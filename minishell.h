/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:21:05 by kbeceren          #+#    #+#             */
/*   Updated: 2023/02/24 12:27:27 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_data
{
	char	*path;
	char	*line;
	char	**new_env;
	char	*current_pwd;
	int		len_env;
	int		shlvl;
}	t_data;

char	**ft_init_env(t_data *data, char **envp);
void	ft_env(t_list *env);
char	*get_shlvl(t_list *env, char *name);
#endif