#include "libft.h"
#include "lemin.h"
#include <stdlib.h>

void	malloc_rooms(t_maze *maze, char *str, int *i)
{
	int			n;
	size_t		count;

	n = *i;
	count = 0;
	while (str[n])
	{
		while (str[n] && (str[n] == '#' || str[n] == 'L'))
			next_line(str, &n);
		while (str[n] != ' ' && str[n] != '-')
			n++;
		if (str[n] != ' ')
			break ;
		count++;
		next_line(str, &n);
	}
	if (count == 0)
	{
		free(str);
		free(maze);
		throw(0, "Error: non rooms\n", 0);
	}
	if (!(maze->rooms = (t_room*)malloc(sizeof(t_room) * count)))
		throw(0, "Error: can't malloc rooms\n",0);
	maze->rooms_count = count;
}
