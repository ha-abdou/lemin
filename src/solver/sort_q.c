#include "libft.h"
#include "lemin.h"

void	sort_solver_q(t_maze *maze, t_q *q)
{
	size_t		i;
	size_t		j;
	size_t		tmp;

	i = 0;
	while (i < q->len)
	{
		j = i + 1;
		while (j < q->len)
		{
			tmp = maze->rooms[q->indexs[i]].distence;
			if (tmp > maze->rooms[q->indexs[j]].distence)
			{
				tmp = q->indexs[i];
				q->indexs[i] = q->indexs[j];
				q->indexs[j] = tmp;
			}
			j++;
		}
		i++;
	}
}