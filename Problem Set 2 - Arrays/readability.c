#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    int letters = 0;
    int words = 0;
    int sentences = 0;
    string s = get_string("text : ");
    
    for (int i = 0 ; i < strlen(s) ; i++)
    { 
        s[i] = tolower(s[i]);
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            letters ++ ;
        }
        if (s[i] == ' ')
        {
            words ++ ;
        }
        if (s[i] == '!' || s[i] == '.' || s[i] == '?')
        {
            sentences ++ ;
        }
        
    }
    
    float L = (float)letters * 100 / (words + 1) ;
        
    float S = (float)sentences * 100 / (words + 1) ;
        
    double index = 0.0588 * L - 0.296 * S - 15.8;
        
    int grade = round(index);
    
    if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    if (grade < 16 && grade > 1)
    {
        printf("Grade %i\n", grade);
    }
    
}