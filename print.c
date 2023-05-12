#include "shell.h"

/**
 * print - Writes a string to the standard output
 * @string: Pointer to the string to be written
 *
 * This function writes the provided string to the standard output.
 * It returns void.
 */

void print(char *string)
{
	int BytesToWrite = stringlen(String);
	ssize_t TotalBytesWritten = write(STDOUT_FILENO, string, BytesToWrite);

	if (TotalBytesWritten == -1)
	{
		perror("Write() failed to write to the standard output");
		return;

		if (TotalBytesWritten < BytesToWrite)
		{
			perror("write() was unable to write all characters to standard output");
			return;
		}
	}
}

