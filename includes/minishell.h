/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:21:05 by kbeceren          #+#    #+#             */
/*   Updated: 2023/03/10 13:51:49 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <stdbool.h>
# include <fcntl.h>
# include <signal.h>

int						g_error;
typedef struct s_list	t_list;

typedef struct s_data
{
	char	*path;
	char	**new_env;
	char	*current_pwd;
	char	*shlvl;
	char	*line;
	bool	s_quote;
	bool	d_quote;
	int		count_cmd;
}	t_data;

enum e_fd
{
	infile,
	outfile
};

enum e_error
{
	FILE_ERROR = 1,
	INTERRUPT_NL = 1,
	NOT_EXECUTABLE = 126,
	COMMAND_NOT_FOUND = 127,
	INTERRUPTED = 130,
	QUIT = 131,
	SYNTAX_ERROR = 258
};

char	**ft_init_env(t_data *data, char **envp);
char	**remove_env_var(char *var, char **env);
char	*ft_getenv(const char *name, char **env);
char	**env_add(char *str, char **env);
char	**update_pwd(char **envp);

char	**increment_shell_level(t_data *data, char **env);
char	*reader(t_data *data);
void	sig_handler(int signum);
int		check_syntax(t_data *data);
void	begin_end_with_separator(char *line);
void	check_seperators(t_data *data, char *line);
void	syntax_error(char c, char c2, char *s, int code);
void	error_message(char *message, int code);
int		check_quote(t_data *data, char c);
int		is_metachar(char c);
void	clear_quote(t_data *data);
void	term_config(void);
char	*join_the_split(char **split);
int		is_only_space(char *line);
void	rl_replace_line(const char *text, int clear_undo);

#endif