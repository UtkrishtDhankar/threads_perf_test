all: threads procs

threads: threads.c
	gcc -pthread threads.c -o threads

procs: procs.c
	gcc procs.c -o procs
