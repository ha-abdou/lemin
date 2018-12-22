#include "libft.h"
#include "lemin.h"
#include <stdlib.h>

static void	new_room(t_maze *maze, char *str, int *i)
{
	int		n;

	maze->rooms[maze->rooms_count].name = str + (*i);
	maze->rooms[maze->rooms_count].index = maze->rooms_count;
	maze->rooms[maze->rooms_count].cons = 0;
	maze->rooms[maze->rooms_count].cons_len = 0;
	maze->rooms[maze->rooms_count].distence = 0;
	maze->rooms[maze->rooms_count].next = -1;
	maze->rooms[maze->rooms_count].previous = -1;
	maze->rooms[maze->rooms_count].ant_id = 0;
	n = 1;
	(*i)++;
	while (str[*i] && str[*i] != ' ')
	{
		(*i)++;
		n++;
	}
	maze->rooms[maze->rooms_count].name_len = n;
}

static void	error(t_maze *maze, char *str, char *msg)
{
	free(maze->rooms);
	free(maze);
	free(str);
	throw(0, msg, 0);
}

static void	get_io(t_maze *maze, char *str, int *i, int t[2])
{
	(*i)++;
	if (!ft_strncmp(&(str[*i]), "#start\n", 7))
	{
		(*i) += 7;
		if (str[*i] == 'L' || str[*i] == '#')
			error(maze, str, "Error: start/end room name error\n");
		new_room(maze, str, i);
		maze->start_index = maze->rooms_count;
		t[0] = 1;
	}
	else if (!ft_strncmp(&(str[*i]), "#end\n", 5))
	{
		(*i) += 5;
		if (str[*i] == 'L' || str[*i] == '#')
			error(maze, str, "Error: start/end room name error\n");
		new_room(maze, str, i);
		maze->end_index = maze->rooms_count;
		t[1] = 1;
	}
	else
		maze->rooms_count++;
}

static void	get(t_maze *maze, char *str, int *i, int t[2])
{
	while (str[*i])
	{
		if (str[*i] == '#' || str[*i] != 'L')
		{
			if (str[*i] == '#')
				get_io(maze, str, i, t);
			else
				new_room(maze, str, i);
			next_line(str, i);
			if (maze->rooms_count == 0)
				break ;
			maze->rooms_count--;
		}
		else
			next_line(str, i);
	}
}

void		get_rooms(t_maze *maze, char *str, int *i)
{
	int		tmp;
	int		t[2];

	t[0] = 0;
	t[1] = 0;
	if (str[*i] == '\n' || str[*i] == '\0')
		error(maze, str, "Error: non rooms\n");
	malloc_rooms(maze, str, i);
	tmp = maze->rooms_count--;
	get(maze, str, i, t);
	maze->rooms_count = tmp;
	if (t[0] == 0 || t[1] == 0)
		error(maze, str, "Error: non start/end\n");
}
