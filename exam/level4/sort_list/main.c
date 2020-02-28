/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:33:24 by hkayla            #+#    #+#             */
/*   Updated: 2020/02/28 22:57:37 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void	ft_print(t_list *list)
{
	while (list)
	{
		printf("%d", list->data);
		if (list->next != NULL)
			printf(" ");
		list = list->next;
	}
	printf("\n");
}

t_list	*create_item(int a)
{
	t_list	*item;

	if (!(item = (t_list*)malloc(sizeof(t_list))))
		return NULL;
	item->data = a;
	item->next = NULL;
	return (item);
}

t_list	*create_list(int *arr)
{
	int		i;
	t_list	*head;
	t_list	*current;

	i = 0;
	while(arr[i] != -1)
	{
		if (i == 0)
		{
			head = create_item(arr[i]);
			current = head;
		}
		else
		{
			current->next = create_item(arr[i]);
			current = current->next;
		}
		i++;
	}
	return (head);
}

int		main(void)
{
	t_list	*list;
	int		arr[12] = {4, 1, 8, 2, 6, 9, 7, 0, 3, 5, -1};

	list = create_list(arr);
	ft_print(list);

	sort_list(list, &ascending);

	ft_print(list);
	free_list(list);
	list = NULL;
	return (0);
}
