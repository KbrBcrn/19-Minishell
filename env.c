/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:38:05 by kbeceren          #+#    #+#             */
/*   Updated: 2023/03/04 16:50:58 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
The function first checks to make sure that both arguments are not NULL. 
It then iterates through the env array, comparing each environment variable 
name to the name argument. If a match is found, the function returns 
a pointer to the value of that environment variable (i.e. everything 
after the = sign).
If no match is found, the function returns NULL.
*/
char	*ft_getenv(const char *name, char **env)
{
    if (!name || !env)
        return (NULL);
    while (*env)
    {
        if (ft_strncmp(name, *env, ft_strlen(name)) == 0 &&
            (*env)[ft_strlen(name)] == '=')
            return (*env + ft_strlen(name) + 1);
        env++;
    }
    return (NULL);
}
/*
This implementation first calculates the length of the env array
by counting the number of elements until a NULL value is found. 
It then allocates a new string array with room for an extra element, 
copies each element of the env array into the new array using ft_strdup, 
and adds the new string str to the end of the new array.
Note that this implementation also frees the old env array using a helper 
function free_str_array.
*/

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
