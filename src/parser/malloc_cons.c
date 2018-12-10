#include "libft.h"
#include "lemin.h"
#include <stdlib.h>

void	malloc_cons(t_maze *maze)
{
	size_t		i;
	size_t		n;

	i = maze->rooms_count;
	while (i != 0)
	{
		i--;
		if (maze->rooms[i].cons_len)
		{
			if (!(maze->rooms[i].cons = (size_t*)malloc(sizeof(size_t) * maze->rooms[i].cons_len)))
				throw(0, "Error: cant malloc connections\n", 0);
			n = maze->rooms[i].cons_len;
			while (n != 0)
			{
				n--;
				maze->rooms[i].cons[n] = 0;
			}
		}
	}
}
