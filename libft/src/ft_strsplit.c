/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdel-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:43:55 by habdel-i          #+#    #+#             */
/*   Updated: 2017/11/14 11:59:07 by habdel-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include <stdio.h>

static int		get_tab_size(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;
	int		tab_size;

	if (!s || !c)
		return (NULL);
	tab_size = get_tab_size(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * get_tab_size(s, c) + 1)))
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (tab_size--)
			tab[k++] = ft_strsub(s, j, i - j);
	}
	tab[k] = 0;
	return (tab);
}
