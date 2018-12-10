#include "libft.h"
#include "lemin.h"

int		get_room_index(t_maze *maze, char *name, size_t len)
{
	int		i;

	i = maze->rooms_count;
	while (i != 0)
	{
		i--;
		if (maze->rooms[i].name_len == len)
		{
			if (!ft_strncmp(maze->rooms[i].name, name, len))
				return (i);
		}
	}
	return (-1);
}
