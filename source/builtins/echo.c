/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:27:42 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/09/29 08:25:48 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	noneed_breakline(char *args);

static int	noneed_breakline(char *args)
{
	int	i;

	if (!args)
		return (0);
	if (ft_strncmp(args, "-n", 2) == 0)
	{
		i = 1;
		while (args[++i])
		{
			if (args[i] != 'n')
				return (0);
		}
		return (1);
	}
	return (0);
}

int	echo_b(t_data *data)
{
	int	i;

	if (!(data->args) || !(data->args[1]))
	{
		g_return_value = 0;
		return (printf("\n"), 0);
	}
	i = 1;
	while (noneed_breakline(data->args[i]) == 1)
		i++;
	if (data->args[i])
	{
		while (strncmp(data->args[i], "\6", 1) == 0)
			i++;
		printf("%s", data->args[i]);
		while (data->args[++i])
		{
			if (strncmp(data->args[i], "\6", 1) != 0)
				printf(" %s", data->args[i]);
		}
	}
	if (noneed_breakline(data->args[1]) == 0)
		printf("\n");
	g_return_value = 0;
	return (g_return_value);
}
