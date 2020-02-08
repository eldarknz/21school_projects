/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:47:09 by hkayla            #+#    #+#             */
/*   Updated: 2020/01/24 15:47:19 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		dot_filler(char *str, int size)
{
	int i;

	i = 0;
	while (i < size)
		str[i++] = '.';
	str[size] = '\0';
}

static char		*ft_linecpy(char *dst, char *src, int size)
{
	int i;

	i = 0;
	dot_filler(dst, size);
	while (src[i] && i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

static void		figure_clear(t_figure *list)
{
	int i;

	i = 0;
	while (i < list->size)
	{
		ft_strdel(&(list->figure[i]));
		i++;
	}
	free(list->figure);
}

static void		refresh_figure(t_figure *list, int size)
{
	int		i;
	char	**new;

	new = (char**)malloc(sizeof(char*) * size);
	i = 0;
	while (i < size)
		new[i++] = ft_strnew(size);
	i = 0;
	while (i < size && i < list->size)
	{
		ft_linecpy(new[i], list->figure[i], size);
		i++;
	}
	while (i < size)
		dot_filler(new[i++], size);
	figure_clear(list);
	list->size = size;
	list->figure = new;
}

int			check_figure_size(t_figure *head)
{
	int j;
	int i;

	while (head)
	{
		j = 3;
		i = 0;
		while (i < 4)
			if (head->figure[j][i++] == '#')
				return (4);
		j = 0;
		i = 3;
		while (j < 4)
			if (head->figure[j++][i] == '#')
				return (4);
		head = head->next;
	}
	return (3);
}

void        set_change(t_figure *head, int size)
{
    shift_all_figures(head);
	if (size == 3)
		size = check_figure_size(head);
    while (head)
    {
		refresh_figure(head, size);
		head = head->next;
    }
}
