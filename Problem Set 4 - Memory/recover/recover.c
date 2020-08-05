#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

typedef uint8_t BYTE;
int main(int argc, char *argv[])
{
    //ensure user ran program with two words at prompt 
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }
    //open a file
    FILE *memory_card = fopen(argv[1], "r");
    unsigned char buffer[512];
    int file_count = 0;
    int jpeg = 0;
    int counter = 0;
    char fname[8];
    FILE *img = NULL ;
    fread(buffer, 512, 1, memory_card);
    
    
    while (fread(buffer, 512, 1, memory_card) != 0)
    {
        
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpeg == 0)
            {
                sprintf(fname, "%03i.jpg", counter);
                img = fopen(fname, "a");
                jpeg = 1;
            }
            else
            {
                fclose(img);
                counter ++;
                sprintf(fname, "%03i.jpg", counter);
                img = fopen(fname, "a");

            }
        }
        if (jpeg == 1)
        {
            fwrite(&buffer, 512, 1, img);
        }

    }
    fclose(img);
    fclose(memory_card);
}
