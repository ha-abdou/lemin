#include "libft.h"
#include "lemin.h"
#include <stdlib.h>

void	free_mem(t_maze *maze, char *str)
{
	size_t	i;

	i = 0;
	while (i < maze->rooms_count)
	{
		free(maze->rooms[i].cons);
		i++;
	}
	free(maze->rooms);
	free(maze);
	maze = 0;
	free(str);
	str = 0;
}
