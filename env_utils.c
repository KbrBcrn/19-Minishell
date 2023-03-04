/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:18:39 by kbeceren          #+#    #+#             */
/*   Updated: 2023/03/04 16:38:58 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
It iterates through the env array and checks if any of 
the environment variables have the same name as var. 
If it finds a match, it frees the memory allocated to 
the corresponding string and shifts all the remaining e
lements in the array to the left to fill the gap created by removing the string.
It returns the modified env array with the environment variable removed 
if it exists, or the original env array if the environment variable does not exist in the array.
*/

char	**remove_env_var(char *name, char **env)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		if (env[i][j] && ft_strncmp(name, env[i], ft_strlen(name)) == 0)
		{
			free(env[i]);
			while (env[i])
			{
				env[i] = env[i + 1];
				i++;
			}
			return (env);
		}
		i++;
	}
	return (env);
}
