/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:48:02 by tmalidi           #+#    #+#             */
/*   Updated: 2023/09/13 13:48:29 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_te(t_element **subparsing)
{
	t_element	*tmp;
	t_element	*cu;

	tmp = *subparsing;
	while (tmp)
	{
		cu = tmp->next;
		if (tmp->type != 0)
			free(tmp->str);
		free(tmp);
		tmp = cu;
	}
}

void	free_elm(t_big_list *arg)
{
	t_big_list	*tmp;

	tmp = arg;
	while (tmp)
	{
		if (tmp->content)
		{
			free_te(tmp->pipelist);
			free(tmp->pipelist);
		}
		tmp = tmp->next;
	}
}
