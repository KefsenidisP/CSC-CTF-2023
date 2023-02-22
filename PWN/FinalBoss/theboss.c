#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setup(void)
{
	puts("So you've made it thus far, but do you have what it takes to get  the shell?\nAnd also, all of the flags? (and solutions)\nI am looking forward to it\nYou are tasked with defeating the csc pwn boss!\n");
}

void choices(void)
{
	puts("\n1.Gather information about the pwn boss\n2.Assault the pwn boss directly!\n3.Prepare yourself\n4.Strategically aproach the pwn boss\n>>");
}

void gather_intel(void)
{	
	char buf[0x10];

	puts("Enter your search term: ");
	fgets(buf, 0x10, stdin);

	buf[0x0f] = '\0';

	puts("I am sorry, but we could not get any information about the pwn boss\nOnly our input came back...");
	printf(buf);
}

void direct_assault(void)
{
	puts("We found only some strange birds!\nThe pwn boss is defeated!");
	puts("Now where is my reward?");

	exit(0);
}

void strategical_aproach(int prepared)
{
	char the_plan[64];

	puts("Execute \"Operation bin dash\"!");
	gets(the_plan);

	if(prepared)
	{
		puts("Operation successful\nTo the victors the spoils!");

		return;
	}
	
	puts("I didn't say Sea Lion!\nYou already lost...");

	exit(0);
}

char prepare(void)
{
	int prepared = 0;
	char warcry[32];

	setuid(0);
	
	puts("Unleash your warcry, to scare the enemies and clear the way to the pwn Boss!\nDo not overdo it!");
	fgets(warcry, 100, stdin);
	
	if(strlen(warcry) > 32)
	{
		puts("The pwn boss spotted and destroyed you!");
		exit(0);
	}

	if(strcmp(warcry, "tsiou,tsiou\0"))
		prepared = 1;

	return prepared;
}

int main(int argc, char *argv[])
{	
	char warcry[16];
	int prepared = 0;

	setup();

	while(1)
	{	
		char choice[2];

		choices();
		fgets(choice, 2, stdin);
		getchar();

		switch(choice[0])
		{
			case '1':
				gather_intel();
				break;
			case '2':
				direct_assault();
				break;
			case '3':
				prepared = (int)prepare();
				break;
			case '4':
				strategical_aproach(prepared);
				break;
			default:
				puts("No escape, only pwn Boss.");
		}
	}
	
	return 0;
}
