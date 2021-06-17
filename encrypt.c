/**********************************************
 * name:    FILE ENCODER                      *
 * author:  S. MAROUSEK                       *
 * date:    2021/6/17                         *
 **********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int passwd_len(char text[])
{
	int number = 0;
	char c = 'x';
	int n;
	int i = 0;

	while (c != '\0') {
		c = text[i];
		i++;
	}

	return (i - 1);
}

/* Encrypt file */
int main(int argc, char *argv[])
{
	if (argc != 4) {
		fprintf(stderr,
			"ERROR: Invalid number of execution parameters\n");
		return 100;
	}
	char *file = argv[1];
	char *newfile = argv[2];
	char *passwd_text = argv[3];

	FILE *inputFile;
	FILE *outputFile;
	inputFile = fopen(file, "r");
	outputFile = fopen(newfile, "w");

	fprintf(outputFile, file);	// original file name
	fputc('\n', outputFile);
	fprintf(outputFile, "caesar\n");	// encoding type
	fprintf(outputFile, "štěpínův úžasný zakódovaný soubor  :)\n");	// random mess

	int passwd = passwd_len(passwd_text);
	char ch;
	unsigned long long position = 1;

	while (!feof(inputFile)) {
		ch = fgetc(inputFile);
		if (feof(inputFile)) {
			break;
		}

		int ch_int = ch;
		char ch = ch_int;

		for (int i = (passwd - 2); i >= 0; i--) {
			if (position % (i + 1) == 0) {
				ch_int = ch_int + (int)passwd_text[i];
				ch = ch_int;
				break;
			}
		}

		position++;
		fputc(ch, outputFile);
	}

	fclose(inputFile);
	fclose(outputFile);

	return 0;
}
