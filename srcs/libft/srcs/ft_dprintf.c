/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:49:36 by lseiller          #+#    #+#             */
/*   Updated: 2022/05/05 16:12:46 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_flag_case(const char *format, va_list ap, int i, int fd)
{
	if (format[i] == 'c')
		return (ft_putchar_fd((char) va_arg(ap, int), fd));
	else if (format[i] == 's')
		return (ft_putstr_fd(va_arg(ap, char *), fd));
	else if (format[i] == 'p')
		return (ft_putptr_fd(va_arg(ap, void *), fd));
	else if (format[i] == 'd' || format[i] == 'i')
		return (ft_putnbr_fd(va_arg(ap, int), fd));
	else if (format[i] == 'u')
		return (ft_putnbr_fd(va_arg(ap, unsigned int), fd));
	else if (format[i] == 'x' || format[i] == 'X')
		return (ft_puthex_fd(va_arg(ap, long), format[i], fd, 0));
	else if (format[i] == '%')
		return (ft_putchar_fd('%', fd));
	return (0);
}

int	ft_dprintf(int fd, const char *format, ...)
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
			char_p += ft_flag_case(format, ap, index, fd);
		}
		else
			char_p += ft_putchar_fd(format[index], fd);
		index++;
	}
	va_end(ap);
	return (char_p);
}
