/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdel-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:54:51 by habdel-i          #+#    #+#             */
/*   Updated: 2017/11/09 14:06:18 by habdel-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s_dst;
	unsigned char	*s_src;

	s_dst = (unsigned char*)dst;
	s_src = (unsigned char*)src;
	while (n--)
	{
		*s_dst = *s_src;
		s_dst++;
		s_src++;
	}
	return (dst);
}
