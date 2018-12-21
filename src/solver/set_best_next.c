#include "libft.h"
#include "lemin.h"
/**
 * check if room is not used in a path
 * 
 */
static int	can_connect(t_maze *maze, size_t room)
{
	return (maze->rooms[room].previous == -1 && room != maze->start_index);
}
/**
 * check if room can be connected for path
 * 
 */
static int	has_one_possible_next(t_maze *maze, int index, size_t *i)
{
	if (maze->rooms[index].cons_len == 0)
		return (0);
	*i = 0;
	while (*i < maze->rooms[index].cons_len &&\
		!can_connect(maze, maze->rooms[index].cons[*i]))
		(*i)++;
	if (*i >= maze->rooms[index].cons_len)
		return (0);
	return (1);
}
/**
 * extend the path from the room index if possible
 * 
 */
void		set_best_next(t_maze *maze, int index, t_q *q)
{
	size_t	i;
	size_t	best_next;
	size_t	best_d;

	if (!has_one_possible_next(maze, index, &i))
		return ;
	best_next = maze->rooms[index].cons[i];
	best_d = maze->rooms[best_next].distence;
	i++;
	while (i < maze->rooms[index].cons_len)
	{
		if (can_connect(maze, maze->rooms[index].cons[i]) &&
			best_d > maze->rooms[ maze->rooms[index].cons[i] ].distence)
		{
			best_next = maze->rooms[index].cons[i];
			best_d = maze->rooms[best_next].distence;
		}
		i++;
	}
	maze->rooms[index].next = best_next;
	if (best_next != maze->end_index)
	{
		maze->rooms[best_next].previous = index;
		q->indexs[q->len++] = best_next;
	}
}
