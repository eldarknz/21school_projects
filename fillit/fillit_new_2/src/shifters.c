/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:31:23 by hkayla            #+#    #+#             */
/*   Updated: 2020/02/03 14:31:25 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	shift_x(t_figure *figure, int n)
{
	figure->figurecoord[0] += n;
	figure->figurecoord[2] += n;
	figure->figurecoord[4] += n;
	figure->figurecoord[6] += n;
}

void	shift_y(t_figure *figure, int n)
{
	figure->figurecoord[1] += n;
	figure->figurecoord[3] += n;
	figure->figurecoord[5] += n;
	figure->figurecoord[7] += n;
}
