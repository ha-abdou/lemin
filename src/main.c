#include "libft.h"
#include "lemin.h"

static int	direct_path(t_maze *maze)
{
	size_t	i;

	i = 0;
	while (i < maze->rooms[maze->start_index].cons_len)
	{
		if (maze->rooms[maze->start_index].cons[i] == maze->end_index)
		{
			while (maze->ants_count)
			{
				ft_putchar('L');
				ft_putnbr(maze->ants_count);
				ft_putchar('-');
				print_room_name(maze, maze->end_index);
				ft_putchar(' ');
				maze->ants_count--;
			}
			ft_putchar('\n');
			return (1);
		}
		i++;
	}
	return (0);
}

int			main(void)
{
	char	*str;
	t_maze	*maze;

	str = read_maze();
	maze = parse(str);
	index_rooms(maze);
	ft_putstr(str);
	ft_putchar('\n');
	if (!direct_path(maze))
	{
		solve_maze(maze);
		print_solution(maze);
	}
	free_mem(maze, str);
	return (0);
}