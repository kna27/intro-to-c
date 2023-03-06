#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *key;
	int key_length;
	int c;
	int i;
	if (argc < 2)
	{
		printf("Not enough arguments. Provide \"key\"\n");
		return -1;
	}
	key = argv[1];
	key_length = strlen(key);
	i = 0;
	for (c = getchar(); c != EOF; c = getchar())
	{
		putchar(c ^ key[i]);
		i = (i + 1) % key_length;
	}
}
