#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int	main()
{
	int	x;

	for (x=0; x <= 59; x++)
	{
		printf("\t0:%1d  Current ID: %d\n", x, getpid());
		sleep(1);
	}
}
