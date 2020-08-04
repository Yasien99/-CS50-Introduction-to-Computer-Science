#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main (void){
   int k = 2;
   int pi =0;
   int ci=0;
   string text = get_string("plaintext:");
   pi= text[0] - 65;
   ci = (pi + k) % 26;
   text[0] = ci + 65;
   printf("%c\n",text[0]);
}