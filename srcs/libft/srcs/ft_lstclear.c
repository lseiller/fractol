/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:24:46 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/09 01:09:17 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list_l **lst, void (*del)(void*))
{
	t_list_l	*tmp_list;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp_list = *lst;
		*lst = (*lst)->next;
		if (del)
			del(tmp_list->content);
		free(tmp_list);
	}
	*lst = NULL;
}
