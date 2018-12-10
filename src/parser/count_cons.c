#include "libft.h"
#include "lemin.h"

static void	count_con(t_maze *maze, char *str, int *i)
{
	int		r1;
	int		r2;
	size_t	tmp;

	tmp = *i;
	while (str[*i] && str[*i] != '\n' && str[*i] != '-')
		(*i)++;
	if (!str[*i])
		return ;
	if (str[(*i)] == '\n')
	{
		(*i)++;
		return ;
	}
	r1 = get_room_index(maze, &(str[tmp]), *i - tmp);
	tmp = ++(*i);
	while (str[*i] && str[*i] != '\n')
		(*i)++;
	r2 = get_room_index(maze, &(str[tmp]), *i - tmp);
	(*i)++;
	if (r1 == -1 || r2 == -1 || r1 == r2)
		return ;
	maze->rooms[r1].cons_len++;
	maze->rooms[r2].cons_len++;
}

void	count_cons(t_maze *maze, char *str, int i)
{
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '#' && str[i] != 'L' && str[i] != '-')
			count_con(maze, str, &i);
		else
			next_line(str, &i);
	}
}
