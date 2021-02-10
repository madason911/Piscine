/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_staff.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljennife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 19:49:32 by ljennife          #+#    #+#             */
/*   Updated: 2020/09/01 22:27:34 by ljennife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_STAFF_H
# define PARSER_STAFF_H

int		is_printable(char str);
int		is_numeric(char str);
int		is_box(char str);
int		join_box(char tmp, t_dict dict, t_box **line, int size);
int		str_to_box(char *str, t_dict dict, t_box **line, int size);
t_box	ctob(char a, t_dict dict);

#endif
