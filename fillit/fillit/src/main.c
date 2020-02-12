/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:30:48 by hkayla            #+#    #+#             */
/*   Updated: 2020/02/09 17:23:54 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_figure	*list;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit source_file");
		return (1);
	}
	list = read_data(av[1]);
	if (!list)
	{
		ft_putendl("error");
		return (1);
	}
	solve(list);
	free_list(list);
	list = NULL;
	return (0);
}
