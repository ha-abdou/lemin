#include "libft.h"
#include "lemin.h"
/*
static void	print(t_maze *maze, t_path *paths)
{
	size_t	i;

	while (ants)
	{

	}
}
*/
void		print_solution(t_maze *maze)
{
	t_path	*paths;

	paths = get_paths(maze);
	dispatsh_ants(maze, paths);
	debug_paths(maze, paths);
}
