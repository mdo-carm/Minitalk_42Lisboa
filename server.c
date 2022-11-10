/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorum <thorum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:24:10 by mdo-carm          #+#    #+#             */
/*   Updated: 2022/11/10 17:48:42 by thorum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

char x[8];

void abtoa (const char *x)
{
	int		binary[8] = {128,64,32,16,8,4,2,1};
	int		charvalue;
	int		i;
	char	y;

	i = 0;
	charvalue = 0;
	while (i < 8)
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

void handler(int num)
{
	static int	i;

	while (i < 8)
	{
		printf("%d\n", x);
		if (num == 10)
			x[i] = 48; // number 2 in the ascii table
		if (num == 12)
			x[i] = 49; // number 1 in the ascii table
		i++;
	}
	x[8] = '\0';
	// printf("%s\n", x);
	// abtoa(x);
}

int	main()
{	
	printf("PID: %d\n", getpid()); // Change to ft_printf
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		sleep(1);
}
