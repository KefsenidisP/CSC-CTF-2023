#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ignore this function
void _buf_setup(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
}

void call_me(void)
{	
	setuid(0);
	system("/bin/cat flag.txt");
	
	exit(0);
}

int main(int argc, char* argv[])
{	
	void (*make_call)(void) = NULL;
	char num[32];
	
	_buf_setup();

	printf("You have 2 numbers saved on your phone: ");
	printf("%x, %x\n", call_me, main);
		
	printf("> ");
	gets(num);
	
	puts("Call pending...");

	(*make_call)();

	return 0;
}