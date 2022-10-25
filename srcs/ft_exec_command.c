/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:46:33 by rstephan          #+#    #+#             */
/*   Updated: 2022/03/08 17:46:47 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env(t_env *env)
{
	while (env)
	{
		printf("%s\n", env->content);
		env = env->next;
	}
	exit(0);
}

int	len_list_env(t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		env = env->next;
		i++;
	}
	return (i);
}

char	**env_convert(t_env *env, t_garbage **garbage)
{
	int		len;
	int		i;
	char	**result_env;

	len = len_list_env(env);
	result_env = (char **)save_malloc(sizeof(char *) * (len + 1), garbage);
	result_env[len] = 0;
	i = 0;
	while (env)
	{
		result_env[i] = env->content;
		env = env->next;
		i++;
	}
	return (result_env);
}

int	file_descriptor_handler(int in, int out)
{
	if (in != 0)
	{
		dup2(in, 0);
		close(in);
	}
	if (out != 1)
	{
		dup2(out, 1);
		close(out);
	}
	return (0);
}
