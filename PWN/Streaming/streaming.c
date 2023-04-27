#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ignore this function
void _buf_setup(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
}

int main(int argc, char* argv[])
{	
	char* msg = "Select a file stream to write.\n";
	int fd;

	_buf_setup();

	write(0, msg, strlen(msg));

	scanf("%d", &fd);
	
	char buf[32];

	read(fd, buf, 0x20);

	if(!strcmp(buf, "I SHALL PASS!\n"))
	{	
		char* inmsg = "You are in!\n";

		write(0, inmsg, strlen(inmsg));

		setuid(0);
		system("/bin/cat flag.txt");
		
		return 0;
	}

	return 0;
}
