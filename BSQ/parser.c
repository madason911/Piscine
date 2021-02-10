/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljennife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 19:47:58 by ljennife          #+#    #+#             */
/*   Updated: 2020/09/01 22:27:36 by ljennife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map_def.h"

t_map             *try_parse_map(int d_input)
{
    int status;
    t_map map;

    status = 0;
    map = malloc(sizeof(t_map));
    if (map == NULL)
        return (NULL);
    status = try_parse_first_line(d_input, &map);
    if (status != 1)
    {
        free(map);
        return (NULL);
    }
    status = try_parse_second_line(d_input, &map);
    if (status != 1)
    {
        free(map);
        return (NULL);
    }
    status = try_parse_other_lines(d_input, &map);
    if (status != 1)
    {
        free(map);
        return (NULL);
    }
    return (&map);
}

int	try_parse_first_line(int d_input, t_map *map)
{
    char	tmp[4];
    int		number;
	int		i;
	int		f;

	f = 1;
	i = 0;
	while (f > 0 && i < 4)
	{
		read(d_input, tmp[i], 1);
		if (tmp[i] == '\n' || !(is_printable(tmp[i])))
			return (-1);
		i++;
	}
	number = 0;
	while (tmp[3] != '\n')
	{
		if (!(is_numeric(tmp[0])))
			return (-1);
		number = number * 10 + tmp[0] - '0';
		tmp[0] = tmp[1];
		tmp[1] = tmp[2];
		tmp[2] = tmp[3];
		read(d_input, tmp[3], 1);
		if (!(is_printable(tmp[i])))
			return (-1);
	}
	if (number == 0)
		return (-1);
	map->size_h = number;
	map->dictionary.empty_char = tmp[0];
	map->dictionary.obstacle_char = tmp[1];
	map->dictionary.full_char = tmp[2];
	//identical chars CHECK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	return (1);
}

int	try_parse_second_line(int d_input, t_map *map)
{
	int c;
	t_box *line;
	char tmp;

	line = 0;
	c = 0;
	read(d_input, &tmp, 1);
	while (tmp != '\n')
	{
		if (!(is_box(tmp, map->dictionary)))
			return (-1);
		join_box(tmp, map->dictionary, &line, c);
		c++;
		read(d_input, &tmp, 1);
	}
	if (c == 0)
		return (-1);
	map->size_w = c;
	map->field = &line;
	return (1);

}

int	try_parse_other_lines(int d_input, t_map *map)
{
	t_box	*tmp_line;
	int		i;
	char	*tmp;

	tmp_line = *(map->field);
	map->field = malloc(sizeof(t_box *) * size_h);
	map->field[0] = tmp_line;
	i = 1;
	tmp = malloc(sizeof(char) * map->size_w);
	while (i < size_h)
	{
		tmp_line = NULL;
		if (read(d_input, tmp, map->size_w) != map->size_w)
			return (-1);
		if (str_to_box(tmp, map->dictionary, &tmp_line, map->size_w) == -1)
			return (-1);
		read(d_input, tmp, 1);
		if (tmp[0] != '\n')
			return (-1);
		map->field[i] = tmp_line;
		i++;
	}
}
