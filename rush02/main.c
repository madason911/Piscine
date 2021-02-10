#include <unistd.h>
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

void    ft_putstr(char *str)
{
    while(*str != '\0')
    {
        write(1, str, 1);
        str++;
    }
}

int		ft_isspace(char str)
{
	if ((str == ' ') || (str == '\t') || (str == '\n'))
	{
		return (1);
	}
	else if ((str == '\v') || (str == '\f') || (str == '\r'))
	{
		return (1);
	}
	return (0);
}

int		ft_atoi(char *str)
{
	int i;
	int atoi;

	atoi = 0;
	i = 0;
	while (ft_isspace(*str) == 1)
	{
		str++;
	}
	while ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
		{
			i++;
		}
		str++;
	}
	while ((*str >= 48) && (*str <= 57))
	{
		atoi = atoi * 10 + (*str - 48);
		str++;
	}
	return (i % 2 == 0 ? atoi : -atoi);
}

int ft_power_dec(int pow)
{
    int i;

    i = 1;
    while (pow > 0)
    {
        i *= 10;
        pow--;
    }
    return (i);
}

int  ft_nbrlen(int nbr)
{
    int i;

    i = 0;
    while (nbr > 0)
    {
        i++;
        nbr = nbr / 10;
    }
    return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0') || (*s2 != '\0'))
	{
		if (*s1 > *s2)
		{
			return (1);
		}
		else if (*s1 < *s2)
		{
			return (-1);
		}
		else
		{
			s1++;
			s2++;
		}
	}
	return (0);
}

// int ft_lensmp(int current_len, char **ar)
// {
//     int i;
//     int j;

//     i = 0;
//     j = 0;
//     while (ar[i])
//     {
//         if(current_len)
//     }
// }

// void    ft_putmass(char **ar)
// {
//     int i;
//     int j;

//     j = 0;
//     i = 0;
//     ar = malloc();
//     while ( != '\0')
// }


// int ft_str_search(char *str)
// {
//     int  i;

//     i = 0;
//     while
// }

