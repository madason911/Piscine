#ifndef FT_MAP_DEF_H
# define FT_MAP_DEF_H

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>

typedef enum    e_box
{
    is_empty,
    is_obstacle,
    is_full,
	is_error
}               t_box;

typedef struct  s_dict
{
    char empty_char,
    char obstacle_char,
    char full_char
}               t_dict;

typedef struct  s_map
{
    t_box   **field,
    int     size_h,
    int     size_w,
    t_dict  dictionary
}               t_map;

int             try_parse_map(int d_input);
int             try_parse_first_line(int d_input, t_map *map);
int             try_parse_second_line(int d_input, t_map *map);
int             try_parse_other_lines(int d_input, t_map *map);
void            ft_putstr(char *str);
void            ft_putstr_error(char *str);
void            ft_put_map(t_map *map);

#endif
