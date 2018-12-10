/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdel-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 04:48:39 by habdel-i          #+#    #+#             */
/*   Updated: 2017/12/13 04:48:41 by habdel-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	char			*s3;
	unsigned int	l1;

	if (!s1 || !s2)
		return (0);
	l1 = ft_strlen(s1);
	if (!(s3 = ft_strnew(l1 + n)))
		return (0);
	ft_strcpy(s3, s1);
	ft_strncpy(s3 + l1, s2, n);
	return (s3);
}

int		get_line_from_static_buffer(char **static_buffer, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*static_buffer)[i] && (*static_buffer)[i] != '\n')
		i++;
	if ((*static_buffer)[i] != '\n')
		return (0);
	*line = ft_strsub(*static_buffer, 0, i);
	tmp = *static_buffer;
	*static_buffer = ft_strsub(*static_buffer, i + 1,
		ft_strlen(*static_buffer));
	free(tmp);
	return (1);
}

int		next_line(char **static_buffer, char **line, int fd)
{
	char	buff[BUFF_SIZE];
	int		i;
	int		n;
	char	*tmp;

	while ((n = get_line_from_static_buffer(static_buffer, line)) == 0)
	{
		i = read(fd, buff, BUFF_SIZE);
		if (i == -1)
			return (-1);
		if (i == 0 && ft_strlen(*static_buffer) == 0)
			return (0);
		if (n == 0 && i == 0)
		{
			*line = ft_strdup(*static_buffer);
			*static_buffer = ft_strnew(0);
			break ;
		}
		tmp = *static_buffer;
		*static_buffer = ft_strnjoin(*static_buffer, buff, i);
		free(tmp);
	}
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static char *static_buffer[MAX_FD];

	if (fd > MAX_FD || fd < 0 || !line)
		return (-1);
	if (!static_buffer[fd])
		static_buffer[fd] = ft_strnew(BUFF_SIZE);
	return (next_line(&(static_buffer[fd]), line, fd));
}
