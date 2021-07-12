/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 04:06:00 by amaghat           #+#    #+#             */
/*   Updated: 2019/10/19 04:06:41 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list		*loop;
	t_list		*temp;

	loop = *lst;
	while (loop)
	{
		del(loop->content);
		temp = loop->next;
		free(loop);
		loop = temp;
	}
	(*lst) = NULL;
}
