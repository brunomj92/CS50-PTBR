#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int line = 0; line < height; line++)
    {
        for (int col = 0; col < width; col++)
        {
           int rgbt = round((image[line][col].rgbtBlue + image[line][col].rgbtGreen + image[line][col].rgbtRed) / 3.0);
           image[line][col].rgbtRed = image[line][col].rgbtGreen = image[line][col].rgbtBlue = rgbt;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            int sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            int sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    if (width %2 == 0)
    {
        for (int line = 0; line < height; line++)
        {
            for (int col = 0; col < width / 2; col++)
            {
                RGBTRIPLE temp = image[line][col];
                image[line][col] = image[line][width - (col + 1)];
                image[line][width - (col + 1)] = temp;
            }
        }
    }
    else
    {
        for (int line = 0; line < height; line++)
        {
            for (int col = 0; col < (width - 1) / 2; col++)
            {
                RGBTRIPLE temp = image[line][col];
                image[line][col] = image[line][width - (col + 1)];
                image[line][width - (col + 1)] = temp;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE avg[height][width];
    for (int line = 0; line < height; line++)
    {
        for (int col = 0; col < width; col++)
        {
            float sumBlue = 0;
            float sumGreen = 0;
            float sumRed = 0;
            float count = 0;
            for (int r = -1; r < 2; r++)
            {
                if (line + r < 0 || line + r == height)
                {
                    continue;
                }
                for (int c = -1; c < 2; c++)
                {
                    if (col + c < 0 || col + c == width)
                    {
                        continue;
                    }
                    sumBlue += image[line + r][col + c].rgbtBlue;
                    sumGreen += image[line + r][col + c].rgbtGreen;
                    sumRed += image[line + r][col + c].rgbtRed;
                    count++;
                }
            }
            avg[line][col].rgbtBlue = (int)round(sumBlue/(float)count);
            avg[line][col].rgbtGreen = (int)round(sumGreen/(float)count);
            avg[line][col].rgbtRed = (int)round(sumRed/(float)count);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = avg[i][j].rgbtBlue;
            image[i][j].rgbtGreen = avg[i][j].rgbtGreen;
            image[i][j].rgbtRed = avg[i][j].rgbtRed;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //fora da imagem tem valores 0
    RGBTRIPLE temp[height][width];
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int gxBlue = 0;
            int gxGreen = 0;
            int gxRed = 0;
            int gyBlue = 0;
            int gyGreen = 0;
            int gyRed = 0;
            for (int r = -1; r < 2; r++)
            {
                if (row + r < 0 || row + r == height)
                {
                    continue;
                }
                for (int c = -1; c < 2; c++)
                {
                    if (col + c < 0 || col + c == width)
                    {
                        continue;
                    }
                    gxBlue += (image[row + r][col + c].rgbtBlue * gx[r + 1][c + 1]);
                    gxGreen += (image[row + r][col + c].rgbtGreen * gx[r + 1][c + 1]);
                    gxRed += (image[row + r][col + c].rgbtRed * gx[r + 1][c + 1]);
                    gyBlue += (image[row + r][col + c].rgbtBlue * gy[r + 1][c + 1]);
                    gyGreen += (image[row + r][col + c].rgbtGreen * gy[r + 1][c + 1]);
                    gyRed += (image[row + r][col + c].rgbtRed * gy[r + 1][c + 1]);
                }
            }
            int vBlue = round(sqrt((gxBlue * gxBlue) + (gyBlue * gyBlue)));
            int vGreen = round(sqrt((gxGreen * gxGreen) + (gyGreen * gyGreen)));
            int vRed = round(sqrt((gxRed * gxRed) + (gyRed * gyRed)));
            if (vBlue > 255)
            {
                vBlue = 255;
            }
            if (vGreen > 255)
            {
                vGreen = 255;
            }
            if (vRed > 255)
            {
                vRed = 255;
            }
            temp[row][col].rgbtBlue = vBlue;
            temp[row][col].rgbtGreen = vGreen;
            temp[row][col].rgbtRed = vRed;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
    return;
}
