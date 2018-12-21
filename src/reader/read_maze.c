#include "libft.h"
#include "lemin.h"
#include <stdlib.h>
#include <unistd.h>

//
char	*read_maze()
{
	int		n;
	char	*buff;
	char	*str;
	char	*tmp;

	if (!(buff = (char*)malloc(sizeof(char) * 5001)))
		throw(0, 0, "Error: cant malloc\n");//todo error code
	if (!(str = (char*)malloc(sizeof(char) * 1)))
		throw(0, 0, "Error: cant malloc\n");//todo error code
	buff[0] = '\0';
	str[0] = '\0';
	while ((n = read(0, buff, 5000)))
	{
		if (n == -1)
			throw(0, "Error\n", "Error: read return -1\n");//todo error code
		buff[n] = '\0';
		tmp = str;
		if (!(str = ft_strjoin(str, buff)))
			throw(0, 0, "Error: ft_strjoin return 0\n");//todo error code
		free(tmp);
	}
	free(buff);
	return (str);
}
