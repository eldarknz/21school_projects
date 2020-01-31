/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:34:53 by hkayla            #+#    #+#             */
/*   Updated: 2020/01/24 14:34:56 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int  get_number_figures(t_figure *head)
{
    int count;

    count = 0;
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    return (count);
}

int     get_board_size(t_figure *head)
{
    int board_size;
    int num_figures;
    int num_cells;
    int max_size_figure;

    board_size = 3;
    num_figures = get_number_figures(head);
    max_size_figure = get_max_size_figure(head);
    printf("max_size_figure ==> %d\n", max_size_figure);
    printf("num_figures ==> %d\n", num_figures);
    num_cells = num_figures * 4;
    while (num_cells > (board_size * board_size))
    {
        //printf("board_size ==> %d\n", board_size);
        board_size++;
    }
    return (board_size);
}
