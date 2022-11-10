/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:24:10 by mdo-carm          #+#    #+#             */
/*   Updated: 2022/11/10 05:44:39 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

char	x[8];

void abtoa ()
{
	int		binary[8] = {128,64,32,16,8,4,2,1};
	int		charvalue;
	int		i;
	char	y;

	i = 0;
	while (i <= 0)
	{
		if (x[i] == '1')
		{
			charvalue = charvalue + binary[i];
			i++;
		}
		if (x[i] == '0')
			i++;
	}
	y = charvalue;
	// write(2, &x, 1);
	printf("%d\n", charvalue);
	// write(2, &y, 1);
}

void usr1handler(int num)
{
	int		i;
	
	i = 0;
	if (i < 8)
	{
		if (num == 10)
			x[i] = 48; // number 2 in the ascii table
		if (num == 12)
			x[i] = 49; // number 1 in the ascii table
		i++;
	}
	x[8] = '\0';
	abtoa();
}

void usr2handler(int num)
{
	usr1handler(num);
}

int	main()
{
	printf("PID: %d\n", getpid()); // Change to ft_printf
	signal(SIGUSR1, usr1handler);
	signal(SIGUSR2, usr2handler);
	printf("%s\n", x);
	while (1)
		sleep(1);
}
