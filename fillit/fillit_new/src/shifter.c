/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:30:14 by hkayla            #+#    #+#             */
/*   Updated: 2020/02/07 11:30:15 by hkayla           ###   ########.fr       */
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

t_figure	*shift_top_left(t_figure *figure)
{
	while (figure->figurecoord[0] != 0 && \
			figure->figurecoord[2] != 0 && \
			figure->figurecoord[4] != 0 && \
			figure->figurecoord[6] != 0)
		shift_x(figure, -1);
	while (figure->figurecoord[1] != 0 && \
			figure->figurecoord[3] != 0 && \
			figure->figurecoord[5] != 0 && \
			figure->figurecoord[7] != 0)
		shift_y(figure, -1);
	return (figure);
}
