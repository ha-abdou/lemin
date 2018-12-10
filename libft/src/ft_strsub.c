/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdel-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:35:09 by habdel-i          #+#    #+#             */
/*   Updated: 2017/11/13 13:48:04 by habdel-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	char	*s;

	if (!str || !(s = ft_strnew(len)))
		return (0);
	return (ft_strncpy(s, str + start, len));
}
