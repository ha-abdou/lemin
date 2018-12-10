/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdel-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:58:51 by habdel-i          #+#    #+#             */
/*   Updated: 2017/11/13 15:15:32 by habdel-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s3;
	unsigned int	l1;

	if (!s1 || !s2)
		return (0);
	l1 = ft_strlen(s1);
	if (!(s3 = ft_strnew(l1 + ft_strlen(s2))))
		return (0);
	ft_strcpy(s3, s1);
	ft_strcpy(s3 + l1, s2);
	return (s3);
}
