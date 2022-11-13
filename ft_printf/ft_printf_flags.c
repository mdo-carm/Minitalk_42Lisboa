/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:45:02 by mdo-carm          #+#    #+#             */
/*   Updated: 2022/03/15 19:44:11 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_prtstr(const char *args)
{
	unsigned int	numchar;

	numchar = 0;
	if (!args)
		return (write(1, "(null)", 6));
	while (*args != '\0')
		numchar += write(1, args++, 1);
	return (numchar);
}

unsigned int	ft_prtadrs(unsigned long int args)
{
	unsigned int	numchar;

	numchar = 0;
	if (args >= 16)
		numchar += ft_prtadrs(args / 16);
	if (args < 16)
		numchar += write(1, "0x", 2);
	numchar += ft_prtchar("0123456789abcdef"[args % 16]);
	return (numchar);
}

unsigned int	ft_prtdec(signed int args)
{
	char			x;
	unsigned int	numchar;

	numchar = 0;
	if (args == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (args < 0)
	{
		args = (args * -1);
		numchar += write(1, "-", 1);
	}
	if (args >= 10)
	{
		numchar += ft_prtdec(args / 10);
	}
	x = ((args % 10) + 48);
	numchar += write(1, &x, 1);
	return (numchar);
}

unsigned int	ft_prtdec_unsigned(unsigned int args)
{
	unsigned int	numchar;
	char			x;

	numchar = 0;
	if (args >= 10)
		numchar += ft_prtdec_unsigned(args / 10);
	x = ((args % 10) + 48);
	numchar += write(1, &x, 1);
	return (numchar);
}

unsigned int	ft_prthex(unsigned int args, const char *txt)
{
	int	numchar;

	numchar = 0;
	if (args >= 16)
	{
		numchar += ft_prthex((args / 16), txt);
		numchar += ft_prthex((args % 16), txt);
	}
	if (args < 16)
	{
		if (*txt == 'x')
			numchar += ft_prtchar("0123456789abcdef"[args]);
		else
			numchar += ft_prtchar("0123456789ABCDEF"[args]);
	}
	return (numchar);
}
