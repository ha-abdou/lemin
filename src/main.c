#include "libft.h"
#include "lemin.h"

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
	if (small_index != maze->end_index && small_index != -1)
		to_the_end(maze, small_index);
}

void	solve_maze(t_maze *maze)
{
	size_t	i;

	i = 0;
	printf("-----------------\n");
	while (i < maze->rooms[maze->start_index].cons_len)
	{
		ft_putstr("2 end: ");
		to_the_end(maze, maze->rooms[maze->start_index].cons[i]);
		ft_putchar('\n');
//		throw(0,0,0);
		i++;
	}
}

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
		ft_putstr("room: ");
		print_room_name(maze, maze->rooms[maze->start_index].cons[i]);
		ft_putstr(" ,distence: ");
		ft_putnbr(maze->rooms[maze->rooms[maze->start_index].cons[i]].distence);
		ft_putchar('\n');
		i++;
	}
	solve_maze(maze);
/*	free_mem(str, maze);*/
	return (0);
}
