# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/15 08:04:18 by abelarif          #+#    #+#              #
#    Updated: 2021/10/12 16:39:52 by amaghat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=minishell

MINISHELL_SRCS=			./main.c\
						./minishell.c\

LIBFT_SRCS=				./libft/ft_split.c\
						./libft/ft_strlen.c\
						./libft/ft_strdup.c\
						./libft/ft_strchr.c\
						./libft/ft_substr.c\
						./libft/ft_strjoin.c\
						./libft/ft_strlcpy.c\
						./libft/ft_strncmp.c\
						./libft/ft_putstr_fd.c\
						./libft/ft_putnbr_fd.c\
						./libft/ft_putchar_fd.c\
						./libft/ft_putendl_fd.c\
						./libft/ft_strcmp.c\
						./libft/ft_atoi.c\
						./libft/ft_itoa.c\
						./libft/ft_isalpha.c\

BUILTINS_SRCS=			./builtins/set_env.c\
						./builtins/buil_cd.c\
						./builtins/buil_pwd.c\
						./builtins/buil_env.c\
						./builtins/buil_exit.c\
						./builtins/buil_echo.c\
						./builtins/buil_unset.c\
						./builtins/buil_export.c\
						./builtins/buil_export_utils.c\

EXECUTION_SRCS=			./execution/exec_path.c\
						./execution/execution.c\
						./execution/input_output_dup.c\
						./execution/execute_line.c\
						./execution/simple_builtin.c\
						./execution/heredocs.c\
						./execution/init_pipes.c\

LINE_READER_SRCS=		./line_reader/import_line.c\


PARSING_SRCS=			./parsing/extraction.c\
						./parsing/replace_dollar.c\
						./parsing/extract_tokens.c\
						./parsing/tokens_handling.c\
						./parsing/expand_quotes.c\

UTILS_SRCS=				./utils/max_of.c\
						./utils/ft_errors.c\
						./utils/tokens_utils.c\
						./utils/env_handling.c\
						./utils/split_by_index.c\
						./utils/grammar_checker.c\
						./utils/backslash_handling.c\
						./utils/line_handler_utils.c\
						./utils/abs_value.c\
						./utils/line_execution_errors.c\
						./utils/free_execution.c\
						./utils/tokens_utils2.c\
						./utils/dollar_utils.c\
						./utils/ft_charjoin.c\
						./utils/is_builtin.c\
						./utils/type_identifier.c\
						./utils/add_env.c\
						

SRCS=					$(LIBFT_SRCS)\
						$(UTILS_SRCS)\
						$(PARSING_SRCS)\
						$(EXECUTION_SRCS)\
						$(MINISHELL_SRCS)\
						$(LINE_READER_SRCS)\
						$(BUILTINS_SRCS)\

OBJS=					$(SRCS:.c=.o)

FLAGS=					-Wall -Werror -Wextra \
						-lreadline\
					   	-L /goinfre/amaghat/.brew/opt/readline/lib \
						-I /goinfre/amaghat/.brew/opt/readline/include
$(NAME): $(OBJS)
		gcc -g3 $(FLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
