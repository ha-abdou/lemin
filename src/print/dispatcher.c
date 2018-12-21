#include "libft.h"
#include "lemin.h"

static void	dispatsh(t_maze *maze, t_path *paths)
{
	size_t		i;

	i = 1;
	while (i < maze->paths_count)
	{
		paths[i].start_ant = paths[i - 1].start_ant + paths[i - 1].buff;
		i++;
	}
}

void		dispatsh_ants(t_maze *maze, t_path *paths)
{
	size_t		i;
	size_t		ants;

	ants = maze->ants_count;
	while (ants)
	{
		i = 0;
		while (i < maze->paths_count)
		{
			if (i + 1 >= maze->paths_count ||\
			(paths[i].len + paths[i].buff) <\
			(paths[i + 1].len + paths[i + 1].buff))
			{
				paths[i].buff++;
				break ;
			}
			i++;
		}
		ants--;
	}
	dispatsh(maze, paths);
}
