/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:47:07 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/08/24 14:05:48 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elt;

	elt = (t_list *)malloc(sizeof(t_list));
	if (!elt)
		return (NULL);
	elt->content = content;
	elt->next = NULL;
	return (elt);
}
