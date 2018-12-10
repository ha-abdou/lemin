#include "libft.h"
#include "lemin.h"

void	connect(t_maze *maze, int r1, int r2)
{
	size_t	i;

	i = 0;
	while (maze->rooms[r1].cons[i])
	{
		if (maze->rooms[r1].cons[i] == (size_t)r2)
			return ;
		i++;
	}
	maze->rooms[r1].cons[i] = r2;
	i = 0;
	while (maze->rooms[r2].cons[i])
		i++;
	maze->rooms[r2].cons[i] = r1;
}

static void	make_con(t_maze *maze, char *str, int *i)
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
	connect(maze, r1, r2);
}

void	make_cons(t_maze *maze, char *str, int i)
{
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '#' && str[i] != 'L' && str[i] != '-')
			make_con(maze, str, &i);
		else
			next_line(str, &i);
	}
}
