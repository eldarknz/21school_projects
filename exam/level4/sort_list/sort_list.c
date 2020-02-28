/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 22:39:48 by hkayla            #+#    #+#             */
/*   Updated: 2020/02/28 22:57:47 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		ascending(int a, int b)
{
	return (a <= b);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;

}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *head;
	t_list *next;

	head = lst;
	while (lst)
	{
		next = lst->next;
		while (next)
		{
			if (!(*cmp)(lst->data, next->data))
				ft_swap(&lst->data, &next->data);
			next = next->next;
		}
		lst = lst->next;
	}
	return (head);
}
