/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljennife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 18:08:59 by ljennife          #+#    #+#             */
/*   Updated: 2020/08/27 18:34:27 by ljennife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *lst;

	lst = malloc(sizeof(t_list));
	lst -> data = data;
	lst -> next = NULL;
	return(lst);
}

t_list	*ft_list_last(t_list *begin_list)
{
	if (begin_list == NULL)
		return (NULL);
	while (begin_list -> next != NULL)
	{
		begin_list = begin_list -> next;
	}
	return (begin_list);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *lst;
	t_list *tmp;

	lst = ft_list_last(begin_list);
	tmp = ft_create_elem(data);
	lst -> next = tmp;
}
