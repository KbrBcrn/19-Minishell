/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:20:08 by kbeceren          #+#    #+#             */
/*   Updated: 2023/03/07 11:28:25 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	syntax_error(char c, char c2, char *s, int code)
{
	g_error = code;
	write(2, "syntax error near unexpected token `", 36);
	if (c)
		write(2, &c, 1);
	if (c2)
		write(2, &c2, 1);
	if (s)
		write(2, s, ft_strlen(s));
	write(2, "'\n", 2);
}

void	check_seperators(t_data *data, char *line)
{
	int	i;
	int	nb_pipe;

	i = 0;
	nb_pipe = 0;
	while (line[i])
	{
		if (!check_quote(data, line[i]) && is_metachar(line[i]))
		{
			nb_pipe++;
			if (nb_pipe == 3
				|| (nb_pipe == 2 && line[i] != line[i - 1]))
			{
				if (is_metachar(line[i + 1]))
					syntax_error(line[i], line[i + 1], 0, 258);
				else
					syntax_error(line[i], 0, 0, 258);
				break ;
			}
		}
		if (ft_isalnum(line[i]))
			nb_pipe = 0;
		i++;
	}
}

void	begin_end_with_separator(char *line)
{
	int		max;
	char	*str;
	char	**split;

	if (g_error)
		return ;
	split = ft_split(line, ' ');
	if (!split)
		exit(EXIT_FAILURE);
	str = join_the_split(split);
	if (line[0] == '|')
		syntax_error(line[0], 0, 0, 258);
	max = ft_strlen(str) - 1;
	if (is_metachar(str[max]))
		syntax_error(0, 0, "newline", 258);
	else if (str[max - 1] && (str[max - 1] == '<'
			|| str[max - 1] == '>') && is_metachar(str[max]))
		syntax_error(str[max], 0, 0, 258);
	//free_split(split);
}

int	check_syntax(t_data *data)
{
	int	save;

	save = g_error;
	g_error = 0;
	check_seperators(data, data->line);
	if (check_quote(data, 'c'))
		error_message("syntax error near unexpected token `quote'", 258);
	clear_quote(data);
	begin_end_with_separator(data->line);
	if (g_error == 258)
		return (0);
	g_error = save;
	return (1);
}
