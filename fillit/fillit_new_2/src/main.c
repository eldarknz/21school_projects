/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:30:48 by hkayla            #+#    #+#             */
/*   Updated: 2020/02/03 14:30:52 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_figure	*list;
	int			fd;

	if (ac != 2)
		error_handler(0);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		error_handler(-1);
	list = read_data(fd);
	//if (!list)
	//{
	//	ft_putendl("error");
	//	return (1);
	//}
	//solve(list);
	//free_list(list);
	//list = NULL;
	return (0);
}
