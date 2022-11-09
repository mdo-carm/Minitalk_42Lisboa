/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:24:10 by mdo-carm          #+#    #+#             */
/*   Updated: 2022/10/28 17:10:06 by mdo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void usr1handler(int num)
{
	write(2, "0", 1);
}

void usr2handler(int num)
{
	write(2, "1", 1);
}

int	main()
{
	printf("PID: %d\n", getpid());
	signal(SIGUSR1, usr1handler);
	signal(SIGUSR2, usr2handler);
	while (1)
		sleep(1);
}
