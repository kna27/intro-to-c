#include <stdio.h>
#include <string.h>
#include "lfsr.h"

int main(int argc, char *argv[])
{
	char *key;
	int key_length;
	int tap;
	int c;
	int i;
	if (argc < 3)
	{
		printf("Not enough arguments. Provide \"key\" and a \"tap\" position\n");
		return -1;
	}
	key = argv[1];
	key_length = strlen(key);
	sscanf(argv[2], "%i", &tap);
	LFSR *lfsr = createLFSR(key, tap);
	i = 0;
	for (c = getchar(); c != EOF; c = getchar())
	{
		putchar(c ^ lfsrStep(lfsr));
		i = (i + 1) % key_length;
	}
	for (i = 0; i < key_length; i++)
	{
		lfsrStep(lfsr);
	}
}
