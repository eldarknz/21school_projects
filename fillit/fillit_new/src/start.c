#include "fillit.h"

int   main(int ac, char **av)
{
  t_figure  *head;
  int       fd;

  if (ac != 2)
    error_handler(0);
  if ((fd = open(av[1], O_RDONLY)) == -1)
    error_handler(-1);
  head = figure_getter(fd);
  close(fd);
	//tmp_print(head);
}
