/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:15:56 by mdo-carm          #+#    #+#             */
/*   Updated: 2022/03/23 21:34:39 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

unsigned int	ft_prtchar(char args);
unsigned int	ft_prtstr(const char *args);
unsigned int	ft_prtadrs(unsigned long int args);
unsigned int	ft_prtdec(signed int args);
unsigned int	ft_prtdec_unsigned(unsigned int args);
unsigned int	ft_prthex(unsigned int args, const char *txt);
unsigned int	ft_movetoflag(const char *txt);
unsigned int	ft_flag(const char *txt, va_list args);
unsigned int	ft_printf(const char *txt, ...);

#endif