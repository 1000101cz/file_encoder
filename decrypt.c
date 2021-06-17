/**********************************************
 * name:    FILE DECODER                      *
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

/* Decode encrypted file */
int main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stderr,
			"ERROR: Invalid number of execution parameters\n");
		return 100;
	}
	char *file = argv[1];
	char *passwd_text = argv[2];

	FILE *inputFile;
	inputFile = fopen(file, "r");

	char newfile[100];	// get name of original file
	fgets(newfile, 100, inputFile);
	newfile[strcspn(newfile, "\n")] = 0;

	FILE *outputFile;
	outputFile = fopen(newfile, "w");

	char encryptionType[20];	// encoding type
	fgets(encryptionType, 20, inputFile);

	if (!
	    (encryptionType[0] == 'c' && encryptionType[1] == 'a'
	     && encryptionType[2] == 'e' && encryptionType[3] == 's'
	     && encryptionType[4] == 'a' && encryptionType[5] == 'r')) {
		printf("cypher not recognised\n");
		return 100;
	}

	char mess[200];
	fgets(mess, 200, inputFile);	// random mess

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

		for (int i = passwd - 2; i >= 0; i--) {
			if (position % (i + 1) == 0) {
				ch_int = ch_int - (int)passwd_text[i];
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
