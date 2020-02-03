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

int				in_bounds(t_figure *figure, int map_size, char axis);
int				overlap(t_map *map, t_figure *figure);
int				solve_map(t_map *map, t_figure *figurelist, int map_size);
void			place(t_figure *figure, t_map *map, char letter);
size_t			count_figures(t_figure *figurelist);
void			print_map(t_map *map, int size);
int				get_map_size(int num);
t_map			*new_map(int size);
void			solve(t_figure *figurelist);
t_figure		*parser(char *filename);
t_figure		*makefigure(char *buf, char figuresymbol);
t_figure		*makelist(char *buf, int size);
t_figure		*shift_top_left(t_figure *figure);
void			shift_x(t_figure *figure, int n);
void			shift_y(t_figure *figure, int y);
int				valid(char *buf, int size);
int				charcount(char *buf);
int				adjacency_counter(char *buf);
void			free_list(t_figure *list);
void			free_map(t_map *map, int map_size);

#endif
