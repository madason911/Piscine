/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljennife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:05:47 by ljennife          #+#    #+#             */
/*   Updated: 2020/08/27 15:15:54 by ljennife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int i;

	i = 0;
	t_list *lst;

	lst = begin_list;
	while (lst != NULL)
	{
		i++;
		lst = lst -> next;
	}
	return (i);
}
