/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:31:32 by hkayla            #+#    #+#             */
/*   Updated: 2020/02/09 14:10:27 by hkayla           ###   ########.fr       */
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
	while (i <= 3)
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
	x = figure->coord_x[i] + figure->offset_x;
	y = figure->coord_y[i] + figure->offset_y;
	while (i <= 3 && map->array[y][x] == '.')
	{
		i++;
		x = figure->coord_x[i] + figure->offset_x;
		y = figure->coord_y[i] + figure->offset_y;
	}
	return (i != 4);
}

/*int		is_inside(t_figure *figure, int map_size, char axis)
{
	if (axis == 'y')
	{
		printf("y ===> %d\n", (figure->coord_y[0] + figure->offset_y < map_size &&
						figure->coord_y[1] + figure->offset_y < map_size &&
						figure->coord_y[2] + figure->offset_y < map_size &&
						figure->coord_y[3] + figure->offset_y < map_size));
		return (figure->coord_y[0] + figure->offset_y < map_size &&
				figure->coord_y[1] + figure->offset_y < map_size &&
				figure->coord_y[2] + figure->offset_y < map_size &&
				figure->coord_y[3] + figure->offset_y < map_size);
	}
	else
	{
		printf("x ===> %d\n", (figure->coord_x[0] + figure->offset_x < map_size &&
						figure->coord_x[1] + figure->offset_x < map_size &&
						figure->coord_x[2] + figure->offset_x < map_size &&
						figure->coord_x[3] + figure->offset_x < map_size));
		return (figure->coord_x[0] + figure->offset_x < map_size &&
				figure->coord_x[1] + figure->offset_x < map_size &&
				figure->coord_x[2] + figure->offset_x < map_size &&
				figure->coord_x[3] + figure->offset_x < map_size);
	}
}*/

int		is_inside(t_figure *figure, int map_size, char axis)
{
	int	i;

	i = 0;
	if (axis == 'y')
		while (i < 4 && figure->coord_y[i] + figure->offset_y < map_size)
			i++;
	else
		while (i < 4 && figure->coord_x[i] + figure->offset_x < map_size)
			i++;
	if (i != 3)
	{
		printf("%c ===> 1\n", axis);
		return (1);
	}
	else
	{
		printf("%c ===> 0\n", axis);
		return (0);
	}
}

int		build_map(t_map *map, t_figure *figure, int map_size)
{
	if (!figure)
		return (1);
	figure->offset_x = 0;
	figure->offset_y = 0;
	while (is_inside(figure, map_size, 'y'))
	{
		while (is_inside(figure, map_size, 'x'))
		{
			if (!intersection(map, figure))
			{
				printf("-------\n");
				printf("%d\n", figure->offset_x);
				printf("%d\n", figure->offset_y);
				printf("-------\n");
				insert_figure(figure, map, figure->figuresymbol);
				if (build_map(map, figure->next, map_size))
					return (1);
				else
				{
					//printf("1\n");
					//printf("%c\n", figure->figuresymbol);
					//print_map(map, map_size);
					//printf("1\n");
					insert_figure(figure, map, '.');
					//printf("2\n");
					//printf("%c\n", figure->figuresymbol);
					//print_map(map, map_size);
					//printf("2\n");
				}
			}
			printf("3\n");
			printf("%c\n", figure->figuresymbol);
			printf("%d\n", figure->offset_x);
			print_map(map, map_size);
			printf("3\n");
			figure->offset_x++;
		}
		//printf("4\n");
		//printf("%c\n", figure->figuresymbol);
		//print_map(map, map_size);
		//printf("4\n");
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
