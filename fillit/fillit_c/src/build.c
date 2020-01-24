/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:19:57 by hkayla            #+#    #+#             */
/*   Updated: 2020/01/22 14:44:35 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_figure	*head;
	int			fd;
	//t_figure	*tmp;
	//int			i;

	if (ac != 2)
		ft_error(0);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_error(-1);
	head = get_figure(fd);
	close(fd);
	check_figures(head);
	printf("board_size ==> %d\n", get_board_size(head));
	//tmp = head;
	//i = 0;
	/*while (tmp)
	{
		while (i < 4)
		{
			printf("figure ==> %s\n", tmp->figure[i]);
			i++;
		}
		tmp = tmp->next;
		i = 0;
		printf("\n");
	}*/
}
