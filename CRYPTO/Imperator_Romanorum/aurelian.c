#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *caesar_cypher(char *text)
{
    int size = strlen(text);
    char *enc = (char*) malloc((size + 0x08) * sizeof(char));
    int sh = 10;
    int j = 0;

    for(char let = text[j]; let != '\0'; let = text[j])
    {
        if(isupper((int)let))
            enc[j] = ((let + sh - 65) % 26 + 65);

        else
            if(islower((int)let))
                enc[j] = ((let + sh - 97) % 26 + 97);

        j++;
    }

    return enc;
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Usage: ./cae... I mean ./aurelian <input>\n");

        return 0;
    }

    printf("%s\n", caesar_cypher(argv[1]));

    return 0;
}