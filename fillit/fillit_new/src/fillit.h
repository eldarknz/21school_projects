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

typedef struct		s_figure
{
	int							size;
	int							num;
	char						**figure;
	struct s_figure	*next;
}									t_figure;

typedef struct		s_map
{
	char						**array;
}									t_map;

void							error_handler(int er);
t_figure					*figure_getter(int fd);

void        			shift_top(t_figure *fig);
void 							figure_validation(char **figure);
void 							figure_checker(char **figure);
void							fill_letters(t_figure *head);

void							tmp_print(t_figure *head);

#endif
