#include "libft.h"
#include "lemin.h"

void	get_cons(t_maze *maze, char *str, int *i)
{
	if (str[*i] == '\n' || str[*i] == '\0')
		throw (0 , "Error: non connections\n", 0);
	count_cons(maze, str, *i);
	malloc_cons(maze);
	make_cons(maze, str, *i);
}
