/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 18:59:53 by hkayla            #+#    #+#             */
/*   Updated: 2020/02/01 19:01:18 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

void	tmp_print(t_figure *head)
{
	t_figure	*tmp;
	int			i;

	tmp = head;
	i = 0;
	while (tmp)
	{
		while (i < 4)
		{
			printf("figure ==> %s\n", tmp->figure[i]);
			i++;
		}
		tmp = tmp->next;
		i = 0;
		printf("\n");
	}
}
