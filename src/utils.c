/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:39:00 by kbeceren          #+#    #+#             */
/*   Updated: 2023/03/07 12:49:05 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	error_message(char *message, int code)
{
	int	len;

	len = ft_strlen(message);
	g_error = code;
	write(2, message, len);
	write(2, "\n", 1);
}

char	*join_the_split(char **split)
{
	int		i;
	char	*copy;
	char	*str;

	i = 0;
	str = "";
	while (split[i])
	{
		copy = ft_strjoin(str, split[i]);
		if (!copy)
			exit(EXIT_FAILURE);
		str = copy;
		free(copy);
		i++;
	}
	return (str);
}

int	is_only_space(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'
		|| line[i] == '\v' || line[i] == '\f' || line[i] == '\r')
		i++;
	if (i == ft_strlen(line))
		return (1);
	return (0);
}
