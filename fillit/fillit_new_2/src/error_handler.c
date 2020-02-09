/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:45:23 by hkayla            #+#    #+#             */
/*   Updated: 2020/01/24 15:46:05 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error_handler(int er)
{
	if (er == 0)
		ft_putstr("usage: fillit source_file\n");
	else if (er == -1)
		ft_putstr("file not found!\n");
	else if (er == 1)
		ft_putstr("error\n");
	else if (er == 2)
		ft_putstr("too many tetriminos\n");
	exit(1);
}
