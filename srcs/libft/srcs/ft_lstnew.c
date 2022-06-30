/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:27:07 by lseiller          #+#    #+#             */
/*   Updated: 2022/06/06 14:17:12 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_l	*ft_lstnew(void *content)
{
	t_list_l	*list;

	list = ft_calloc(1, sizeof(t_list_l));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
