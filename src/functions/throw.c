#include "libft.h"
#include "lemin.h"
#include <stdlib.h>

void	throw(int	error_code, char *msg, char *debug_msg)
{
	if (DEBUG && debug_msg)
		ft_putstr(debug_msg);
	else if (msg)
		ft_putstr(msg);
	exit(error_code);
}