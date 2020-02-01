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

	if (ac != 2)
		error_handler(0);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		error_handler(-1);
	head = get_figure(fd);
	close(fd);
	check_figures(head);
	set_change(head, get_board_size(head));
	fill_figure(head);

	//tmp_print(head);

	back_track(head);
	fillit(head);
	print(head);
	dell_all_figures(head);
}
