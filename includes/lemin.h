#ifndef LEMIN_H
# define LEMIN_H
# define DEBUG 1
# include <string.h>

typedef struct	s_q
{
	size_t	*indexs;
	size_t	len;
	size_t	value;//todo remove value from index function
}				t_q;

typedef struct	s_room
{
	char	*name;
	size_t	name_len;
	size_t	index;
	size_t	*cons;
	size_t	cons_len;
	size_t	distence;
	int		next;
	int		previous;//todo remove if not used
	size_t	path_id;
}				t_room;

typedef struct	s_maze
{
	t_room	*rooms;
	size_t	rooms_count;
	size_t	ants_count;
	size_t	start_index;
	size_t	end_index;
//	size_t	paths_count;
//	size_t	*paths_start;
}				t_maze;
/**
 * utility functions
 */
void	throw(int	error_code, char *msg, char *debug_msg);
int		get_room_index(t_maze *maze, char *name, size_t len);
/**
 * read functions
 */
char	*read_maze();
/**
 * parse functions
 */
t_maze	*parse(char *str);
int		get_ants_count(char *str, int *i);
void	get_rooms(t_maze *maze, char *str, int *i);
void	next_line(char *str, int *i);
void	malloc_rooms(t_maze *maze, char *str, int *i);
void	get_cons(t_maze *maze, char *str, int *i);
void	count_cons(t_maze *maze, char *str, int i);
void	malloc_cons(t_maze *maze);
void	make_cons(t_maze *maze, char *str, int i);
/**
 * solve functions
 */
void	index_rooms(t_maze *maze);
void	solve_maze(t_maze *maze);
/**
 * debug functions
 */
void	debug_maze(t_maze *maze);
void	print_room_name(t_maze *maze, int index);

#endif
