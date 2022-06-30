/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:49:36 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/09 01:09:17 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_flag_case(const char *format, va_list ap, int i)
{
	if (format[i] == 'c')
		return (ft_putchar_fd((char) va_arg(ap, int), 1));
	else if (format[i] == 's')
		return (ft_putstr_fd(va_arg(ap, char *), 1));
	else if (format[i] == 'p')
		return (ft_putptr_fd(va_arg(ap, void *), 1));
	else if (format[i] == 'd' || format[i] == 'i')
		return (ft_putnbr_fd(va_arg(ap, int), 1));
	else if (format[i] == 'u')
		return (ft_putnbr_fd(va_arg(ap, unsigned int), 1));
	else if (format[i] == 'x' || format[i] == 'X')
		return (ft_puthex_fd(va_arg(ap, long), format[i], 1, 0));
	else if (format[i] == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		char_p;
	va_list	ap;
	int		index;

	index = 0;
	char_p = 0;
	va_start(ap, format);
	while (format[index])
	{
		if (format[index] == '%')
		{
			index++;
			char_p += ft_flag_case(format, ap, index);
		}
		else
			char_p += ft_putchar_fd(format[index], 1);
		index++;
	}
	va_end(ap);
	return (char_p);
}
