/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:44:21 by kbeceren          #+#    #+#             */
/*   Updated: 2023/03/08 13:15:35 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*reader(t_data *data)
{
	char	*line;

	(void)data;
	sig_handler(1);
	term_config();
	line = readline("minishell$ ");
	if (!line)
	{
		printf("exit\n");
		exit(0);
	}
	if (*line == '\0')
		return (NULL);
	add_history(line);
	return (line);
}
