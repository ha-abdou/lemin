#include "libft.h"
#include "lemin.h"

int		get_ants_count(char *str, int *i)
{
	while (ft_isdigit(str[*i]))
		(*i)++;
	if (str[*i] != '\n' || *i == 0)//todo review
		throw(0, "Error: not valid ants number\n", 0);
	(*i)++;
	return (ft_atoi(str));
}
