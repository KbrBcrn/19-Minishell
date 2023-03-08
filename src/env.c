/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:38:05 by kbeceren          #+#    #+#             */
/*   Updated: 2023/03/08 09:27:33 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_getenv(const char *name, char **env)
{
	if (!name || !env)
		return (NULL);
	while (*env)
	{
		if (ft_strncmp(name, *env, ft_strlen(name)) == 0
			&& (*env)[ft_strlen(name)] == '=')
			return (*env + ft_strlen(name) + 1);
		env++;
	}
	return (NULL);
}

char	**env_add(char *str, char **env)
{
	char	**new_env;
	int		env_len;
	int		i;

	env_len = 0;
	while (env[env_len] != NULL)
		env_len++;
	new_env = malloc(sizeof(char *) * (env_len + 2));
	i = 0;
	while (i < env_len)
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = ft_strdup(str);
	new_env[i+1] = NULL;
	// free_str_array(env);
	return (new_env);
}

char	**update_pwd(char **env)
{
	char	*path;
	char	*var;

	env = remove_env_var("PWD", env);
	path = getcwd(NULL, 0);
	var = ft_strdup("PWD=");
	var = ft_strjoin(var, path);
	env = env_add(var, env);
	free(var);
	free(path);
	return (env);
}
