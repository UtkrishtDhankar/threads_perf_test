all: thread

thread: threads.c
	gcc -pthread threads.c -o thread
