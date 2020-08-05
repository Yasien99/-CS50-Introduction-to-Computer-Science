#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int j = 0; j < width ; j++)
    {
        for (int i = 0; i < height ; i++)
        {
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            int sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            if (sepiaRed <= 255)
            {
                image[i][j].rgbtRed =  sepiaRed;
            }
            else
            {
                image[i][j].rgbtRed = 255 ;
            }

            if (sepiaGreen <= 255)
            {
                image[i][j].rgbtGreen =  sepiaGreen;
            }
            else
            {
                image[i][j].rgbtGreen = 255 ;
            }

            if (sepiaBlue <= 255)
            {
                image[i][j].rgbtBlue =  sepiaBlue;
            }
            else
            {
                image[i][j].rgbtBlue = 255 ;
            }

        }

    }

    return;
}
// swap the pixels in reflect function 
void swap(RGBTRIPLE *pixel_one, RGBTRIPLE *pixel_two)
{
    RGBTRIPLE tmp = *pixel_one;
    *pixel_one = *pixel_two;
    *pixel_two = tmp;
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height ; i++)
    {
        for (int j = 0, k = width - 1 ; j < k ; j++, k--)
        {
            swap(&image[i][j], &image[i][k]);
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //starting new image to save the blur pixels in it
    RGBTRIPLE new_image[height][width];
    
    // num of red pixels in the box blur we are analysing
    int red_pixels = 0;
    
    // num of green pixels in the box blur we are analysing
    int green_pixels = 0;
    
    // num of blue pixels in the box blur we are analysing
    int blue_pixels = 0;
    
    // num of valid pixels in the box blur
    double pixels_num = 0;
    
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            //counter for the height around the middle pixel in our blurbox  
            for (int k = -1; k <= 2 ; k++)
            {
                //counter for the width around the middle pixel in our blurbox
                for (int l = -1; l <= i ; l++)
                {
                    //check if the pixel is valid
                    if (k >= 0 && l >= 0 && k < height && l < width)
                    {
                        pixels_num++;
                        red_pixels += image[i + k][j + l].rgbtRed;
                        green_pixels += image[i + k][j + l].rgbtGreen;
                        blue_pixels += image[i + k][j + l].rgbtBlue; 
                    }
                }
            }
            //calculate the average RGB in each pixel to assigned it to our new image
            new_image[i][j].rgbtRed = round((double)red_pixels / pixels_num);
            new_image[i][j].rgbtGreen = round((double)green_pixels / pixels_num);
            new_image[i][j].rgbtBlue = round((double)blue_pixels / pixels_num);
          
        }
        
    }
    //assigned our new image to the image we want to display it
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            image[i][j].rgbtRed = new_image[i][j].rgbtRed;
            image[i][j].rgbtGreen = new_image[i][j].rgbtGreen;
            image[i][j].rgbtBlue = new_image[i][j].rgbtBlue ;   
        }
    }  
    return;
    
}
