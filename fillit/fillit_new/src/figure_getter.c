/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_getter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:49:43 by hkayla            #+#    #+#             */
/*   Updated: 2020/01/24 15:49:45 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_figure	*figure_maker(int size)
{
	t_figure	*new;
	int			i;

	if (!(new = (t_figure*)malloc(sizeof(t_figure))))
		return (NULL);
	new->next = NULL;
	new->size = size;
	new->figure = (char**)malloc(sizeof(char*) * size);
	i = 0;
	while (i < size)
	{
		new->figure[i] = ft_strnew(size);
		i++;
	}
	return (new);
}

static int			check_row(t_figure *tmp, char **row, int num, int key)
{
	int len;

	len = ft_strlen(*row);
	if (len != key)
		error_handler(1);
	if (key == 0)
	{
		if (num > 24)
			error_handler(2);
		tmp->num = num;
		tmp->size = 4;
		tmp->next = figure_maker(4);
	}
	ft_strdel(row);
	return (0);
}

t_figure				*figure_getter(int fd)
{
	t_figure	*figure;
	t_figure	*tmp;
	char			*row;
	int				index;
	int				num;
	int       i;

	figure = figure_maker(4);
	tmp = figure;
	index = 0;
	num = 0;
	//i = 0;
	while ((get_next_line(fd, &row)))
	{
		if (index == 4)
		{
			i = 0;
			index = check_row(tmp, &row, num++, 0);
			//figure_validation(tmp->figure);
			//figure_checker(tmp->figure);
			//shift_top(tmp);
			//fill_letters(tmp);
			while (i < 4)
			{
				printf("figure ==> %s\n", tmp->figure[i]);
				i++;
			}
			printf("\n----------------\n");
			tmp = tmp->next;
			continue;
		}
		ft_strcpy(tmp->figure[index++], row);
		check_row(tmp, &row, num, 4);
	}
	free(row);
	//tmp->num = num;
	return (figure);
}
