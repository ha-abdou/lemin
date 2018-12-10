/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdel-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:39:37 by habdel-i          #+#    #+#             */
/*   Updated: 2017/11/15 10:39:39 by habdel-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dst, char *src, unsigned int size)
{
	size_t	i;
	size_t	s1;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (dst[i] && i < size)
		i++;
	s1 = i;
	while (src[i - s1] && i < size - 1)
	{
		dst[i] = src[i - s1];
		i++;
	}
	if (s1 < size)
		dst[i] = '\0';
	return (s1 + ft_strlen(src));
}
