/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:55:03 by kbeceren          #+#    #+#             */
/*   Updated: 2023/03/10 13:13:54 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	term_config(void)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &term);
}

void	restore_prompt(int sig)
{
	g_error = INTERRUPTED;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	(void)sig;
}

void	ctrl_c(int sig)
{
	g_error = INTERRUPTED;
	write(1, "^C\n", 3);
	(void)sig;
}

void	back_slash(int sig)
{
	g_error = QUIT;
	printf("^\\Quit : 3\n");
	(void)sig;
}

void	sig_handler(int signum)
{
	if (signum == 1)
	{
		signal(SIGINT, restore_prompt);
		signal(SIGQUIT, SIG_IGN);
	}
	if (signum == 2)
	{
		signal(SIGINT, ctrl_c);
		signal(SIGQUIT, back_slash);
	}
}
