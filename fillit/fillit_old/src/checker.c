/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:48:31 by hkayla            #+#    #+#             */
/*   Updated: 2020/01/24 15:48:35 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int  check_neighbors(char **figure, int row, int c)
{
    int bond;

    bond = 0;
    if ((c + 1) < 4)
        if (figure[row][c + 1] == '#')
            bond++;
    if ((row + 1) < 4)
        if (figure[row + 1][c] == '#')
            bond++;
    if ((row - 1) >= 0)
        if (figure[row - 1][c] == '#')
            bond++;
    if ((c - 1) >= 0)
        if (figure[row][c - 1] == '#')
            bond++;
    return (bond);
}

static void figure_checker(char **figure)
{
    int row;
    int c;
    int bond;

    row = 0;
    bond = 0;
    while (row < 4)
    {
        c = 0;
        while (c < 4)
        {
            if (figure[row][c] == '#')
                bond += check_neighbors(figure, row, c);
            c++;
        }
        row++;
    }
    //printf("bond ==> %d\n", bond);
	if (bond != 8 && bond != 6)
		error_handler(1);
}

static void figure_validation(char **figure)
{
    int row;
    int c;
    int count;

    row = 0;
    count = 0;
    while (row < 4)
    {
        c = 0;
        while (c < 4)
        {
            if (figure[row][c] == '#')
                count++;
            if (figure[row][c] != '.' && figure[row][c] != '#')
                error_handler(1);
            c++;
        }
        row++;
    }
    //printf("count ==> %d\n", count);
    if (count != 4)
        error_handler(1);
}

void    check_figures(t_figure *head)
{
    while (head)
    {
        figure_validation(head->figure);
        figure_checker(head->figure);
        head = head->next;
    }
}
