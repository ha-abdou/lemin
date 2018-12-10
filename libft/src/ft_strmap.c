/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmqp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdel-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:52:50 by habdel-i          #+#    #+#             */
/*   Updated: 2017/11/13 13:03:54 by habdel-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *str, char (*f)(char))
{
	char	*s;
	int		i;

	if (!str || !(s = ft_strnew(ft_strlen(str))))
		return (0);
	i = 0;
	while (str[i])
	{
		s[i] = f(str[i]);
		i++;
	}
	return (s);
}
