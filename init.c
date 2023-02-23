/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:25:35 by kbeceren          #+#    #+#             */
/*   Updated: 2023/02/23 13:09:42 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_env(t_data *data, t_list **new_env, char **envp)
{
	int		i;

	i = 0;
	while (envp[data->len_env])
		data->len_env++;
	while (i < data->len_env)
	{
		ft_lstadd_back(new_env, ft_lstnew(envp[i]));
		i++;
	}
}



/* get_shvl is used to obtain the value of the SHLVL environment variable, 
which indicates the nesting level of the shell process. 
The value of SHLVL is incremented each time a new shell process is created.
Function returns a pointer to the value of the environment variable
(which starts after the equals sign).
*/

char	*get_shlvl(t_list *env, char *name)
{
	char	*content;
	int		len_name;

	len_name = ft_strlen(name);
	while (env)
	{
		content = (char *) env->content;
		if (!ft_strncmp(name, content, len_name) && content[len_name] == '=')
			return (content + len_name + 1); 
		env = env->next;
	}
	return (NULL);
}

// void	ft_env(t_list *env)
// {
// 	while (env)
// 	{
// 		printf("%s\n", env->content);
// 		env = env->next;
// 	}
// }