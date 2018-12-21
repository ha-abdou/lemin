#include "libft.h"
#include "lemin.h"
#include <stdlib.h>

static void	setup_next_q(t_maze *maze, t_q *q, t_q *q_2)
{
	size_t		i;

	i = 0;
	q_2->value = q->value - 1;
	while (i < q_2->len)
	{
		if (q_2->value < maze->rooms[q_2->indexs[i]].distence)
			q_2->value = maze->rooms[q_2->indexs[i]].distence;
		i++;
	}
	if (q_2->len != 0 && q_2->value != 0)
	{
		sort_solver_q(maze, q);
		solve(maze, q_2, q);
	}
}

void	solve(t_maze *maze, t_q *q, t_q *q_2)
{
	size_t		i;

	i = 0;
	q_2->len = 0;
	while (i < q->len)
	{
		if (q->indexs[i] != maze->end_index)
		{
			if (maze->rooms[q->indexs[i]].distence == q->value)
				set_best_next(maze, q->indexs[i], q_2);
			else
			{
				q_2->indexs[q_2->len] = q->indexs[i];
				q_2->len++;
			}
			i++;
		}
	}
	setup_next_q(maze, q, q_2);
}

void	solve_maze(t_maze *maze)
{
	t_q		q;
	t_q		q_2;

	create_solver_q(maze, &q, &q_2);
	if (q.len == 0)
	{
		free_solver_q(&q, &q_2);
//		free_mem(str, maze);
		throw(0, "Error: non posible path found!\n", 0);
	}
	sort_solver_q(maze, &q);
	solve(maze, &q, &q_2);
	free_solver_q(&q, &q_2);
}