/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdel-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:30:24 by habdel-i          #+#    #+#             */
/*   Updated: 2017/11/13 11:37:23 by habdel-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void		*ft_memalloc(size_t n)
{
	void	*mem;

	if (!(mem = (void *)malloc(sizeof(void) * n)))
		return (NULL);
	ft_memset(mem, 0, n);
	return (mem);
}
