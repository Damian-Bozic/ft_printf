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



int	ft_printf(const char *str, ...)
{
	int	i;
	char	**array;
	va_list args;

	i = 0;
	array = ft_splitmod(str, '%');
	va_start(args, str);

	return (i);
}
//return strlen of the outputted text;
//'\0' stops printf but %c '\0' doesnt;
//each call to va_arg advances the list;
//data_type variable = va_arg(args, data_type);
//int value = va_arg(args, int);

//use ft_split to seperate each section then have it check
//the first char of each seperated piece
int	main(void)
{
	#include "stdio.h"
	char	c = '\0';
	char	*str = "Hello";
	int		j;
	
	j = printf("%c\n", c);
	printf("\n%d", j);
}