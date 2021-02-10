/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljennife <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 12:27:48 by ljennife          #+#    #+#             */
/*   Updated: 2020/08/23 19:14:14 by ljennife         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int main(int argc, char **argv)
{
	int i;
	int j;
	int k;
	char arr_row[2][4];
	char arr_col[2][4];

	k = 0;
	j = 0;
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] >=48 && argv[1][i] <= 57)
		{
			if (k < 2)
				arr_row[k][j] = argv[1][i] - 48;
			else
				arr_col[k - 2][j] = argv[1][i] - 48;
			j++;
			//printf("J - %d", j);
			if (j % 4 == 0)
			{
				j = 0;
				k++;
			}
		}
		i++;
	}
	j = 0;
	i = 0;
	while (i < 2)
	{
		while (j < 4)
		{
			printf("%d ", arr_row[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
	printf("----------------------------------\n");
	while (i < 2)
	{
		while (j < 4)
		{
			printf("%d ", arr_col[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	return (0);
}

int def_row( char arr_col[2][4], char arr[4][4], int j, int l[4])
{
	int i;

	i = 0;
	if ((arr_col[i][j] == 3 && arr_col[i + 1][j] == 1) ||
			(arr_col[i][j] == 1 && arr_col[i + 1][j]))
		return (func3_1(arr, j, arr_col[i][j], l[j]));
	else if ((arr_col[i][j] == 4 && arr_col[i + 1][j] == 1) ||
			(arr_col[i][j] == 1 && arr_col[i + 1][j] == 4))
		return (func4_1(arr, j, arr_col[i][j]));
	else if (arr_col[i][j] == 2 && arr_col[i + 1][j] == 2)
		return (func2_2(arr, j, l[j]));
	else if ((arr_col[i][j] == 3 && arr_col[i + 1][j] == 2) ||
			(arr_col[i][j] == 2 && arr_col[i + 1][j] == 3))
		return (func3_2(arr, j, arr_col[i][j], l[j]));
	else if ((arr_col[i][j] == 2 && arr_col[i + 1][j]) == 1 ||
			(arr_col[i][j] == 1 && arr_col[i + 1][j] == 2))
		return (func2_1(arr, j, arr_col[i][j], l[j]));
	else
		return (-1);
}
