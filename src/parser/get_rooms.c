#include "libft.h"
#include "lemin.h"
#include <stdlib.h>

void	new_room(t_maze *maze, char *str, int *i)
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

void	get_io(t_maze *maze, char *str, int *i)
{
	(*i)++;
	if (!ft_strncmp(&(str[*i]), "#start\n", 7))
	{
		(*i) += 7;
		new_room(maze, str, i);
		maze->start_index = maze->rooms_count;
	}
	else if (!ft_strncmp(&(str[*i]), "#end\n", 5))
	{
		(*i) += 5;
		new_room(maze, str, i);
		maze->end_index = maze->rooms_count;
	}
	else
		maze->rooms_count++;//todo remove
}

void		get_rooms(t_maze *maze, char *str, int *i)
{
	int		tmp;

	if (str[*i] == '\n' || str[*i] == '\0')
		throw (0 , "Error: non rooms\n", 0);
	malloc_rooms(maze, str, i);
	tmp = maze->rooms_count--;
	while (str[*i])
	{
		if (str[*i] == '#' || str[*i] != 'L')
		{
			if (str[*i] == '#')
				get_io(maze, str, i);
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
	maze->rooms_count = tmp;
}

/*
void		get_rooms(t_maze *maze, char *str, int *i)
{
	int		tmp;

	if (str[*i] == '\n' || str[*i] == '\0')
		throw (0 , "Error: non rooms\n", 0);
	malloc_rooms(maze, str, i);
	tmp = maze->rooms_count--;
	while (str[*i] && maze->rooms_count)
	{
		if (str[*i] == '#' || str[*i] != 'L')
		{
			if (str[*i] == '#')
				get_io(maze, str, i);
			else
				new_room(maze, str, i);
			next_line(str, i);
			maze->rooms_count--;
		}
		else
			next_line(str, i);
	}
	maze->rooms[0] = 0;
	maze->rooms_count = tmp;
*/