/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_figure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:24:42 by hkayla            #+#    #+#             */
/*   Updated: 2020/01/22 14:24:50 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static t_figure	*new_figure(int size)
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

static int		check_row(t_figure *tmp, char **row, int num, int key)
{
	int len;
	len = ft_strlen(*row);
	if (len != key)
		ft_error(1);
	if (key == 0)
	{
		if (num > 24)
			ft_error(2);
		tmp->num = num;
		tmp->size = 4;
		tmp->next = new_figure(4);
	}
	ft_strdel(row);
	return (0);
}

t_figure		*get_figure(int fd)
{
	t_figure	*start;
	t_figure	*tmp;
	char		*row;
	int			index;
	int			num;

	start = new_figure(4);
	tmp = start;
	index = 0;
	num = 0;
	while ((get_next_line(fd, &row)))
	{
        //printf("index ==> %d, num ==> %d\n", index, num);
		if (index == 4)
		{
			index = check_row(tmp, &row, num++, 0);
            //printf("If index == 4: index ==> %d, num ==> %d\n", index, num);
			tmp = tmp->next;
			continue ;
		}
		ft_strcpy(tmp->figure[index++], row);
		check_row(tmp, &row, num, 4);
	}
	free(row);
	tmp->num = num;
	return (start);
}
