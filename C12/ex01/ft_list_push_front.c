/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljennife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:24:39 by ljennife          #+#    #+#             */
/*   Updated: 2020/08/27 15:04:24 by ljennife         ###   ########.fr       */
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

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *lst;

	lst = ft_create_elem(data);
	lst -> data = data;
	lst -> next = begin_list;
	begin_list = &lst;	
}
