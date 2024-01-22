#include <stdio.h>

int main(int argc, char *argv[])
{
	char align_ch = -1; // alignment character
	int indentation_point = 0; // the largest index of alignment character for each string

	/* Find the character to align to */
	for (int i = 0; argv[1][i]; i++) {                 // for each character of the first string
		int matches = 2;
		for (int j = 2; j < argc; j++) {           // for each string except for the 1st
			for (int k = 0; argv[j][k]; k++) { // for each character of that string
				if (argv[j][k] == argv[1][i]) {
					matches++;
					if (indentation_point < k)
						indentation_point = k;
					break;
				}
			}
		}
		if (matches >= argc) {
			align_ch = i;
			break;
		}
	}
	if (align_ch < 0)
		return 1;

	for (int i = 1; i < argc; i++) {                              // for each string
		int align_ch_index = 0; // index of alignment character for this string
		for (int j = 0; argv[1][align_ch] != argv[i][j] && argv[i][j]; j++) // for each character
			align_ch_index++;
		for (int j = 0; j < (indentation_point - align_ch_index); j++)      // for each space required
			printf(" ");
		printf("%s\n", argv[i]);
	}

	return 0;
}
