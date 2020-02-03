/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:31:32 by hkayla            #+#    #+#             */
/*   Updated: 2020/02/03 14:31:34 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		overlap(t_map *map, t_figure *figure)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	x = figure->figurecoord[i] + figure->offset_x;
	y = figure->figurecoord[i + 1] + figure->offset_y;
	while (i <= 6 && map->array[y][x] == '.')
	{
		i += 2;
		x = figure->figurecoord[i] + figure->offset_x;
		y = figure->figurecoord[i + 1] + figure->offset_y;
	}
	return (i != 8);
}

void	place(t_figure *figure, t_map *map, char letter)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (i <= 6)
	{
		x = figure->figurecoord[i] + figure->offset_x;
		y = figure->figurecoord[i + 1] + figure->offset_y;
		map->array[y][x] = letter;
		i += 2;
	}
}

int		in_bounds(t_figure *figure, int map_size, char axis)
{
	if (axis == 'y')
		return (figure->figurecoord[1] + figure->offset_y < map_size &&
				figure->figurecoord[3] + figure->offset_y < map_size &&
				figure->figurecoord[5] + figure->offset_y < map_size &&
				figure->figurecoord[7] + figure->offset_y < map_size);
	else
		return (figure->figurecoord[0] + figure->offset_x < map_size &&
				figure->figurecoord[2] + figure->offset_x < map_size &&
				figure->figurecoord[4] + figure->offset_x < map_size &&
				figure->figurecoord[6] + figure->offset_x < map_size);
}

int		solve_map(t_map *map, t_figure *figure, int map_size)
{
	if (!figure)
		return (1);
	figure->offset_x = 0;
	figure->offset_y = 0;
	while (in_bounds(figure, map_size, 'y'))
	{
		while (in_bounds(figure, map_size, 'x'))
		{
			if (!overlap(map, figure))
			{
				place(figure, map, figure->figuresymbol);
				if (solve_map(map, figure->next, map_size))
					return (1);
				else
				{
					place(figure, map, '.');
				}
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
	while (!solve_map(map, figurelist, map_size))
	{
		free_map(map, map_size);
		map_size++;
		map = new_map(map_size);
	}
	print_map(map, map_size);
	free_map(map, map_size);
}
