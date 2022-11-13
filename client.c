/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:23:35 by mdo-carm          #+#    #+#             */
/*   Updated: 2022/11/13 18:49:38 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int		bit;
	int		x;
	int		i;

	if (argc != 3)
		return (write(2, "ERROR: Not Enough Arguments\n", 28));
	x = ft_atoi(argv[1]);
	i = 0;
	bit = 0;
	while (argv[2][i])
	{
		while (bit < 8)
		{
			if (argv[2][i] & 128 >> bit)
				kill(x, 12);
			else
				kill(x, 10);
			bit++;
			usleep(100);
		}
		bit = 0;
		i++;
	}
	return (0);
}
