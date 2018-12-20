NAME		= lem-in
LIBFT		= libft/libft.a
CC			= gcc
INC			= -I libft/includes -I includes
FLAGS		= -Wall -Wextra $(INC)

OBJ			= src/main.o\
src/functions/throw.o\
src/functions/get_room_index.o\
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
src/solver/index_rooms.o

$(NAME): $(OBJ) includes/lemin.h
	@make -C libft/
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f *.o
	/bin/rm -f */*.o
	/bin/rm -f */*/*.o
	/bin/rm -f */*/*/*.o
	/bin/rm -f */*/*/*/*.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test