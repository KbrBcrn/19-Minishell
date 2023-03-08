/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:40:07 by kbeceren          #+#    #+#             */
/*   Updated: 2023/03/08 10:49:24 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_metachar(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

void	activate_s_quote(t_data *data, char c)
{
	if (c == '\'' && data->s_quote == 0 && data->d_quote == 0)
		data->s_quote = 1; //1 if c is a single quote character 
	else if (c == '\'' && data->s_quote == 1)//deactivate the quote.
		data->s_quote = 0;
}

void	activate_d_quote(t_data *data, char c)
{
	if (c == '"' && data->d_quote == 0 && data->s_quote == 0)
		data->d_quote = 1;
	else if (c == '"' && data->d_quote == 1)
		data->d_quote = 0;
}

int	check_quote(t_data *data, char c)
{
	activate_s_quote(data, c);
	activate_d_quote(data, c);
	if (data->s_quote == 1 || data->d_quote == 1)
		return (1);//indicates that c is inside a quoted string. Otherwise, it returns 0.
	return (0);
}

void	clear_quote(t_data *data)
{
	data->s_quote = 0;
	data->d_quote = 0;
}
