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

void	shift_axis(t_figure *figure, int n, char axis)
{
	int	i;

	i = (axis == 'x') ? 0 : 1;
	while (i < 8)
	{
		figure->figurecoord[i] += n;
		i += 2;
	}
}

t_figure	*shift_top_left(t_figure *figure)
{
	while (figure->figurecoord[0] != 0 && \
			figure->figurecoord[2] != 0 && \
			figure->figurecoord[4] != 0 && \
			figure->figurecoord[6] != 0)
		shift_axis(figure, -1, 'x');
	while (figure->figurecoord[1] != 0 && \
			figure->figurecoord[3] != 0 && \
			figure->figurecoord[5] != 0 && \
			figure->figurecoord[7] != 0)
		shift_axis(figure, -1, 'y');
	return (figure);
}
