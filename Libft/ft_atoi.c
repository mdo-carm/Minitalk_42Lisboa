/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:23:36 by mdo-carm          #+#    #+#             */
/*   Updated: 2022/03/14 17:22:58 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(const char *str)
{
	if (*str == ' ' || (*str >= '\t' && *str <= '\r'))
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	number;
	int	nr_sign;

	i = 0;
	number = 0;
	nr_sign = 1;
	while (ft_isspace(&str[i]) == 1 && str[i] != '\0')
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			nr_sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (number * nr_sign);
}
/*
int	main(void)
{
	char n[40] = "";
	int i1 = atoi(n);
	int i2 = ft_atoi(n);

	printf("Original function: %d\n\n", i1);
	printf("My function      : %d\n\n", i2);
}
*/