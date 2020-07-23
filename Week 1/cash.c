  
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    
    float n  ;
    int quaters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    int coins = 0 ;
    do
    {
        n = get_float("owed: ");
    }
    while (n < 0);
    n = n * 100;
    n = round(n);
    // counting quaters
    while (n >= 25)
    {
        n = n - 25;
        quaters ++;
    }
    // counting dimes
    while (n >= 10)
    {
        n = n - 10;
        dimes ++;
    }
    // counting nickels
    while (n >= 5)
    {
        n = n - 5;
        nickels ++;
    }
    // counting pennies
    while (n >= 1)
    {
        n = n - 1;
        pennies ++;
    }
    coins = quaters + dimes + nickels + pennies ;
    printf(" %i \n", coins);

}
