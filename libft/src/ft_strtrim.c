/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdel-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:23:37 by habdel-i          #+#    #+#             */
/*   Updated: 2017/11/13 16:43:37 by habdel-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int start;
	unsigned int end;
	unsigned int i;

	if (!s)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen(s);
	while (s[i] && (s[i] == '\n' || s[i] == ' ' || s[i] == '\t'))
		i++;
	start = i;
	if (start == end)
		return (ft_strnew(0));
	i = end - 1;
	while (i != 0 && (s[i] == '\n' || s[i] == ' ' || s[i] == '\t'))
		i--;
	return (ft_strsub(s, start, i - start + 1));
}
