/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:57:13 by hkayla            #+#    #+#             */
/*   Updated: 2020/02/03 17:57:17 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*void		free_list(t_figure *list)
{
	t_figure *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}*/

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

t_figure	*make_figure(char *buf, char figuresymbol)
{
	t_figure	*figure_ptr;
	int			x;
	int			y;
	int			i;

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

/*t_figure	*make_list(char *buf, int size)
{
	t_figure	*current;
	t_figure	*head;
	int			i;
	char		figuresymbol;

	i = 0;
	figuresymbol = 'A';
	while (i < size)
	{
		if (figuresymbol == 'A')
		{
			head = make_figure(buf + i, figuresymbol);
			current = head;
		}
		else
		{
			current->next = make_figure(buf + i, figuresymbol);
			current = current->next;
		}
		figuresymbol++;
		i += 21;
	}
	current->next = NULL;
	return (head);
}

t_figure	*read_data(char *filename)
{
	char	buf[545];
	int		fd;
	int		bytes;

	fd = open(filename, O_RDONLY);
	bytes = read(fd, buf, 545);
	close(fd);
	if (bytes > 544 || bytes < 19)
		return (NULL);
	buf[bytes] = '\0';
	if (!check(buf, bytes))
		return (NULL);
	return (make_list(buf, bytes));
}*/

static void	free_array(t_array *array, int array_size)
{
	int i;

	i = 0;
	while (i < array_size)
	{
		ft_memdel((void **)&(array->array[i]));
		i++;
	}
	ft_memdel((void **)&(array->array));
	ft_memdel((void **)&array);
}

static void	print_array(t_array *array, int array_size)
{
	int i;

	i = 0;
	while (i < array_size)
	{
		ft_putstr(array->array[i]);
		ft_putchar('\n');
		i++;
	}
}

static t_array	*new_array(int array_size)
{
	t_array	*array;
	int			i;

	array = (t_array *)ft_memalloc(sizeof(t_array));
	array->array = (char**)ft_memalloc(sizeof(char*) * array_size);
	i = 0;
	while (i < array_size)
	{
		array->array[i] = ft_strnew(array_size);
		i++;
	}
	return (array);
}

static int		check_row(t_array *array, char **row, int num, int key)
{
	int len;

	len = ft_strlen(*row);
	if (len != key)
		error_handler(1);
	if (key == 0)
	{
		if (num > 25)
			error_handler(2);
		print_array(array, 4);
	}
	ft_strdel(row);
	return (0);
}

t_figure	*read_data(int fd)
{
	char			*row;
	t_array		*array;
	int				index;
	int				num;

	array = new_array(4);
	index = 0;
	num = 0;
	while ((get_next_line(fd, &row)))
	{
		if (index == 4)
		{
			index = check_row(array, &row, num++, 0);
			free_array(array, 4);
			array = new_array(4);
			continue ;
		}
		ft_strcpy(array->array[index++], row);
		check_row(array, &row, num, 4);
	}
	free_array(array, 4);
	free(row);
	return (NULL);
}
