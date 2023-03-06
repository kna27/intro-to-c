#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "lfsr.h"

void testSet(char *seed, int tap, char **lfsr_states, int total_steps)
{
	char *temp_str;
	char output;
	char expected;
	int register_size = strlen(seed);
	LFSR *lfsr = createLFSR(seed, tap);
	int step;

	printf("\nLFSR created with seed %s and tap %d\n\t", seed, tap);

	for (step = 0; step <= total_steps; step++)
	{
		// Step "0" just checks initial state
		if (step > 0)
		{
			printf("\nStep %d:\n\t", step);
			// Check lfsrStep
			output = lfsrStep(lfsr);
			expected = lfsr_states[step][register_size - 1];
			if (output != expected)
			{
				printf("\nFAILED: lfsrStep result %x (%c) doesn't match expected output %x (%c)\n", output, output, expected, expected);
				return;
			}
			else
				printf("lsfrStep: %x (%c)", output, output);
		}

		// Check lfsrToString
		temp_str = lfsrToString(lfsr);

		if (strcmp(lfsr_states[step], temp_str) != 0)
		{
			printf("\nFAILED: lfsrToString result \"%s\" doesn't match expected output \"%s\"\n", temp_str, lfsr_states[step]);
			return;
		}
		else
			printf(" | toString: %s", temp_str);

		free(temp_str);

		// Check lfsrHead
		output = lfsrHead(lfsr);
		expected = lfsr_states[step][0];
		if (output != expected)
		{
			printf("\nFAILED: lfsrHead result %x (%c) doesn't match expected output %x (%c)\n", output, output, expected, expected);
			return;
		}
		else
			printf(" | lsfrHead: %x (%c)", output, output);

		// Check lfsrTap
		output = lfsrTap(lfsr);
		expected = lfsr_states[step][tap];
		if (output != expected)
		{
			printf("\nFAILED: lfsrTap result %x (%c) doesn't match expected output %x (%c)\n", output, output, expected, expected);
			return;
		}
		else
			printf(" | lsfrTap: %x (%c)", output, output);
	}

	destroyLFSR(lfsr);
	printf("\ndestroyLFSR does not cause segFault, although correctness is not guaranteed\n");
}

int main()
{
	char *seed_1 = "aBcDeFg";
	char *seed_2 = "AbCdEfG?!";
	int tap_1 = 3;
	int tap_2 = 6;
	int total_steps_1 = 10;
	int total_steps_2 = 10;
	char *lfsr_states_1[] = {"aBcDeFg", "BcDeFg%", "cDeFg%'", "DeFg%'%", "eFg%'%#",
							 "Fg%'%#@", "g%'%#@a", "%'%#@aB", "'%#@aB\x06", "%#@aB\x06g",
							 "#@aB\x06gD"};
	char *lfsr_states_2[] = {"AbCdEfG?!", "bCdEfG?!\x06", "CdEfG?!\x06]", "dEfG?!\x06]b", "EfG?!\x06]bb",
							 "fG?!\x06]bb\x18", "G?!\x06]bb\x18\x04", "?!\x06]bb\x18\x04%", "!\x06]bb\x18\x04%'",
							 "\x06]bb\x18\x04%'%", "]bb\x18\x04%'%#"};

	printf("Running Test set 1:\n");
	testSet(seed_1, tap_1, lfsr_states_1, total_steps_1);
	printf("Running Test set 2:\n");
	testSet(seed_2, tap_2, lfsr_states_2, total_steps_2);
}
