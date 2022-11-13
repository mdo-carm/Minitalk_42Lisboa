/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:24:10 by mdo-carm          #+#    #+#             */
/*   Updated: 2022/11/13 15:22:55 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_binary[8] = {128, 64, 32, 16, 8, 4, 2, 1};

void	abtoa(int num)
{
	static int		charvalue;
	static int		i;

	if (i < 8)
	{
		if (num == 12)
			charvalue = charvalue + g_binary[i];
		i++;
	}
	if (i == 8)
	{
		write(2, &charvalue, 1);
		i = 0;
		charvalue = 0;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, abtoa);
	signal(SIGUSR2, abtoa);
	while (1)
		sleep(1);
	return (0);
}
