/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:21:05 by kbeceren          #+#    #+#             */
/*   Updated: 2023/03/04 16:50:48 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>

# define MAX_SHLVL 1000

typedef struct s_data
{
	char	*path;
	char	**new_env;
	char	*current_pwd;
	char	*shlvl;
}	t_data;

char	**ft_init_env(t_data *data, char **envp);
char	**remove_env_var(char *var, char **env);
char	*ft_getenv(const char *name, char **env);
char	**env_add(char *str, char **env);
char	**update_pwd(char **envp);

char	**increment_shell_level(t_data *data, char **env);

#endif