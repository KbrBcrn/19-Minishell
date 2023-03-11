# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabda <aabda@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 11:10:39 by kbeceren          #+#    #+#              #
#    Updated: 2023/03/10 14:11:02 by aabda            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC = 	src/main.c\
		src/init.c\
		src/reader.c\
		src/signals.c\
		src/syntax_utils.c\
		src/check_syntax.c\
		src/utils.c\
		src/env.c\
		src/env_utils.c\
		src/parser.c
		
INCLUDES = includes
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = gcc
$(RM) = rm -rf

all: libft $(NAME)

libft:
	@make -C ./libft
	
.c.o: $(SRC)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ -lreadline -L./libft -lft -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include

	
clean:
	make clean -C ./libft
	$(RM) $(OBJ)

fclean: clean
	rm -f libft/libft.a
	$(RM) $(NAME)

re: fclean all
.PHONY: all clean fclean re libft