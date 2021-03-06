/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:30:37 by hkayla            #+#    #+#             */
/*   Updated: 2020/02/03 14:30:41 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_figure
{
	int				coord_x[4];
	int				coord_y[4];
	int				height;
	int				width;
	int				offset_x;
	int				offset_y;
	char			figuresymbol;
	struct s_figure	*next;
}				t_figure;

typedef struct	s_map
{
	char		**array;
}				t_map;

t_figure		*read_data(char *filename);
int				check_figure(char *buf, int size);
int				character_counter(char *buf);
int				neighbor_counter(char *buf, int i);
t_figure		*create_figure(char *buf, int num);
int				get_side_size(int *array);
t_figure		*create_figure_list(char *buf, int size);
t_figure		*shift_top_left(t_figure *figure);
void			shift_axis(t_figure *figure, int n, char axis);
void			solve(t_figure *figurelist);
int				get_map_size(int num);
size_t			figure_counter(t_figure *figurelist);
int				build_map(t_map *map, t_figure *figurelist, int map_size);
int				intersection(t_map *map, t_figure *figure);
void			insert_figure(t_figure *figure, t_map *map, char letter);
t_map			*new_map(int size);
void			print_map(t_map *map, int size);
void			free_list(t_figure *list);
void			free_map(t_map *map, int map_size);

#endif
