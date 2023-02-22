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

	if(argc < 2)
	{
		printf("You need to decide whom to call first!\n");
		printf("You have 2 numbers saved on your phone: ");
		printf("%x, %x", call_me, main);

		printf("\nUsage: ./callme <input>\n");

		return 0;
	}
		
	strcpy(num, argv[1]);
	
	printf("Call pending...\n");

	(*make_call)();

	return 0;
}

