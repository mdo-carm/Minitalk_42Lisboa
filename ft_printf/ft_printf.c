/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:03:11 by mdo-carm          #+#    #+#             */
/*   Updated: 2022/11/13 13:46:13 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_prtchar(char args)
{
	return (write(1, &args, 1));
}

unsigned int	ft_flag(const char *txt, va_list args)
{
	unsigned int	numchar;

	numchar = 0;
	if (*txt == 'c')
		numchar += ft_prtchar(va_arg(args, int));
	if (*txt == 's')
		numchar += ft_prtstr(va_arg(args, char *));
	if (*txt == 'p')
		numchar += ft_prtadrs(va_arg(args, unsigned long int));
	if (*txt == 'd' || *txt == 'i')
		numchar += ft_prtdec(va_arg(args, signed int));
	if (*txt == 'u')
		numchar += ft_prtdec_unsigned(va_arg(args, unsigned long int));
	if (*txt == 'x' || *txt == 'X')
		numchar += ft_prthex(va_arg(args, unsigned int), txt);
	if (*txt == '%')
		numchar += write(1, "%%", 1);
	return (numchar);
}

unsigned int	ft_movetoflag(const char *txt)
{
	unsigned int	i;

	i = 0;
	while (txt[i] != '\0' && !(txt[i] >= 'a' && txt[i] <= 'z') \
	&& txt[i] != '%' && txt[i] != ' ' && txt[i] != 'X')
		i++;
	return (i);
}

unsigned int	ft_printf(const char *txt, ...)
{
	int		numchar;
	va_list	args;

	if (!txt)
		return (0);
	va_start(args, txt);
	numchar = 0;
	while (*txt)
	{
		if (*txt == '%')
		{
			txt++;
			txt += ft_movetoflag(txt);
			numchar += ft_flag(txt, args);
		}
		else
			numchar += write(1, txt, 1);
		txt++;
	}
	va_end(args);
	return (numchar);
}
