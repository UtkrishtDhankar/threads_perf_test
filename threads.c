#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 10000

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
	pthread_t* threads = malloc(NUM_THREADS * sizeof (*threads));
	for (unsigned i = 0; i < NUM_THREADS; i++) {
		pthread_create(threads + i, NULL, &do_stuff, NULL);
	}

	for (unsigned i = 0; i < NUM_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}

	return 0;
}
