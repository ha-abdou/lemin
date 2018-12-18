#include "libft.h"
#include "lemin.h"
#include <stdlib.h>
#include <stdio.h>

static void	index_it(t_maze *maze, t_q q, t_q q_2)
{
	size_t		j;
	size_t		i;
	t_room	target;

	q_2.value = q.value + 1;
	q_2.len = 0;
	i = 0;
	//for all q
	while (i < q.len)
	{
		target = maze->rooms[q.indexs[i]];
		//if non distence
		if (target.distence == 0 && q.indexs[i] != maze->start_index && q.indexs[i] != maze->end_index)
		{
			j = 0;
			//set value for all elm of q
			maze->rooms[q.indexs[i]].distence = q.value;
			//for cons of target
			while (j < target.cons_len)
			{
				//add to new q
				q_2.indexs[q_2.len] = target.cons[j];
				q_2.len++;
				j++;
			}
		}
		i++;
	}
	if (q_2.len > 0)
		index_it(maze, q_2, q);
}

void		index_rooms(t_maze *maze)
{
	t_q		q;
	t_q		q_2;
	t_room	target;

	if (!(q.indexs = (size_t *)malloc(sizeof(size_t) * maze->rooms_count)))
		throw(0, "Error: can't malloc q_1\n", 0);
	if (!(q_2.indexs = (size_t *)malloc(sizeof(size_t) * maze->rooms_count)))
		throw(0, "Error: can't malloc q_2\n", 0);
	q.len = 0;
	target = maze->rooms[maze->end_index];
	while (q.len < target.cons_len)
	{
		q.indexs[q.len] = target.cons[q.len];
		q.len++;
	}
	q.value = 1;
	index_it(maze, q, q_2);
}
