#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_open_file(char **ar)
{
	int fd;

	fd = open(ar[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Dict Error\n", 11);
		return (0);
	}
	return (fd);
}

int ft_line_count(int fd)
{
	int i;
	char arr;

    i = 0;
	while (read(fd, &arr, 1) > 0)
	{
		if (arr == '\n')
			i++;
	}
	return(i);
}

int ft_sym_count(int fd)
{
    int i;
    char arr;

    i = 0;
    while ((read(fd, &arr, 1) > 0) && (arr != '\n'))
    {
        i++;
    }
    return (i);
}

int ft_sym_count_other(int fd, char **ar)
{
    int i;
    char arr;

    read(fd, &arr, ft_sym_count(fd) + 1);
    i = 0;
    while ((read(fd, &arr, 1) > 0) && (arr != '\n'))
    {
        i++;
    }
    return (i);
}

void	ft_map_stdin(void)
{
	int		n;
	char	arr;

	while ((n = read(0, &arr, 1)) > 0)
		write(1, &arr, 1);
	if (errno != 0)
	{
		return ;
	}
	errno = 0;
}


int main(int argc, char **argv)
{
    int fd;
    int byte;
    char **buf;
    char arr;
    char *first_line;
    int i;
    int j;

    j = 0;
    i = 0;
    fd = open(argv[1], O_RDONLY);
    // printf("%d\n", ft_line_count(ft_open_file(argv)));
    // printf("%d", ft_sym_count(ft_open_file(argv)));
    buf = malloc(sizeof(char *) * (ft_line_count(ft_open_file(argv)) - 1));
    first_line = malloc(sizeof(char) * ft_sym_count(ft_open_file(argv)));
    byte = read(fd, first_line, ft_sym_count(ft_open_file(argv)) + 1);
    // close(fd);
    // fd = open(argv[1], O_RDONLY);
    read(fd, buf, 1);
    ft_putstr(first_line);
    if (errno != 0)
    {
        return (0);
    }
    int c = ft_sym_count_other(fd, argv) + 1;
    while (i < ft_line_count(ft_open_file(argv)))
    {
        buf[i] = malloc(sizeof(char) * (c));
        read(fd, buf[i], (c));
        ft_putstr(buf[i]);
        i++;
    }
    // while (i < ft_line_count(ft_open_file(argv)))
    // {
    //     buf[i] = malloc(sizeof(char) * ft_sym_count(ft_open_file(argv)));
    //     while (j < ft_sym_count(ft_open_file(argv)))
    //     {
    //         while ((byte = read(fd, &arr, sizeof(arr))) > 0)
    //             buf[i][j] = arr;
    //         j++;
    //     }
    //     i++;
    //     j = 0;
    // }

    // i = 0;
    // j = 0;
    // while (i < ft_line_count(ft_open_file(argv)))
    // {
    //     while (j < ft_sym_count(ft_open_file(argv)))
    //     {
    //         write(1, &(buf[i][j]), 1);
    //         j++;
    //     }
    //     i++;
    //     j = 0;
    // }

}