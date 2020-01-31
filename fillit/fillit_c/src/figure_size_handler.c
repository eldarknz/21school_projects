/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_size_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 13:07:25 by hkayla            #+#    #+#             */
/*   Updated: 2020/01/31 13:07:41 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int  get_right(char **fig)
{
    int i;
    int j;
    int left;
    int is_left;

    i = 0;
    left = 0;
    is_left = 0;
	while (i < 4 && !is_left)
    {
        j = 3;
        while (j >= 0 && !is_left)
        {
            printf("%c", fig[i][j]);
            if (fig[i][j] != '.')
            {
                left = j;
                is_left = 1;
                printf("\ni, j ===> %d %d", i, j);
            }
            j--;
        }
        printf("\n----------------\n");
        i++;
    }
    return (left);
}

static int  get_left(char **fig)
{
    int i;
    int j;
    int left;
    int is_left;

    j = 0;
    left = 0;
    is_left = 0;
	while (j < 4 && !is_left)
    {
        i = 0;
        while (i < 4 && !is_left)
        {
            printf("%c", fig[j][i]);
            if (fig[j][i] != '.')
            {
                left = j;
                is_left = 1;
                printf("\ni, j ===> %d %d", i, j);
            }
            i++;
        }
        printf("\n----------------\n");
        j++;
    }
    return (left);
}

static int  get_max_size(t_figure *fig)
{
    int width;
    int left;
    int right;

    width = 0;
    left = get_left(fig->figure);
    printf("\n-------------------------------------\n");
    right = get_right(fig->figure);

    printf("left ==> %d\n", left);
    printf("right ==> %d\n", right);
    return (width);
}

int         get_max_size_figure(t_figure *head)
{
	int cur_max_size;
    int next_max_size;

    cur_max_size = 0;
    while(head)
    {
        next_max_size = get_max_size(head);
        if (next_max_size > cur_max_size)
            cur_max_size = next_max_size;
		head = head->next; 
    }
	return (cur_max_size);
}