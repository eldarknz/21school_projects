/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:30:06 by hkayla            #+#    #+#             */
/*   Updated: 2020/02/28 22:58:33 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct		s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

t_list				*sort_list(t_list* lst, int (*cmp)(int, int));
int					ascending(int a, int b);

#endif
