#include "libft.h"
#include "lemin.h"

int		main(void)
{
	char	*str;
	t_maze	*maze;

	str = read_maze();
	maze = parse(str);
	ft_putchar('\n');
	index_rooms(maze);
	
	int	i = 0;
	while (i < maze->rooms[maze->start_index].cons_len)
	{
		ft_putstr("\nroom: ");
		print_room_name(maze, maze->rooms[maze->start_index].cons[i]);
		ft_putstr(" ,distence: ");
		ft_putnbr(maze->rooms[maze->rooms[maze->start_index].cons[i]].distence);
		i++;
	}
	/*
	solve_maze(&maze);
	free_mem(str, maze);*/
	return (0);
}
