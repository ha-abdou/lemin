#include "libft.h"
#include "lemin.h"

int		main(void)
{
	char	*str;
	t_maze	*maze;

	str = read_maze();
	maze = parse(str);
	ft_putchar('\n');

/*	index_rooms(maze);
	solve_maze(&maze);
	free_mem(str, maze);*/
	return (0);
}
