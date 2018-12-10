#include "libft.h"
#include "lemin.h"

void	next_line(char *str, int *i)
{
	while (str[*i] && str[*i] != '\n')
		(*i)++;
	if (str[*i])
		(*i)++;
}
