#include "libft.h"
#include "lemin.h"
#include <stdlib.h>

void	create_solver_q(t_maze *maze, t_q *q, t_q *q_2)
{
	size_t	i;
	t_room	target;

	if (!(q->indexs = (size_t *)malloc(sizeof(size_t) *\
		maze->rooms[maze->start_index].cons_len)))
		throw(0, "Error: can't malloc q_1\n", 0);
	if (!(q_2->indexs = (size_t *)malloc(sizeof(size_t) *\
		maze->rooms[maze->start_index].cons_len)))
		throw(0, "Error: can't malloc q_2\n", 0);
	q->len = 0;
	q->value = 1;
	i = 0;
	target = maze->rooms[maze->start_index];
	while (i < target.cons_len)
	{
		if (maze->rooms[target.cons[i]].distence != 0)
		{
			if (maze->rooms[target.cons[i]].distence > q->value)
				q->value = maze->rooms[target.cons[i]].distence;
			maze->rooms[target.cons[i]].previous = maze->start_index;
			q->indexs[q->len] = target.cons[i];
			q->len++;
		}
		i++;
	}
}

void	free_solver_q(t_q *q, t_q *q_2)
{
	free(q->indexs);
	free(q_2->indexs);
}
