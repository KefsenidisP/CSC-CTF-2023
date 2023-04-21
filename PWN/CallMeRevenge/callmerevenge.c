#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

char *cat = "CSC{bonus_fake_flag}\x00";

// Ignore this
extern FILE *__bss_start; 

// Ignore this
void sig_handler(int signum)
{
	if(signum == SIGALRM)
	{
		puts("Out of time");
		exit(0);
	}
}

// Ignore this function
void _buf_setup(void) 
{
	setvbuf(stdout, 0, _IONBF, 0);
	setvbuf(stdin, 0, _IONBF, 0);
	setvbuf(stderr, 0, _IONBF, 0);
	// setvbuf(__bss_start, NULL, _IONBF, 0);
}

// Ignore this
void _timeout()
{
	signal(SIGALRM, sig_handler);
  	alarm(60);
}

// You need something called a ROP gadget for the bonus.
void call_me_bonus(char *cmd)
{			
	puts("Better and high paid Job!!!");
	puts(cmd);
}

void call_me()
{
	FILE *fd;
	char flag[256];

	puts("Good Job!");
	puts("CSC{fake_flag}");
}

void make_call()
{
	// You may need gdb this time and perhaps python2.7...
	// And maybe try using a file with python, if you get stuck

	char buf[16];

	puts("Last time you called, you stole my flag!");
	puts("I hope you have a very good explanation for this!\n");

	gets(buf);

	puts("I thought as much!");
}

void main(int argc, char *argv[])
{
	_buf_setup();
	_timeout();
	make_call();
}
