#include "shell.h"

void print(char *String)
{
	int BytesToWrite = stringlen(String);
	ssize_t TotalBytesWritten = write(STDOUT_FILENO, String, BytesToWrite);
	
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
