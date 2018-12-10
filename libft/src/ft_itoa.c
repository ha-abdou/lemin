/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdel-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:01:25 by habdel-i          #+#    #+#             */
/*   Updated: 2017/11/14 13:55:35 by habdel-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int	int_len(int n)
{
	int		i;

	i = 0;
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	i++;
	return (i);
}

static void	get_num(int n, char *str, int len)
{
	if (n == 0)
	{
		str[0] = '0';
		return ;
	}
	while (n > 0)
	{
		str[len - 1] = '0' + n % 10;
		n /= 10;
		len--;
	}
}

char		*ft_itoa(int n)
{
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strcpy(ft_strnew(11), "-2147483648"));
	if (n < 0)
	{
		n *= -1;
		len = int_len(n);
		if (!(str = ft_strnew(len + 1)))
			return (NULL);
		str[0] = '-';
		get_num(n, str + 1, len);
	}
	else
	{
		len = int_len(n);
		if (!(str = ft_strnew(len)))
			return (NULL);
		get_num(n, str, len);
	}
	return (str);
}
