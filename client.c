/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorum <thorum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:23:35 by mdo-carm          #+#    #+#             */
/*   Updated: 2022/11/12 05:43:01 by thorum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		bit; //position of current bit
	int		pid;
	int		i;

	if (argc != 3)
		return (write(2, "Invalid Arguments\n", 18));
	pid = atoi(argv[1]); //alterar para ft_atoi
	i = 0;
	bit = 0;
	while (argv[2][i])
	{
		while (bit < 8)
		{
			if (argv[2][i] & 128 >> bit) //char(128) binary = 10000000
				kill(pid, 12);
			else
				kill(pid, 10);
			bit++;
			usleep(100);
		}
		bit = 0;
		i++;
	}
	return (0);
}
