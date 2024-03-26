/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:50:29 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/22 14:51:20 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "stdio.h"
// REMOVE STDIO.H

/* static char	intdec_to_hexchar(int	i)
{
	if (i >= 0 && i <= 9)
		i = i + '0';
	else if (i >= 10 && i <= 15)
		i = i + 87;
	return ((char)i);
}

int	ft_printf_x(int	dx)
{
	int		i;
	int		dec;
	int		temp;
	char	output[20];

	i = 0;
	dec = dx;
	ft_bzero(output, 20);
	while (dec != 0)
	{
		temp = dec % 16;
		output[i] = intdec_to_hexchar(temp);
		dec /= 16;
		i++;
	}
	temp = ft_strlen(output);
	while (i--)
			ft_putchar_fd(output[i], 1);
	return (temp);
} */

int print_selected(char c, va_list args)
{
	if (c == 'c')
		return (ft_printf_c(va_arg(args, int)));
	if (c == 's')
		return (ft_printf_s(va_arg(args, char*)));
	if (c == 'p')
		return (ft_printf_p(va_arg(args, void*)));
	if (c == 'd' || c == 'i')
		return(ft_printf_d(va_arg(args, int)));
	if (c == 'u')
		return (ft_printf_u(va_arg(args, unsigned int)));
	// if (c == 'x');
	// 	return (1);
	// if (c == 'X');
	// 	return (1);
	else
		return (0);
}
// Our implementation of %i tells us just use base 10

int	ft_printf(const char *str, ...)
{
	int		i;
	int		rtn;
	va_list args;

	i = 0;
	rtn = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
			rtn += print_selected(str[++i], args);
		else if (str[i])
		{
			ft_putchar_fd(str[i], 1);
			rtn++;
		}
		i++;
	}
	va_end(args);
	return (rtn);
}

/* int	main(void)
{
	char	c = 'a';
	char	str[] = "hello";
	void	*ptr;
	int		nbr;
	char	input_text[] = "%x";
	int		j;
	
	j = 0;
	nbr = -2;
	ptr = &c;
	j = ft_printf(input_text, nbr);
	printf("\n%d\n", j);
	j = printf(input_text, nbr);
	printf("\n%d", j);
} */
// if NULL is found in string have it print (null)
// %d assumes base 10 while %i autodetects the base 012
// Base 10 if the number doesn’t start with 0 or 0x.
// Base 8 (octal) if the number starts with 0.
// Base 16 (hexadecimal) if the number starts with 0x or 0X.
// test for %%d
//having more definers than arguments is undefined
//search for % then send char and arg to input select
//return strlen of the outputted text;
//'\0' stops printf but %c '\0' doesnt;
//each call to va_arg advances the list;
//data_type variable = va_arg(args, data_type);
//int value = va_arg(args, int);

//use ft_split to seperate each section then have it check
//the first char of each seperated piece

//0x12