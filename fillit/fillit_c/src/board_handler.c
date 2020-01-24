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
    int size;

    board_size = 0;
    num_figures = get_number_figures(head);
    printf("num_figures ==> %d\n", num_figures);
    size = num_figures * 4;
    while (size > (board_size * board_size))
    {
        printf("board_size ==> %d\n", board_size);
        board_size++;
    }
    return (board_size);
}
