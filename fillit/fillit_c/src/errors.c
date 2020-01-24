/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:25:10 by hkayla            #+#    #+#             */
/*   Updated: 2020/01/22 14:43:47 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(int er)
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
