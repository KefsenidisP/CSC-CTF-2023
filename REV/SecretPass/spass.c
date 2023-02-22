#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		puts("Give me a the password and you will have the flag");
		puts("Usage: ./spass <password>");
		
		return 0;
	}

	char *pass = argv[1];
	char *enc_flag = "C}SrC0{x5_wh47pipwi_ng";

	for(int i = 0; i < strlen(pass); i++)
		for(int j = 0; j < i; j++)
			for(int k = 0; k < j; k++)
			{
				pass[i] ^= pass[j];
				pass[j] ^= pass[i];
				pass[i] ^= pass[j];
			}
	
	if(!strncmp(pass, enc_flag, 22))
	{
		puts("You have found the flag!");

		return 0;
	}

	puts(pass);

	return 0;
}
