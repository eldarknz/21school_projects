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
int				get_board_size(t_figure *head);

#endif
