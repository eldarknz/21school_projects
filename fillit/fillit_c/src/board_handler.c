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

static int  ft_size(int size)
{
    int board_size;

    board_size = 0;
    size *= 4;
    printf("size ==> %d\n", size);
    while (size > (board_size * board_size))
    {
        printf("board_size ==> %d\n", board_size);
        board_size++;
    }
    return (board_size);
}

int     get_board_size(t_figure *head)
{
    int count;

    count = 0;
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    printf("count ==> %d\n", count);
    return (ft_size(count));
}
