#include "libft.h"
#include "lemin.h"
#include <stdlib.h>

static void		move_ant_at(t_maze *maze, size_t room)
{
	ft_putchar('L');
	ft_putnbr(maze->rooms[room].ant_id);
	ft_putchar('-');
	print_room_name(maze, maze->rooms[room].next);
	ft_putchar(' ');
	maze->rooms[maze->rooms[room].next].ant_id = maze->rooms[room].ant_id;
	maze->rooms[room].ant_id = 0;
}

static size_t	move_all(t_maze *maze)
{
	size_t	i;
	size_t	moved;
	int		room;
	
	moved = 0;
	i = 0;
	while (i < maze->rooms[maze->end_index].cons_len)
	{
		room = maze->rooms[maze->end_index].cons[i];
		while (maze->rooms[room].ant_id == 0 &&\
			room != (int)maze->start_index &&\
			maze->rooms[room].previous != -1)
			room = (int)maze->rooms[room].previous;
		if (maze->rooms[room].ant_id && room != (int)maze->start_index)
		{
			while (maze->rooms[room].ant_id && room != (int)maze->start_index)
			{
				move_ant_at(maze, room);
				room = maze->rooms[room].previous;
			}
			moved = 1;
		}
		i++;
	}
	return (moved);
}

static void		push_to_path(t_maze *maze, t_path *paths)
{
	size_t	i;

	i = 0;
	while (i < maze->paths_count)
	{
		if (paths[i].buff && maze->rooms[paths[i].start_index].ant_id == 0)
		{
			ft_putchar('L');
			ft_putnbr(paths[i].start_ant);
			ft_putchar('-');
			print_room_name(maze, paths[i].start_index);
			ft_putchar(' ');
			maze->rooms[paths[i].start_index].ant_id = paths[i].start_ant;
			paths[i].buff--;
			paths[i].start_ant++;
		}
		i++;
	}
}

void			print_solution(t_maze *maze)
{
	t_path	*paths;
	size_t	i;

	i = 1;
	paths = get_paths(maze);
	dispatsh_ants(maze, paths);
	push_to_path(maze, paths);
	ft_putchar('\n');
	while (move_all(maze))
	{
		push_to_path(maze, paths);
		ft_putchar('\n');
		i++;
	}
	printf("line count: %zu\n", i);
	free(paths);
}
