/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:29:51 by hkayla            #+#    #+#             */
/*   Updated: 2020/02/07 11:30:07 by hkayla           ###   ########.fr       */
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

t_figure	*create_figure(char *buf, char figuresymbol)
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
			figure->coord_x[j] = (i >= 5) ? (i % 5) : i;
			figure->coord_y[j] = i / 5;
			j++;
		}
		i++;
	}
	figure->offset_x = 0;
	figure->offset_y = 0;
	figure->figuresymbol = figuresymbol;
	return (shift_top_left(figure));
}

t_figure	*create_figure_list(char *buf, int size)
{
	t_figure	*current;
	t_figure	*head;
	int			i;
	char		figuresymbol;

	i = 0;
	figuresymbol = 'A';
	while (i < size)
	{
		if (figuresymbol == 'A')
		{
			head = create_figure(buf + i, figuresymbol);
			current = head;
		}
		else
		{
			current->next = create_figure(buf + i, figuresymbol);
			current = current->next;
		}
		figuresymbol++;
		i += 21;
	}
	current->next = NULL;
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
	if (!check_figure(buf, bytes))
		return (NULL);
	return (create_figure_list(buf, bytes));
}
