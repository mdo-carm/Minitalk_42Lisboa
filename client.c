/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:23:35 by mdo-carm          #+#    #+#             */
/*   Updated: 2022/11/10 03:31:18 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		bit; // position of current bit
	int		x;
	int		i;

	x = atoi(argv[1]); // alterar para ft_atoi
	i = 0;
	bit = 0;
	while (argv[2][i])
	{
		printf("%c -> ", argv[2][i]);
		while (bit < 8)
		{
			if (argv[2][i] & 128 >> bit) // char(128) binary = 10000000
			{
				printf("1");
				kill(x, 12);//SIGUSR2
			}
			else
			{
				printf("0");
				kill(x, 10);//SIGUSR1
			}
			bit++;
			usleep(100);
		}
		printf("\n");
		bit = 0;
		i++;
	}
	return (0);
}
