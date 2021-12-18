#include <stdio.h>
#include <syscall.h>
#include <unistd.h>

#define NUMBER_OF_ITERATIONS 99999999

#define __NR_get_number_of_context_switches 450

int main()
{
	int i, t = 2, u = 3, v;
	pid_t pid = getpid();
	int nvcw;

	for (i = 0; i < NUMBER_OF_ITERATIONS; i++)
		v = (++t) * (u++);

	if (syscall(__NR_get_number_of_context_switches, pid, &nvcw))
		printf("Error!\n");
	else
		printf("This process encounters %u times context switches.\n", nvcw);

	// getchar();	// cat /proc/PID/sched to validate the result

	return 0;
}
