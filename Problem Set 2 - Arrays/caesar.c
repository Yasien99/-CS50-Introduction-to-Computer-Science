#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

bool check_key(string s);
int main(int argc, string argv[])
{
    int pi = 0;
    int ci = 0;
 
    if (argc != 2)
    {
        printf("Usage:./caesar key\n");
        return 1;
    }
    int l = strlen(argv[1]);
    for (int i = 0; i < l; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage:./caesar key\n");
            return 1;
        }
    }
  
    int k = atoi(argv[1]);
    string text = get_string("plaintesxt:");
    printf("ciphertext: ");

    for (int i = 0 ; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                pi = text[i] - 65;
                ci = (pi + k) % 26;
                text[i] = ci + 65;
                printf("%c", text[i]);
            }
            if (islower(text[i]))
            {
                pi = text[i] - 97;
                ci = (pi + k) % 26;
                text[i] = ci + 97;
                printf("%c", text[i]);
            }  
        
        }
        else
        {
            printf("%c", text[i]);
        }
      
    }
    
    printf("\n");
    return 0 ;
}
