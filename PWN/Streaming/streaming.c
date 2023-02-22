#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{	
	char* msg = "Select a file stream to write.\n";
	char* note = "Usage: ./streaming <file stream>";

	if(argc < 2)
	{
		write(0, msg, strlen(msg));
		write(0, note, strlen(note));
		
		return 0;
	}

	int fd = atoi(argv[1]);
	char buf[32];

	read(fd, buf, 0x20);

	if(strcmp(buf, "LETMEIN!\n"))
	{	
		char* inmsg = "You are in!\n";

		write(0, inmsg, strlen(inmsg));

		setuid(0);
		system("/bin/cat flag.txt");
		
		return 0;
	}

	return 0;
}
