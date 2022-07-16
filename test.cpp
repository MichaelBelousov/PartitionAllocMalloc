#include <stdio.h>
#include <stdlib.h>

#include <vector>

#include "config.h"
#include "PartitionAlloc.h"

int main(int argc, char *argv[]) {

	void *p = malloc(16);
	printf("PartitionAlloc memory allocated @ %p\n", p);
	free(p);

	void *t = malloc(1024);
	printf("Memory allocated with malloc @ %p\n", t);
	free(t);

	return 0;
}
