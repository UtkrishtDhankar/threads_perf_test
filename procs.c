#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_PROCS 10000
#define PROCS_PER_ITER 100

unsigned factorial(unsigned n)
{
	if (n > 0)
		return n * factorial(n - 1);
	else
		return 1;
}

void* do_stuff(void* voidptr)
{
	factorial(10);
	return NULL;
}

int main()
{
	int* pids = malloc(PROCS_PER_ITER * sizeof (*pids));
	unsigned iters = 0;
	while (iters < NUM_PROCS) {
		for (unsigned i = 0; i < PROCS_PER_ITER; i++) {
			pids[i] = fork();
			if (pids[i] == 0) {
				do_stuff(NULL);
				exit(0);
			} else {
				continue;
			}
		}

		for (unsigned i = 0; i < PROCS_PER_ITER; i++) {
			int status;
			waitpid(pids[i], &status, 0);
			iters++;
		}
	}
	return 0;
}
