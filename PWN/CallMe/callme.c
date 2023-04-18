#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

	printf("You have 2 numbers saved on your phone: ");
	printf("%x, %x\n", call_me, main);
		
	printf("> ");
	gets(num);
	
	printf("Call pending...\n");

	(*make_call)();

	return 0;
}

