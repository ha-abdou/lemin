#include "libft.h"
#include "lemin.h"

void	debug_paths(t_maze *maze)
{
	size_t	i;
	int		con;
	int		len;

	printf("ants count: %d\n", (int)maze->ants_count);
	i = 0;
	while (i < maze->rooms[maze->start_index].cons_len)
	{
		con = maze->rooms[maze->start_index].cons[i];
		if (maze->rooms[con].next != -1)
		{
			len = 0;
			printf("path %d:\n", i + 1);
			print_room_name(maze, maze->start_index);
			ft_putstr("-->");
			while (con != maze->end_index)
			{
				if (con == -1)
					break ;
				print_room_name(maze, con);
				ft_putstr("->");
				con = maze->rooms[con].next;
				len++;
			}
			if (con == -1)
			{
				ft_putstr("--->|\n");
				ft_putstr("dead end\n\n");
			}
			else
			{
				len++;
				print_room_name(maze, maze->end_index);
				ft_putchar('\n');
				printf("len: %d\n\n", len);
			}
		}
		i++;
	}
}

int		main(void)
{
	char	*str;
	t_maze	*maze;

	//read the file form std input
	str = read_maze();
	//parse the file
	maze = parse(str);
	ft_putchar('\n');
	//index rooms
	index_rooms(maze);
	
	//debud first rooms connected to start point
/*	int	i = 0;
	while (i < maze->rooms[maze->start_index].cons_len)
	{
		ft_putstr("room: ");
		print_room_name(maze, maze->rooms[maze->start_index].cons[i]);
		ft_putstr(" ,distence: ");
		ft_putnbr(maze->rooms[maze->rooms[maze->start_index].cons[i]].distence);
		ft_putchar('\n');
		i++;
	}*/
	//solve the maze
	solve_maze(maze);
	debug_paths(maze);
/*	free_mem(str, maze);*/
	return (0);
}
