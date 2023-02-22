#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *cat = "/bin/cat bonus_flag.txt\x00";

// You need something called a ROP gadget for the bonus.
void call_me_bonus(char *cmd)
{		
	if(!strcmp(cmd, "/bin/sh\x00"))
	{
		printf("I am not letting you read all of my flags!\n");
		exit(-1);
	}
	
	setuid(0);
	system(cmd);

	exit(0);
}

void call_me(void)
{
	setuid(0);
	system("/bin/cat flag.txt");

	exit(0);
}

int main(int argc, char *argv[])
{
	//You may need gdb this time and perhaps python2.7...
	//And maybe try using a file with python, if you get stuck

	char buf[16];

	printf("Last time you called, you stole my flag!\n");
	printf("I hope you have a very good explanation for this!\n");

	gets(buf);

	printf("I thought as much!\n");

	return 0;
}
