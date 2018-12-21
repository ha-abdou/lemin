#include "libft.h"
#include "lemin.h"
#include <stdlib.h>

static void		sort_paths(t_maze *maze, t_path *paths)
{
	size_t	i;
	size_t	j;
	t_path	tmp;

	i = 0;
	while (i < maze->paths_count)
	{
		j = i +1;
		while (j < maze->paths_count)
		{
			if (paths[i].len > paths[j].len)
			{
				tmp = paths[i];
				paths[i] = paths[j];
				paths[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int		go_deep(t_maze *maze, size_t index)
{
	int		len;

	len = 0;
	while (index != maze->end_index)
	{
		if (maze->rooms[index].next == -1)
			return (-1);
		index = (size_t)maze->rooms[index].next;
		len++;
	}
	return (len + 1);
}

t_path		*get_paths(t_maze *maze)
{
	t_path	*paths;
	size_t	i;
	size_t	j;
	int		len;

	i = maze->rooms[maze->start_index].cons_len;
	if (!(paths = (t_path*)malloc(sizeof(t_path) * i)))
		throw(0, "Error: cant malloc paths\n", 0);
	i = 0;
	j = 0;
	while (i < maze->rooms[maze->start_index].cons_len)
	{
		if ((len = go_deep(maze, maze->rooms[maze->start_index].cons[i])) > 0)
		{
			paths[j].start_index = maze->rooms[maze->start_index].cons[i];
			paths[j].len = len;
			paths[j].buff = 0;
			paths[j].start_ant = 1;
			j++;
		}
		i++;
	}
	maze->paths_count = j;
	sort_paths(maze, paths);
	return (paths);
}