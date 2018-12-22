#include "libft.h"
#include "lemin.h"
#include <stdlib.h>

void		set_ants_count(t_maze *maze, char *str, int *i)
{
	while (ft_isdigit(str[*i]))
		(*i)++;
	if (str[*i] != '\n' || *i == 0)
	{
		free(maze);
		free(str);
		throw(0, "Error: not valid ants number\n", 0);
	}
	(*i)++;
	maze->ants_count = ft_atoi(str);
	if (maze->ants_count <= 0)
	{
		free(maze);
		free(str);
		throw(0, "Error: not valid ants number\n", 0);
	}
}
