/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdel-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:40:33 by habdel-i          #+#    #+#             */
/*   Updated: 2017/11/10 10:56:49 by habdel-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	if (!*n)
		return ((char *)h);
	i = 0;
	while (h[i] && i < len)
	{
		j = 0;
		if (n[j] == h[i])
		{
			tmp = i;
			while (n[j] && h[tmp] && n[j] == h[tmp] && tmp < len)
			{
				tmp++;
				j++;
			}
			if (n[j] == '\0')
				return ((char *)(h + i));
		}
		i++;
	}
	return (0);
}
