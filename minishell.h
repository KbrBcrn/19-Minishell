/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:21:05 by kbeceren          #+#    #+#             */
/*   Updated: 2023/02/23 13:00:37 by kbeceren         ###   ########.fr       */
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
	char	*env;
	char	*current_pwd;
	t_list	*new_env;
	int		len_env;
}	t_data;

void	ft_init_env(t_data *data, t_list **new_env, char **envp);
void	ft_env(t_list *env);
char	*get_shlvl(t_list *env, char *name);
#endif