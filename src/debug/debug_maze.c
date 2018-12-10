#include "libft.h"
#include "lemin.h"

static void	print_room_name(t_maze *maze, int index)
{
	int		i;

	i = 0;
	while ((size_t)i < maze->rooms[index].name_len)
	{
		ft_putchar(maze->rooms[index].name[i]);
		i++;
	}
}

static void	debug_rooms(t_maze *maze)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < maze->rooms_count)
	{
		ft_putstr("\nroom: ");
		print_room_name(maze, i);
		ft_putstr(" ,distence: ");
		ft_putnbr(maze->rooms[i].distence);
		ft_putstr("\nconnected to: ");
		j = 0;
		while (j < maze->rooms[i].cons_len)
		{
			print_room_name(maze, maze->rooms[i].cons[j]);
			ft_putstr(" ");
			j++;
		}
		i++;
		ft_putstr("\n---------*---------");
	}
}

void		debug_maze(t_maze *maze)
{
	ft_putstr("\nants count: ");
	ft_putnbr(maze->ants_count);
	ft_putstr("\nrooms count: ");
	ft_putnbr(maze->rooms_count);
	ft_putstr("\nstart: ");
	print_room_name(maze, maze->start_index);
	ft_putstr("\nend: ");
	print_room_name(maze, maze->end_index);
	ft_putstr("\n---------*---------");
	debug_rooms(maze);
}
