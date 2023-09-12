/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:40:42 by aatbir            #+#    #+#             */
/*   Updated: 2023/09/12 16:00:19 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

int	ft_putnbr(int n)
{
	int	a;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	a = n % 10 + '0';
	write(1, &a, 1);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				count += ft_putchar(va_arg(arg, int));
			else if (format[i] == 'd')
				count += ft_putnbr(va_arg(arg, int));
			else if (format[i] == 's')
				count += ft_putstr(va_arg(arg, char *));
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
