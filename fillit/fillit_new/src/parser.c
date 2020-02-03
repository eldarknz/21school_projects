/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:31:12 by hkayla            #+#    #+#             */
/*   Updated: 2020/02/03 14:31:16 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_list(t_figure *list)
{
	t_figure *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

t_figure		*shift_top_left(t_figure *figure)
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

t_figure		*makefigure(char *buf, char figuresymbol)
{
	t_figure	*figure_ptr;
	int		x;
	int		y;
	int		i;

	i = 0;
	x = 0;
	y = 1;
	if (!(figure_ptr = (t_figure*)malloc(sizeof(t_figure))))
		return (NULL);
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			figure_ptr->figurecoord[x] = (i >= 5) ? (i % 5) : i;
			figure_ptr->figurecoord[y] = i / 5;
			x += 2;
			y += 2;
		}
		i++;
	}
	figure_ptr->offset_x = 0;
	figure_ptr->offset_y = 0;
	figure_ptr->figuresymbol = figuresymbol;
	return (shift_top_left(figure_ptr));
}

t_figure		*makelist(char *buf, int size)
{
	t_figure *current;
	t_figure *beginning;
	int		i;
	char	figuresymbol;

	i = 0;
	figuresymbol = 'A';
	while (i < size)
	{
		if (figuresymbol == 'A')
		{
			beginning = makefigure(buf + i, figuresymbol);
			current = beginning;
		}
		else
		{
			current->next = makefigure(buf + i, figuresymbol);
			current = current->next;
		}
		figuresymbol++;
		i += 21;
	}
	current->next = NULL;
	return (beginning);
}

t_figure		*parser(char *filename)
{
	char	buf[545];
	int		fd;
	int		bytecount;

	fd = open(filename, O_RDONLY);
	bytecount = read(fd, buf, 545);
	close(fd);
	if (bytecount > 544 || bytecount < 19)
		return (NULL);
	buf[bytecount] = '\0';
	if (!valid(buf, bytecount))
		return (NULL);
	return (makelist(buf, bytecount));
}
