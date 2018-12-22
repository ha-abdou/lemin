NAME		= lem-in
LIBFT		= libft/libft.a
CC			= gcc
INC			= -I libft/includes -I includes
FLAGS		= -Wall -Wextra -g $(INC)

OBJ			= src/main.o\
src/functions/throw.o\
src/functions/get_room_index.o\
src/functions/free_mem.o\
src/debug/debug_maze.o\
src/reader/read_maze.o\
src/parser/parse.o\
src/parser/get_ants_count.o\
src/parser/get_rooms.o\
src/parser/next_line.o\
src/parser/get_cons.o\
src/parser/malloc_rooms.o\
src/parser/malloc_cons.o\
src/parser/count_cons.o\
src/parser/make_cons.o\
src/solver/solve_maze.o\
src/solver/index_rooms.o\
src/solver/set_best_next.o\
src/solver/create_free_q.o\
src/solver/sort_q.o\
src/print/print_solution.o\
src/print/dispatcher.o\
src/print/get_paths.o\
src/print/debug_paths.o

$(NAME): $(OBJ) includes/lemin.h
	@make -C libft/
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

all: $(NAME)

%.o: %.c includes/lemin.h
	@$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re