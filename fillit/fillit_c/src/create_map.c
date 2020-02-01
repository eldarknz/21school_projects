/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 20:03:02 by hkayla            #+#    #+#             */
/*   Updated: 2020/02/01 20:03:16 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map    *new_map(int size)
{
	t_map	*new_map;
	int		i;

	if (!(new_map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	new->size = size;
	new->fill = (char**)malloc(sizeof(char*) * size);
	i = 0;
	while (i < size)
	{
		new->fill[i] = ft_strnew(size);
		i++;
	}
	return (new);
}

void    create_map(int size)
{
	t_map	*new_map;

    new_map = new_map(size)
}