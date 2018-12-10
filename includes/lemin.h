#ifndef LEMIN_H
# define LEMIN_H
# define DEBUG 1

typedef struct	s_room
{
	char	*name;
	size_t	name_len;
	size_t	index;//start 1, 0 for deleted con
	size_t	*cons;
	size_t	cons_len;
	size_t	distence;
	size_t	next;
	size_t	previous;
	size_t	path_id;//start 1, 0 for
}				t_room;

typedef struct	s_maze
{
	t_room	*rooms;
	size_t	rooms_count;
	size_t	ants_count;
	size_t	start_index;
	size_t	end_index;
}				t_maze;

void	throw(int	error_code, char *msg, char *debug_msg);
int		get_room_index(t_maze *maze, char *name, size_t len);

char	*read_maze();

t_maze	*parse(char *str);
int		get_ants_count(char *str, int *i);
void	get_rooms(t_maze *maze, char *str, int *i);
void	next_line(char *str, int *i);
void	malloc_rooms(t_maze *maze, char *str, int *i);
void	get_cons(t_maze *maze, char *str, int *i);
void	count_cons(t_maze *maze, char *str, int i);
void	malloc_cons(t_maze *maze);
void	make_cons(t_maze *maze, char *str, int i);

void	debug_maze(t_maze *maze);


#endif
