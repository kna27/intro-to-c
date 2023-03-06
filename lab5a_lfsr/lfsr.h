
/*Some kind of struct for an LFSR*/
struct lfsr;

typedef struct lfsr LFSR;

/*
 * Allocates memory for an LFSR with an initial
 * register containing the seed string and the given tap index.
 * Creates a deep copy of the seed string for the lfsr register.
 * Returns a pointer to that struct.
 * You may assume that tap is greater than 0 and less than the length of seed.
 */
LFSR *createLFSR(char *seed, int tap);

/*
 * Return the character at the leftmost position of the register (position 0, next to get shifted off/dequeued).
 * Should take a CONSTANT amount of time, with respect the size of the register.
 */
char lfsrHead(LFSR *lfsr);

/*
 * Return the character at the tap index of the register. The head is considered position 0.
 * Should take a CONSTANT amount of time, with respect the size of the register/the tap index..
 */
char lfsrTap(LFSR *lfsr);

/*
 * Perform one cycle of the LFSR algorithm. The register should
 * shift all characters one position to the left (shifting the head off), and
 * filling the vacated rightmost position with the XOR of the two chars that used to be at the head and the tap.
 * (Alternative description: simultaneously enqueue a new char (XOR of head and tap) and dequeue the head)
 * Should take at most a LINEAR amount of time, with respect to the size of the register.
 *
 * Returns a copy of the newly XORed character (the character now at the tail of the array).
 */
char lfsrStep(LFSR *lfsr);

/*
 * Print the contents of the register as a list for debugging purposes, one line per character.
 * Each line should include the index, the hex value of the char, and (if printable) the char itself.
 * Note the tap index with a + symbol.
 * For example, an LFSR created with createLSFR("lfsr", 2) would print:
 *  0: 6c (l)
 *  1: 66 (f)
 * +2: 73 (s)
 *  3: 72 (r)
 * Recall that the printable range of characters are in the decimal range [32,126] inclusive
 */
void lfsrDebugPrint(LFSR *lfsr);

/*
 * Allocate memory for a new string with the same length and contents as the register.
 * Return a pointer to this new string. It is up to the caller to free the string later.
 */
char *lfsrToString(LFSR *lfsr);

/*
 * Free all memory associated with this LFSR.
 */
void destroyLFSR(LFSR *lfsr);
