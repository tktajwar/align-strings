int main(int argc, char *argv[])
{
	char align_ch = -1; // alignment character

	/* Find the character to align to */
	for (int i = 0; argv[1][i]; i++) {                 // for each character of the first string
		int matches = 2;
		for (int j = 2; j < argc; j++) {           // for each string except for the 1st
			for (int k = 0; argv[j][k]; k++) { // for each character of that string
				if (argv[j][k] == argv[1][i]) {
					matches++;
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

	return 0;
}
