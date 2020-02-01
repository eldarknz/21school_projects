/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:55:28 by hkayla            #+#    #+#             */
/*   Updated: 2020/02/01 16:55:31 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		del_figure(t_figure *list)
{
	int i;

	i = 0;
	while (i < list->size)
		free(list->figure[i++]);
	free(list->figure);
	list->figure = NULL;
	list->size = 0;
	list->num = 0;
	list->next = NULL;
}

void			dell_all_figures(t_figure *head)
{
	t_figure *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		del_figure(tmp);
		free(tmp);
	}
}

void		print(t_figure *head)
{
	int i;

	i = 0;
	while (i < head->size)
	{
		ft_putstr(head->figure[i]);
		ft_putstr("\n");
		i++;
	}
}

static int	figfill(char **head, char **fig, int size)
{
	int i;
	int j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (fig[j][i] != '.')
				head[j][i] = fig[j][i];
			i++;
		}
		j++;
	}
	return (0);
}

void		fillit(t_figure *head)
{
	t_figure *tmp;

	tmp = head;
	while (tmp)
	{
		figfill(head->figure, tmp->figure, head->size);
		tmp = tmp->next;
	}
}

t_figure		*go_back(t_figure *head, int num)
{
	while (head->num < (num - 1))
		head = head->next;
	return (head);
}

static int	check_boarder_right(char **f, int size_field)
{
	int	i;
	int	j;

	i = size_field;
	j = 0;
	while (j <= size_field)
	{
		if (f[j][size_field] != '.')
			return (1);
		j++;
	}
	return (0);
}

static int	check_boarder_down(char **f, int size_field)
{
	int	i;
	int	j;

	i = 0;
	j = size_field;
	while (i <= size_field)
	{
		if (f[size_field][i] != '.')
			return (1);
		i++;
	}
	return (0);
}

static void	move_right(char **f, int size_field)
{
	int	i;
	int	j;
	int	triger;

	i = size_field;
	j = size_field;
	triger = 0;
	if (check_boarder_right(f, size_field) == 1)
		triger++;
	while (i > 0 || j > 0)
	{
		if (triger == 1)
			break ;
		if (f[j][i] != '.' && i != size_field)
			swap_char(&f[j][i], &f[j][i + 1]);
		if (i == 0)
		{
			j--;
			i = size_field;
		}
		else
			i--;
	}
	if (triger == 0)
		swap_char(&f[j][i], &f[j][i + 1]);
}

static void	move_down(char **f, int size_field)
{
	int	i;
	int	j;
	int	triger;

	i = size_field;
	j = size_field;
	triger = 0;
	if (check_boarder_down(f, size_field) == 1)
		triger++;
	while (i > 0 || j > 0)
	{
		if (triger == 1)
			break ;
		if (f[j][i] != '.' && j != size_field)
			swap_char(&f[j][i], &f[j + 1][i]);
		if (i == 0)
		{
			j--;
			i = size_field;
		}
		else
			i--;
	}
	if (triger == 0)
		swap_char(&f[j][i], &f[j + 1][i]);
}

int			move_next(t_figure *list)
{
	if (check_boarder_down(list->figure, list->size - 1)
		&& check_boarder_right(list->figure, list->size - 1))
		return (1);
	if (check_boarder_right(list->figure, list->size - 1))
	{
		shift_left(list->figure, list->size);
		move_down(list->figure, list->size - 1);
	}
	else
		move_right(list->figure, list->size - 1);
	return (0);
}

static int	figure_compare(char **head, char **body, int size)
{
	int i;
	int j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (head[j][i] != '.' && body[j][i] != '.')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int			is_overlap(t_figure *head, t_figure *body)
{
	int ret;

	ret = 0;
	while (head->num < body->num)
	{
		//printf("head_num body_num ===> %d %d\n", head->num, body->num);
		if ((ret = figure_compare(head->figure, body->figure, head->size)) == 1)
			break ;
		head = head->next;
	}
	return (ret);
}

void		back_track(t_figure *head)
{
	t_figure	*tmp;

	tmp = head;
	while (tmp)
	{
		printf("head_num tmp_num ===> %d %d\n", head->num, tmp->num);
		while (is_overlap(head, tmp))
			if (move_next(tmp))
			{
				while (move_next(tmp))
				{
					if (tmp == head)
					{
						set_change(head, head->size + 1);
						break ;
					}
					tmp = go_back(head, tmp->num);
				}
				shift_all_figures(tmp->next);
			}
		tmp = tmp->next;
	}
}