/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:29:51 by hkayla            #+#    #+#             */
/*   Updated: 2020/02/10 15:28:17 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_list(t_figure *list)
{
	t_figure *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

t_figure	*create_figure(char *buf, int num)
{
	t_figure	*figure;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(figure = (t_figure*)malloc(sizeof(t_figure))))
		return (NULL);
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			figure->coord_x[j] = i % 5;
			figure->coord_y[j] = i / 5;
			j++;
		}
		i++;
	}
	figure->offset_x = 0;
	figure->offset_y = 0;
	figure->figuresymbol = 'A' + (num / 21);
	figure->next = NULL;
	return (shift_top_left(figure));
}

t_figure	*create_figure_list(char *buf, int size)
{
	t_figure	*head;
	t_figure	*current;
	int			i;

	i = 0;
	while (i <= size)
	{
		if (!check_figure(buf + i))
			return (NULL);
		else
		{
			if (i == 0)
			{
				head = create_figure(buf + i, i);
				current = head;
			}
			else
			{
				current->next = create_figure(buf + i, i);
				current = current->next;
			}
			i += 21;
		}
	}
	return (head);
}

t_figure	*read_data(char *filename)
{
	char	buf[545];
	int		fd;
	int		bytes;

	fd = open(filename, O_RDONLY);
	bytes = read(fd, buf, 545);
	close(fd);
	if (bytes > 544 || bytes < 19)
		return (NULL);
	buf[bytes] = '\0';
	return (create_figure_list(buf, bytes));
}
