/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:08:05 by aabda             #+#    #+#             */
/*   Updated: 2023/03/11 23:20:27 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_double_quotes(t_data *data)
{
	//	need to add a check for all exeptions (backslash,...) 
	//	and maybe put all in a new struct ?
	char	*between_quote;
	int		first_quote;
	int		last_quote;
	int		i;

	first_quote = 0;
	i = -1;
	while (data->line && data->line[++i])
	{
		if (data->line[i] != '"')
			first_quote++;
		if (data->line[i] == '"')
			break ;
	}
	last_quote = first_quote + 1;
	i = first_quote;
	while (data->line && data->line[++i])
	{
		if (data->line[i] != '"')
			last_quote++;
		if (data->line[i] == '"')
			break ;
	}
	if (data->line[first_quote] != '"' || data->line[last_quote] != '"') // If the string doesn't have double quote
		return (NULL);
	between_quote = ft_substr(data->line, first_quote + 1, (last_quote - 1) - first_quote);
	return (between_quote);
}

int	parser(t_data *data)
{
	char	*test;

	test = ft_double_quotes(data);
	// exit(EXIT_FAILURE);
	printf("%s\n", test);
	return (0);
}
