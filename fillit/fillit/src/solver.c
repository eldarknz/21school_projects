/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:31:32 by hkayla            #+#    #+#             */
/*   Updated: 2020/02/09 17:24:20 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	insert_figure(t_figure *figure, t_map *map, char letter)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (i < 4)
	{
		x = figure->coord_x[i] + figure->offset_x;
		y = figure->coord_y[i] + figure->offset_y;
		map->array[y][x] = letter;
		i++;
	}
}

int		intersection(t_map *map, t_figure *figure)
{
	int i;
	int x;
	int y;

	i = 0;
	while (i < 4)
	{
		x = figure->coord_x[i] + figure->offset_x;
		y = figure->coord_y[i] + figure->offset_y;
		if (map->array[y][x] != '.')
			return (1);
		i++;
	}
	return (0);
}

int		build_map(t_map *map, t_figure *figure, int map_size)
{
	if (!figure)
		return (1);
	figure->offset_x = 0;
	figure->offset_y = 0;
	while (figure->offset_y < map_size - figure->height + 1)
	{
		while (figure->offset_x < map_size - figure->width + 1)
		{
			if (!intersection(map, figure))
			{
				insert_figure(figure, map, figure->figuresymbol);
				if (build_map(map, figure->next, map_size))
					return (1);
				else
					insert_figure(figure, map, '.');
			}
			figure->offset_x++;
		}
		figure->offset_x = 0;
		figure->offset_y++;
	}
	return (0);
}

void	solve(t_figure *figurelist)
{
	t_map	*map;
	int		map_size;

	map_size = get_map_size(figure_counter(figurelist) * 4);
	map = new_map(map_size);
	while (!build_map(map, figurelist, map_size))
	{
		free_map(map, map_size);
		map_size++;
		map = new_map(map_size);
	}
	print_map(map, map_size);
	free_map(map, map_size);
}
