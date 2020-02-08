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
  int index;

  i = 0;
  index = -1;
  while (i < 4)
  {
    j = 0;
    while (j < 4)
    {
      if (fig[i][j] != '.' && j > index)
        index = j;
      j++;
    }
    i++;
  }
  return (index);
}

static int  get_left(char **fig)
{
  int i;
  int j;
  int index;

  i = 0;
  index = 4;
  while (i < 4)
  {
    j = 0;
    while (j < 4)
    {
      if (fig[i][j] != '.' && j < index)
        index = j;
      j++;
    }
    i++;
  }
  return (index);
}

static int  get_top(char **fig)
{
  int i;
  int j;
  int index;

  j = 0;
  index = 4;
  while (j < 4)
  {
    i = 0;
    while (i < 4)
    {
      if (fig[j][i] != '.' && j < index)
      {
        index = j;
      }
      i++;
    }
    j++;
  }
  return (index);
}

static int  get_bottom(char **fig)
{
  int i;
  int j;
  int index;

  j = 0;
  index = -1;
  while (j < 4)
  {
    i = 0;
    while (i < 4)
    {
      if (fig[j][i] != '.' && j > index)
        index = j;
      i++;
    }
    j++;
  }
  return (index);
}

int         get_max_size_figure(t_figure *head)
{
    int width;
    int height;
    int cur_max_size;
    int next_max_size;

    cur_max_size = 0;
    while(head)
    {
      width = (get_right(head->figure) + 1) - get_left(head->figure);
      height = (get_bottom(head->figure) + 1) - get_top(head->figure);
      next_max_size = (width > height) ? width : height;
      if (next_max_size > cur_max_size)
          cur_max_size = next_max_size;
      head = head->next;
    }
	return (cur_max_size);
}
