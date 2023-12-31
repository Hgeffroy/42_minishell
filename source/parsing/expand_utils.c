/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalidi <tmalidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:53:06 by tmalidi           #+#    #+#             */
/*   Updated: 2023/10/03 11:21:39 by tmalidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	range(char *str, char *var, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		if (str[i] == var[0])
		{
			j = 0;
			while (str[i] == var[j] && (size_t)j < ft_strlen(var))
			{
				j++;
				i++;
				if ((size_t)j == ft_strlen(var))
					return (i);
			}
		}
		i++;
	}
	return (-1);
}

char	*rp_env(char *str, char *var, char *value)
{
	char	*sec;
	char	*tmp;
	char	*final;
	int		len;

	sec = ft_strnstr(str, var, ft_strlen(str));
	if (sec == NULL)
		return (NULL);
	sec += ft_strlen(var);
	len = range(str, var, ft_strlen(str));
	tmp = ft_substr(str, 0, len - (int)ft_strlen(var));
	if (!tmp)
		error_manager("rp_env(ft_substr)", MALLOC);
	if (value)
		final = ft_strjoin(tmp, value);
	else
		final = ft_strdup(tmp);
	free(tmp);
	tmp = ft_strjoin(final, sec);
	free(final);
	return (tmp);
}

int	count_var(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i++] == '$')
			c += 1;
	}
	return (c);
}

char	*expand_process(char *str, t_env *env)
{
	char	**tab;
	int		i;
	char	*tmp;
	char	*final;
	char	*rv;

	i = 0;
	final = ft_strdup(str);
	rv = ft_itoa(g_return_value);
	if (!final || !rv)
		return (error_manager("expand_process(ft_strdup)", MALLOC), NULL);
	tab = extract_var(final);
	while (tab && tab[i])
	{
		tmp = change(tab[i], final, env, rv);
		if (!tmp)
			break ;
		free(final);
		final = ft_strdup(tmp);
		if (tmp && tmp[0] == '\0')
			final[0] = 6;
		free(tmp);
		i++;
	}
	return (free_tab(tab), free(rv), free(str), final);
}