int main(int argc, char **argv)
{
    char *single_digits[] = { "zero", "one", "two",  
                               "three", "four","five",  
                               "six", "seven", "eight", "nine"}; 

    char *two_digits[] = {"ten", "eleven", "twelve",  
                               "thirteen", "fourteen", 
                               "fifteen", "sixteen",  
                               "seventeen", "eighteen", "nineteen"}; 

    char *tens_multiple[] = {"", "", "twenty", "thirty", "forty", "fifty", 
                            "sixty", "seventy", "eighty", "ninety"}; 
  
    char *tens_power[] = {"hundred", "thousand"};

    char *single_digits_nbr[] = { "0", "1", "2",  
                               "3", "4","5",  
                               "6", "7", "8", "9"}; 

    char *two_digits_nbr[] = {"10", "11", "12",  
                               "13", "14", 
                               "15", "16",  
                               "17", "18", "19"}; 

    char *tens_multiple_nbr[] = {"", "", "20", "30", "40", "50", 
                            "60", "70", "80", "90"}; 
  
    char *tens_power_nbr[] = {"100", "1000"};

    char *the_most[] = {"million", "billion", "trillion"};

    char nbr[] = "109012";
    char th[4];
    int c = 0;
    int k = 0;
    int j = 2;
    int i = ft_strlen(nbr) - 1;
    th[3] = '\0';
    while (j >= 0)
    {
        th[j] = nbr[i];
        i--;
        j--;
    }
    i = ft_strlen(nbr) - 1;
    while (k < 3)
    {
        nbr[i] = 0;
        i--;
        k++;
    }
    // j = 2;
    while (nbr[i])
    {
        if (ft_strlen(th) == 1)
        {
            // if (th[i] == '0')
            //     con
            ft_putstr(single_digits[ft_atoi(th)]);
            th[i] = '\0';
        }
        else if (ft_strlen(th) == 2 && ft_strcmp(th, "20") == -1)
        {
            ft_putstr(two_digits[ft_atoi(th) % 10]);
            return 0;
        }
        else if (ft_strlen(th) == 2)
        {
            ft_putstr(tens_multiple[ft_atoi(th) / 10]);
            ft_putstr(" ");
            if (ft_atoi(th) % 10 == 0)
                return 0;
            th[i - 1] = th[i];
            th[i] = '\0';
            i--;
        }
        else
        {
            ft_putstr(single_digits[ft_atoi(th) / ft_power_dec(ft_strlen(th) - 1)]);
            ft_putstr(" ");
            ft_putstr(tens_power[ft_strlen(th) - 3]);
            ft_putstr(" ");
            if (ft_atoi(th) % ft_power_dec(ft_strlen(th) - 1) == 0)
                return (0);
            if (ft_strlen(th) == 3)
            {
                th[i - 2] = th[i - 1];
                th[i - 1] = th[i];
                th[i] = '\0';
            }
            else
            {
                th[i - 3] = th[i - 2];
                th[i - 2] = th[i - 1];
                th[i - 1] = th[i];
                th[i] = '\0';
            }
            while (th[i] == '0')
                i--;
            i--;
        }
        c++;
        while (j >= 0)
        {
            th[j] = nbr[i];
            i--;
            j--;
        }
        i = ft_strlen(nbr) - 1;
        while (k < 3)
        {
            nbr[i] = 0;
            i--;
            k++;
        }
    }
    // ft_putstr("\n");
    // write(1, &th[2], 1);
    // while (nbr[i])
    // {
    //     if (ft_strlen(nbr) == 1)
    //     {
    //         ft_putstr(single_digits[ft_atoi(nbr)]);
    //         nbr[i] = '\0';
    //     }
    //     else if (ft_strlen(nbr) == 2 && ft_strcmp(nbr, "20") == -1)
    //     {
    //         ft_putstr(two_digits[ft_atoi(nbr) % 10]);
    //         return 0;
    //     }
    //     else if (ft_strlen(nbr) == 2)
    //     {
    //         ft_putstr(tens_multiple[ft_atoi(nbr) / 10]);
    //         ft_putstr(" ");
    //         if (ft_atoi(nbr) % 10 == 0)
    //             return 0;
    //         nbr[i - 1] = nbr[i];
    //         nbr[i] = '\0';
    //         i--;
    //     }
    //     else if (ft_strlen(nbr) <= 4)
    //     {
    //         ft_putstr(single_digits[ft_atoi(nbr) / ft_power_dec(ft_strlen(nbr) - 1)]);
    //         ft_putstr(" ");
    //         ft_putstr(tens_power[ft_strlen(nbr) - 3]);
    //         ft_putstr(" ");
    //         if (ft_atoi(nbr) % ft_power_dec(ft_strlen(nbr) - 1) == 0)
    //             return (0);
    //         if (ft_strlen(nbr) == 3)
    //         {
    //             nbr[i - 2] = nbr[i - 1];
    //             nbr[i - 1] = nbr[i];
    //             nbr[i] = '\0';
    //         }
    //         else
    //         {
    //             nbr[i - 3] = nbr[i - 2];
    //             nbr[i - 2] = nbr[i - 1];
    //             nbr[i - 1] = nbr[i];
    //             nbr[i] = '\0';
    //         }
    //         while (nbr[i] == '0')
    //             i--;
    //         i--;
    //     }
    //     else 
    //     {
    //         ft_putstr()
    //     }
    // }
    // int nbr = 9000;
    // int del = 0
    // while (nbr > 0)
    // {
    //     del = nbr % 100;
    //     while (del > 0)
    //     {
    //         if (ft_nbrlen(del) == 1)
    //         {
    //             ft_putstr(single_digits[del]);
    //             return 0;
    //         }
    //         else if (ft_nbrlen(del) == 2 && del < 20)
    //         {
    //             ft_putstr(two_digits[del % 10]);
    //             return 0;
    //         }
    //         else if (ft_nbrlen(del) == 2)
    //         {
    //             ft_putstr(tens_multiple[del / 10]);
    //             del = del % 10;
    //         }
    //         else
    //         {
    //             ft_putstr(single_digits[del / (ft_power_dec(ft_nbrlen(del) - 1))]);
    //             ft_putstr(tens_power[ft_nbrlen(del) - 3]);
    //             del = del % ft_power_dec(ft_nbrlen(del) - 1);
    //         }
    //     }
    //     nbr = nbr 
    // }


    return 0;
}