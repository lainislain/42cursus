/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:41:44 by abelarif          #+#    #+#             */
/*   Updated: 2021/10/12 17:18:56 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <signal.h>
# include <sys/errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft/libft.h"

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

# define STDIN  0
# define STDOUT 1
# define STDERR 2

# define CMD        9001
# define ARG        9002
# define REDO0		9003
# define REDO1		9004
# define REDI0		9005
# define REDI1		9006
# define FILE		9007
# define ERROR		9008
# define PROTECTED0	9009
# define PROTECTED1	9010
# define SKIPED		9011
# define HEREDOC	9012
# define EOFHEREDOC	9013

# define BS_ERR		"This Shell does not support unspecified \
					special characters \"\\\""

typedef struct s_quote
{
	bool				s_quote;
	bool				d_quote;
}						t_quote;

typedef struct s_env
{
	char				**env;
	char				**sorted;
	int					exit_status;
	int					child_flag;
}						t_env;

typedef struct s_tokens
{
	int					nb;
	int					pipe;
	int					*type;
	char				**tokens;
}						t_tokens;

typedef struct s_separator
{
	int					*separator_index;
	int					nb_separator;
	char				**content;
}						t_separator;

typedef struct s_execution
{
	int					nb_pipelines;
	int					*args_type;
	int					*files_type;
	int					*fds;
	char				**args;
	char				**files;
	char				*exec_path;
	char				*command;
}						t_execution;

typedef struct s_data
{
	int			presence;
	int			oldlen;
	int			newlen;
}				t_data;

t_env					g_env;

int				*init_pipes(int nb_pipes);
int				is_empty(char *str);
int				is_redirection(int type);
int				is_arg(int type);
int				is_cmd(int type);
int				is_input_redir(int file_type);
int				get_end(char *line, int index);
int				is_output_redir(int file_type);
int				count(char **str);
int				skip_spaces(char *line, int index);
int				dollar_len(char *str, int index);
int				token_quotes(char *line, int index);
int				token_word(char *line, int index);
int				token_redir(char *line, int index);
int				token_dollar(char *line, int index);
int				max_of(int i, int j);
int				is_protected(int type);
int				count_bslash(char *line);
int				count_tokens(char *line);
int				bs_position(char **tokens);
int				*set_tok_types(t_tokens tok);
int				count_bs(char *line, int index);
int				*get_bslash_index(char *line, int nb);
int				ft_error(char *description, int exitstat);
int				grammar_checker(char **commands, t_tokens *tokens);
int				empty_line(char *line);
int				count_arr(char **arr);
int				abs_value(int nb);
int				builtin_exit(char **args, int is_a_child_process, int counter);
int				builtin_env(void);
int				builtin_cd(char **path);
int				builtin_echo(char **args, int *types);
int				builtin_unset(char **args);
int				simple_builtin(t_execution *execution, int exit_flag);
int				*get_fds_files(int index, t_execution *execution);
int				check_redirections_errors(int index, t_execution *execution);
int				get_fd(int index, t_execution *execution, int i);
int				builtin_export(char **args, int *types);
int				*get_execution_types(t_tokens tokens);
int				*get_execution_files_type(t_tokens tokens);
int				is_wrong_arg(char *arg);

void			sort_env(void);
void			terminal_view(void);
void			clear_window(void);
void			init_env(char **env);
void			no_such_file_error(char *command);
void			command_not_found_error(char *command);
void			free_dollar(char **old, char **content);
void			close_all_fds(int *pipes, int nb_pipes);
void			free_execution(t_execution *execution);
void			free_toks(t_tokens tok);
void			execution(t_tokens *tokens);
void			extract_tokens(char **commands);
void			extract_semicolon_line(char *line);
void			dollar_handling(char **tok, int index);
void			expand_quotes_dollar(t_tokens *tokens);
void			set_separator_type(int *type, char **toks);
void			minishell(int argc, char *argv[], char *envp[]);
void			free_arr(char **arr);
void			heredocs_parsing(t_execution *execution);
void			dup_in_out(int index, int *pipes, t_execution *execution);
void			create_childs(t_execution *execution);
void			export_add_env(char *var, char *value);
void			join_bs(char **paths);
void			print_export_errors(char **args);

char			*prompt(void);
char			*read_line(void);
char			**get_paths(void);
char			*builtin_pwd(int descriptor);
char			**split_tok(char *line, int nb);
char			*get_token(char *line, int flag);
char			*is_builtin(char *cmd);
char			*ft_charjoin(char *str, char c);
char			*sub_dollar(char *str, int index);
char			**set_env(char *variable, char *value);
char			*get_exec_path(t_tokens token, char **paths);
char			**splitSep(char *line, int *sepIndex, int nbSep);
char			**join_args(char **args, int *types);
char			*env_search(char *str, int index);
char			**get_execution_args(t_tokens tokens, char *command);
char			**get_execution_files(t_tokens tokens);

t_quote			init_quote(void);
t_quote			set_quote_value(char quote_type, t_quote to_quote);
t_tokens		replace_dollar(t_tokens *tok);
t_separator		get_separator_index(char *line, char separator_type);
t_execution		*execute_line(t_execution *execution);

#endif
