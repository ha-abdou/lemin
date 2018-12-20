#include "libft.h"
#include "lemin.h"
#include <stdlib.h>
#include <stdio.h>

//not good
void	to_the_end(t_maze *maze, size_t index)
{
		int	small_index;
		size_t	small_d;
		size_t	i;

		print_room_name(maze, index);
		ft_putchar(' ');
		if (maze->rooms[index].distence == 0 || maze->rooms[index].cons_len == 0)
			return ;
		small_index = -1;
		small_d = maze->rooms[index].distence;
		i = 0;
		while (i < maze->rooms[index].cons_len)
		{
	//		printf("------>%d, %d\n", maze->rooms[ maze->rooms[index].cons[i] ].distence, small_d);
	//		printf("*%d\n", maze->rooms[ maze->rooms[index].cons[i] ].next);
			if (maze->rooms[ maze->rooms[index].cons[i] ].distence <= small_d &&\
				maze->rooms[ maze->rooms[index].cons[i] ].next == 0 &&
				maze->rooms[index].cons[i] != maze->start_index
				)
			{
	//			printf("---->\n");
				small_index = maze->rooms[index].cons[i];
				small_d = maze->rooms[small_index].distence;
			}
			i++;
		}
		maze->rooms[index].next = small_index;
	//	printf("%d -> %d:\n", index, small_index);
		if (small_index != (int)maze->end_index && small_index != -1)
			to_the_end(maze, small_index);
}

static void	set_best_next(t_maze *maze, int index, t_q *q)
{
	//for all cons get best empty one
	size_t	i;
	int		best_next;
	size_t	best_d;

	best_next = -1;
	best_d = maze->rooms[index].distence;
	i = 0;
	//for all cons
	while (i < maze->rooms[index].cons_len)
	{
		//if not connected and is the small distance
		if (maze->rooms[ maze->rooms[index].cons[i] ].previous == -1 &&
			best_d > maze->rooms[ maze->rooms[index].cons[i] ].distence &&
			maze->rooms[index].cons[i] != maze->start_index
			)
		{
			best_next = maze->rooms[index].cons[i];
			best_d = maze->rooms[best_next].distence;
		}
		i++;
	}
	if (best_next == -1)
		printf("todo\n");
	else
	{
		maze->rooms[index].next = best_next;
		if (best_next != maze->end_index)
		{
			maze->rooms[best_next].previous = index;
			q->indexs[q->len] = best_next;
			q->len++;
		}
	}
}

static void	solve(t_maze *maze, t_q q, t_q q_2)//todo *q *q_2
{
	size_t		i;

	i = 0;
	q_2.len = 0;
	//for all q
	while (i < q.len)
	{
		//if not end
		if (q.indexs[i] != maze->end_index)
		{
			//if 
			if (maze->rooms[q.indexs[i]].distence == q.value)
				set_best_next(maze, q.indexs[i], &q_2);
			else//if rooms is ahead set it for next q
			{
				q_2.indexs[q_2.len] = q.indexs[i];
				q_2.len++;
			}
			i++;
		}
	}
	q_2.value = q.value - 1;
	if (q_2.len != 0 && q_2.value != 0)
		solve(maze, q_2, q);
}

void	solve_maze(t_maze *maze)
{
	t_q		q;
	t_q		q_2;
	t_room	target;
	int		i;

	if (!(q.indexs = (size_t *)malloc(sizeof(size_t) * maze->rooms_count)))//todo small q
		throw(0, "Error: can't malloc q_1\n", 0);
	if (!(q_2.indexs = (size_t *)malloc(sizeof(size_t) * maze->rooms_count)))//todo small q
		throw(0, "Error: can't malloc q_2\n", 0);
	q.len = 0;
	q.value = 1;
	i = 0;
	target = maze->rooms[maze->start_index];
	while (q.len < target.cons_len)
	{
		if (maze->rooms[target.cons[i]].distence != 0)
		{
			if (maze->rooms[target.cons[i]].distence > q.value)
				q.value = maze->rooms[target.cons[i]].distence;
			maze->rooms[target.cons[i]].previous = maze->start_index;
			q.indexs[q.len] = target.cons[i];
			q.len++;
		}
		i++;
	}
	if (q.len == 0)
		throw(0, "Error: non posible path found!\n", 0);
		//todo order the q
	solve(maze, q, q_2);
}