/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:19:21 by kbeceren          #+#    #+#             */
/*   Updated: 2023/03/10 13:04:56 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**increment_shell_level(t_data *data, char **env)
{
	int		lvl;
	char	*tmp;

	data->shlvl = ft_getenv("SHLVL", env);
	if (data->shlvl)
	{
		lvl = ft_atoi(data->shlvl);
		env = remove_env_var("SHLVL", env);
	}
	else
		lvl = 0;
	lvl++;
	if (lvl != 1000)
		tmp = ft_itoa(lvl);
	else
		tmp = ft_strdup("");
	data->shlvl = ft_strjoin("SHLVL=", tmp);
	env = env_add(data->shlvl, env);
	free(tmp);
	free(data->shlvl);
	return (env);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)argc;
	(void)argv;
	ft_memset(&data, 0, sizeof(t_data));
	data.new_env = ft_init_env(&data, envp);
	data.new_env = increment_shell_level(&data, data.new_env);
	for(int i = 0; i < 38; i++)
		printf("%s\n", data.new_env[i]);
	while (1)
	{
		data.line = reader(&data); // do not forget to free the memory
		if (!data.line || check_syntax(&data) || is_only_space(data.line))
			continue ;
		// parser(&data);
	}
	return (0);
}
