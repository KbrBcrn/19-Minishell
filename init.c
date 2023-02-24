/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:25:35 by kbeceren          #+#    #+#             */
/*   Updated: 2023/02/24 12:51:22 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_init_env(t_data *data, char **envp)
{
	int		i;

	i = 0;
	while (envp[i]) //Count the number of environmebt variables
		i++;
	data->new_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		data->new_env[i] = ft_strdup(envp[i]);
		i++;
	}
	data->new_env[i] = NULL;
	data->shlvl = get_env(data->new_env, "SHLVL=");
	if (!data->shlvl)
		add_env(data, data->new_env, "SHLVL=1");
	else
		incremenet_shell_level(data->new_env);
}

/* get_shvl is used to obtain the value of the SHLVL environment variable, 
which indicates the nesting level of the shell process. 
The value of SHLVL is incremented each time a new shell process is created.
Function returns a pointer to the value of the environment variable
(which starts after the equals sign).
*/

char	*get_env(char **env, char *name)
{
	int		i;
	char	*shlvl;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(name, env[i], 6) == 0)
		{
			shlvl = ft_strdup(env[i] + 6);
			return (shlvl);
		}
		i++;
	}
	shlvl = ft_strdup("0");
	return (shlvl);
}

