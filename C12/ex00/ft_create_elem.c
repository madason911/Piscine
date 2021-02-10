/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljennife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:17:42 by ljennife          #+#    #+#             */
/*   Updated: 2020/08/27 13:14:10 by ljennife         ###   ########.fr       */
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
