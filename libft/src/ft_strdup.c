/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdel-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:13:48 by habdel-i          #+#    #+#             */
/*   Updated: 2017/11/09 16:25:45 by habdel-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*s;

	if (!(s = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (0);
	ft_strcpy(s, str);
	return (s);
}
