/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorum <thorum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:24:10 by mdo-carm          #+#    #+#             */
/*   Updated: 2022/11/12 05:46:47 by thorum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void abtoa (int num)
{
	int				binary[8] = {128,64,32,16,8,4,2,1};
	static int		charvalue;
	static int		i;

	if (i < 8)
	{
		if (num == 12)
			charvalue = charvalue + binary[i];
		i++;
	}
	if (i == 8)
	{
		write(2, &charvalue, 1);
		i = 0;
		charvalue = 0;
	}
}

int	main()
{
	printf("PID: %d\n", getpid()); // Change to ft_printf
	signal(SIGUSR1, abtoa);
	signal(SIGUSR2, abtoa);
	while (1)
		sleep(1);
}
