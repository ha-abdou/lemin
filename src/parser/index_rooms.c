#include "libft.h"
#include "lemin.h"

/*
maze->maze->rooms[maze->end_index].cons ,
		maze->rooms[maze->end_index].cons_len ,
		1
*/

static void	index_it(int *q_1, int *q_2, int q_len, int value)
{
	//
}

void	index_rooms(t_maze *maze)
{
	int		*q_1;
	int		*q_2;
	int		i;
	t_room	*target;

	if (!(q_1 = (int *)malloc(sizeof(int) * maze->rooms_count)))
		throw(0, "Error: can't malloc q_1\n");
	if (!(q_2 = (int *)malloc(sizeof(int) * maze->rooms_count)))
		throw(0, "Error: can't malloc q_2\n");
	i = 0;
	target = maze->rooms[maze->end_index];
	while (i < target->cons_len)
	{
		q_1[i] = target->cons[i];
		i++;
	}
	index_it(q_1, q_2, i, 1);
	free(q_1);
	free(q_2);
}
