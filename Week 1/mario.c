#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n ;
    do
    {
        n = get_int("height=");
    }
    while (n <= 0 || n > 8);
    // for printing columns     
    for (int i = 0 ; i < n ; i++)
    {   
        // for printing spaces
        for (int j = n - 1 ; j > i ; j--)
        {
            printf(" ");
        }   

        // for printing hashes
        for (int k = 0 ; k <= i ; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
       
   

