/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:49:42 by hkayla            #+#    #+#             */
/*   Updated: 2020/02/01 16:49:46 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	fill_letters(t_figure *head)
{
	int i;
	int j;

	i = 0;
	while (i < head->size)
	{
		j = 0;
		while (j < head->size)
		{
			if (head->figure[i][j] != '.')
				head->figure[i][j] = head->num + 'A';
			j++;
		}
		i++;
	}
}

void		fill_figure(t_figure *start)
{
	while (start)
	{
		fill_letters(start);
		start = start->next;
	}
}
