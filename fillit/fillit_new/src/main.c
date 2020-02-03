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

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (1);
	}
	list = read_data(av[1]);
	if (!list)
	{
		ft_putstr("error\n");
		return (1);
	}
	solve(list);
	free_list(list);
	return (0);
}
