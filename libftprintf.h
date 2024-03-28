/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:35:46 by dbozic            #+#    #+#             */
/*   Updated: 2024/03/14 15:10:35 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "unistd.h"
# include "stdlib.h"
# include "stdarg.h"

int		ft_printf(const char *str, ...);
int		ft_printf_c(char c);
int		ft_printf_s(char *str);
int		ft_printf_p(void *ptr);
int		ft_printf_d(int d);
int		ft_printf_u(unsigned int u);
int		ft_printf_xx(int d, int x);

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *str, int fd);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *str, size_t n);

#endif
