/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:25:35 by kbeceren          #+#    #+#             */
/*   Updated: 2023/03/08 09:25:36 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
This function duplicates the given environment variables 
envp and makes some modifications to it. It creates a new environment 
variable MINISHELL with the current working directory as its value 
and adds it to the duplicated environment. It also removes any existing 
MINISHELL and OLDPWD environment variables if they exist. Finally, 
it updates the value of PWD environment variable to the current working directory.
*/

char	**ft_init_env(t_data *data, char **envp)
{
	int		i;
	char	*str;

	i = 0;
	while (envp[i])
		i++;
	data->new_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		data->new_env[i] = ft_strdup(envp[i]);
		i++;
	}
	data->new_env[i] = NULL;
	data->current_pwd = getcwd(NULL, 0);
	str = ft_getenv(".MINISHELL", data->new_env);
	if (str)
	{
		data->new_env = remove_env_var(".MINISHELL", data->new_env);
		free(str);
	}
	data->path = ft_strdup(".MINISHELL=");
	data->path = ft_strjoin(ft_strjoin(data->path, data->current_pwd),
			"/minishell");
	data->new_env = remove_env_var("OLDPWD", data->new_env);
	data->new_env = update_pwd(data->new_env);
	free(data->current_pwd);
	free(data->path);
	return (data->new_env);
}
