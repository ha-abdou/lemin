#include "libft.h"
#include "lemin.h"

t_maze	*parse(char *str)
{
	int		i;
	t_maze	*maze;

	if (!(maze = ((t_maze*)malloc(sizeof(t_maze)))))
		throw(0, 0, "Error: cant malloc\n");
	i = 0;
	maze->rooms = 0;
	maze->start_index = 0;
	maze->end_index = 0;
	maze->ants_count = get_ants_count(str, &i);
	get_rooms(maze, str, &i);
	get_cons(maze, str, &i);
	return (maze);
}
