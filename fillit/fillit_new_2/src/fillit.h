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
# include "../libft/libft.h"

typedef struct	s_figure
{
	int				figurecoord[8];
	char			figuresymbol;
	int				offset_x;
	int				offset_y;
	struct s_figure	*next;
}				t_figure;

typedef struct	s_map
{
	char		**array;
}				t_map;

typedef struct	s_array
{
	char		**array;
}				t_array;

t_figure		*read_data(int fd);
//t_figure		*read_data(char *filename);
int				check(char *buf, int size);
int				character_counter(char *buf);
int				neighbor_counter(char *buf);
t_figure		*make_figure(char *buf, char figuresymbol);
t_figure		*make_list(char *buf, int size);
t_figure		*shift_top_left(t_figure *figure);
void			shift_x(t_figure *figure, int n);
void			shift_y(t_figure *figure, int y);
void			solve(t_figure *figurelist);
int				get_map_size(int num);
size_t			figure_counter(t_figure *figurelist);
int				solve_map(t_map *map, t_figure *figurelist, int map_size);
int				in_bounds(t_figure *figure, int map_size, char axis);
int				overlap(t_map *map, t_figure *figure);
void			place(t_figure *figure, t_map *map, char letter);
t_map			*new_map(int size);
void			print_map(t_map *map, int size);
void			free_list(t_figure *list);
void			free_map(t_map *map, int map_size);

void			error_handler(int er);

#endif
