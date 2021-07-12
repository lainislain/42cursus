/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 04:08:24 by amaghat           #+#    #+#             */
/*   Updated: 2019/10/19 04:17:58 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new;
	t_list		*res;
	t_list		*temp;

	if (!lst || !(new = ft_lstnew(f(lst->content))))
		return (NULL);
	res = new;
	temp = lst->next;
	while (temp)
	{
		if (!(new = ft_lstnew(f(temp->content))))
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, new);
		temp = temp->next;
	}
	return (res);
}
