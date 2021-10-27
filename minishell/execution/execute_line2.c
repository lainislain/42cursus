/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_line2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:06:12 by abelarif          #+#    #+#             */
/*   Updated: 2021/10/12 17:09:30 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_input_redir(int file_type)
{
	if (abs_value(file_type) == REDI0)
		return (1);
	if (abs_value(file_type) == HEREDOC)
		return (1);
	return (0);
}

int	is_output_redir(int file_type)
{
	if (abs_value(file_type) == REDO0)
		return (1);
	if (abs_value(file_type) == REDO1)
		return (1);
	return (0);
}
