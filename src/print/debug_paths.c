#include "libft.h"
#include "lemin.h"

void		debug_paths(t_maze *maze, t_path *paths)
{
	size_t		i;

	i = 0;
	ft_putstr("ants count: ");
	ft_putnbr((int)maze->ants_count);
	ft_putstr("\n");
	while (i < maze->paths_count)
	{
		ft_putstr("\npath: ");
		ft_putnbr((int)i + 1);
		ft_putstr("\nlen: ");
		ft_putnbr((int)paths[i].len);
		ft_putstr("\nstart point: ");
		print_room_name(maze, paths[i].start_index);
		ft_putstr("\nants buff size: ");
		ft_putnbr((int)paths[i].buff);
		ft_putstr("\nstart ant: ");
		ft_putnbr((int)paths[i].start_ant);
		ft_putstr("\n");
		i++;
	}
}
