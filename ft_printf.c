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
// REMOVE

int print_selected(char c, void *arg)
{
	if (c == 'c')
		return (ft_printf_c(*(char*) &arg));
	if (c == 's')
		return (ft_printf_s((char*)arg));
	if (c == 'p')
		return (ft_printf_p((void*)arg));
	// if (c == 'd')
	// 	return(ft_printf_d(*(int*)arg));
	// if (c == 'i')
	// 	return(ft_printf_d(*(int*)arg));
	// if (c == 'u');
	// 	return (ft_printf_u(*(unsigned int*)arg));
	// if (c == 'x');
	// 	return (1);
	// if (c == 'X');
	// 	return (1);
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else
		return (0);
}

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
		{
			i++;
			rtn += print_selected(str[i], va_arg(args, void*));
		}
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

int	main(void)
{
	char	c = 'a';
	char	str[] = "\nwow,\nthats\0 cool";
	void	*ptr;
	int		nbr = 10;
	char	input_text[] = "%u";
	int		j;
	
	ptr = &c;
	j = ft_printf(input_text, nbr);
	printf("\n%d\n", j);
	j = printf(input_text, nbr);
	printf("\n%d", j);
}
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