#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int num)
{
	write(2, "I won't Die!", 13);
}

void seghandler(int num)
{
	write(2, "Seg Fault!\n", 10);
}

int	main(int )
{
	int x;

	signal(SIGUSR1, handler);
	for (x=0; x <= 59; x++)
	{
		printf("\t0:%1d  Current ID: %d\n", x, getpid());
		sleep(1);
	}
}