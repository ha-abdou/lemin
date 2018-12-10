/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdel-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:37:45 by habdel-i          #+#    #+#             */
/*   Updated: 2017/11/20 10:37:48 by habdel-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	if (!content)
		content_size = 0;
	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(lst->content = (void *)malloc(content_size)))
			return (NULL);
		ft_memcpy(lst->content, content, content_size);
	}
	else
		lst->content = 0;
	lst->content_size = content_size;
	lst->next = 0;
	return (lst);
}
