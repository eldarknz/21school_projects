/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:09:19 by hkayla            #+#    #+#             */
/*   Updated: 2020/01/22 14:51:42 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef struct	s_figure
{
	int				size;
	int				num;
	char			**figure;
	struct s_figure	*next;
}				t_figure;

t_figure		*get_figure(int fd);
void			error_handler(int er);
void			check_figures(t_figure *head);
void			set_change(t_figure *head, int size);
void			shift_all_figures(t_figure *head);
void			shift_top(t_figure *fig);
void			shift_left(char **fig, int size);
void        	swap_char(char *c1, char *c2);
void			fill_figure(t_figure *start);
int				get_board_size(t_figure *head);
int				get_max_size_figure(t_figure *head);

void			back_track(t_figure *head);
int				is_overlap(t_figure *head, t_figure *body);
int				move_next(t_figure *list);
t_figure		*go_back(t_figure *head, int num);
int				check_figure_size(t_figure *head);
void			fillit(t_figure *head);
void			print(t_figure *head);
void			dell_all_figures(t_figure *head);



void			tmp_print(t_figure *head);

#endif
