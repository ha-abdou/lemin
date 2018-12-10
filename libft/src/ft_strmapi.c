/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmqpi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdel-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:04:02 by habdel-i          #+#    #+#             */
/*   Updated: 2017/11/13 13:21:56 by habdel-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char			*s;
	unsigned int	i;

	if (!str || !(s = ft_strnew(ft_strlen(str))))
		return (0);
	i = 0;
	while (str[i])
	{
		s[i] = f(i, str[i]);
		i++;
	}
	return (s);
}
