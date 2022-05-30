#include "helpers.h"
#include <math.h>
#include <stdio.h>


RGBTRIPLE swap;


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE onepixel = image[i][j];
            float faverage = 0;
            int iaverage = 0;
            faverage = (onepixel.rgbtRed + onepixel.rgbtBlue + onepixel.rgbtGreen) / 3.0;
            iaverage = round(faverage);
            image[i][j].rgbtRed = iaverage;
            image[i][j].rgbtBlue = iaverage;
            image[i][j].rgbtGreen = iaverage;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            swap = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = swap;

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imagetwo[height][width];
    float fbluraverage;
    int ibluraverage;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imagetwo[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            //corners
            if ((i == 0) && (j == 0))
            {
                //Top left
                fbluraverage = (imagetwo[i][j].rgbtRed + imagetwo[i][j + 1].rgbtRed + imagetwo[i + 1][j].rgbtRed + imagetwo[i + 1][j + 1].rgbtRed) /
                               4.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtRed = ibluraverage;

                fbluraverage = (imagetwo[i][j].rgbtGreen + imagetwo[i][j + 1].rgbtGreen + imagetwo[i + 1][j].rgbtGreen + imagetwo[i + 1][j +
                                1].rgbtGreen) / 4.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtGreen = ibluraverage;

                fbluraverage = (imagetwo[i][j].rgbtBlue + imagetwo[i][j + 1].rgbtBlue + imagetwo[i + 1][j].rgbtBlue + imagetwo[i + 1][j +
                                1].rgbtBlue) / 4.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtBlue = ibluraverage;
            }
            else if ((i == height - 1) && (j == 0))
            {
                //Bottom left

                fbluraverage = (imagetwo[i][j].rgbtRed + imagetwo[i][j + 1].rgbtRed + imagetwo[i - 1][j].rgbtRed + imagetwo[i - 1][j + 1].rgbtRed) /
                               4.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtRed = ibluraverage;

                fbluraverage = (imagetwo[i][j].rgbtGreen + imagetwo[i][j + 1].rgbtGreen + imagetwo[i - 1][j].rgbtGreen + imagetwo[i - 1][j +
                                1].rgbtGreen) / 4.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtGreen = ibluraverage;

                fbluraverage = (imagetwo[i][j].rgbtBlue + imagetwo[i][j + 1].rgbtBlue + imagetwo[i - 1][j].rgbtBlue + imagetwo[i - 1][j +
                                1].rgbtBlue) / 4.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtBlue = ibluraverage;

            }
            else if ((i == 0) && (j == width - 1))
            {
                //Top right

                fbluraverage = (imagetwo[i][j].rgbtRed + imagetwo[i][j - 1].rgbtRed + imagetwo[i + 1][j].rgbtRed + imagetwo[i + 1][j - 1].rgbtRed) /
                               4.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtRed = ibluraverage;

                fbluraverage = (imagetwo[i][j].rgbtGreen + imagetwo[i][j - 1].rgbtGreen + imagetwo[i + 1][j].rgbtGreen + imagetwo[i + 1][j -
                                1].rgbtGreen) / 4.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtGreen = ibluraverage;

                fbluraverage = (imagetwo[i][j].rgbtBlue + imagetwo[i][j - 1].rgbtBlue + imagetwo[i + 1][j].rgbtBlue + imagetwo[i + 1][j -
                                1].rgbtBlue) / 4.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtBlue = ibluraverage;
            }
            else if ((i == height - 1) && (j == width - 1))
            {
                //Bottom right

                fbluraverage = (imagetwo[i][j].rgbtRed + imagetwo[i][j - 1].rgbtRed + imagetwo[i - 1][j].rgbtRed + imagetwo[i - 1][j - 1].rgbtRed) /
                               4.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtRed = ibluraverage;

                fbluraverage = (imagetwo[i][j].rgbtGreen + imagetwo[i][j - 1].rgbtGreen + imagetwo[i - 1][j].rgbtGreen + imagetwo[i - 1][j -
                                1].rgbtGreen) / 4.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtGreen = ibluraverage;

                fbluraverage = (imagetwo[i][j].rgbtBlue + imagetwo[i][j - 1].rgbtBlue + imagetwo[i - 1][j].rgbtBlue + imagetwo[i - 1][j -
                                1].rgbtBlue) / 4.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtBlue = ibluraverage;
            }


            //edges
            else if ((0 < i < height - 1) && (j == 0))
            {

                //Left Squish
                fbluraverage = (imagetwo[i][j].rgbtRed + imagetwo[i][j + 1].rgbtRed + imagetwo[i - 1][j].rgbtRed + imagetwo[i - 1][j + 1].rgbtRed +
                                imagetwo[i + 1][j].rgbtRed + imagetwo[i + 1][j + 1].rgbtRed) / 6.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtRed = ibluraverage;

                fbluraverage = (imagetwo[i][j].rgbtGreen + imagetwo[i][j + 1].rgbtGreen + imagetwo[i - 1][j].rgbtGreen + imagetwo[i - 1][j +
                                1].rgbtGreen + imagetwo[i + 1][j].rgbtGreen + imagetwo[i + 1][j + 1].rgbtGreen) / 6.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtGreen = ibluraverage;

                fbluraverage = (imagetwo[i][j].rgbtBlue + imagetwo[i][j + 1].rgbtBlue + imagetwo[i - 1][j].rgbtBlue + imagetwo[i - 1][j +
                                1].rgbtBlue + imagetwo[i + 1][j].rgbtBlue + imagetwo[i + 1][j + 1].rgbtBlue) / 6.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtBlue = ibluraverage;


            }
            else if ((0 < i < height - 1) && (j == width - 1))
            {
                //Right Squish

                fbluraverage = (imagetwo[i][j].rgbtRed + imagetwo[i][j - 1].rgbtRed + imagetwo[i - 1][j].rgbtRed + imagetwo[i - 1][j - 1].rgbtRed +
                                imagetwo[i + 1][j].rgbtRed + imagetwo[i + 1][j - 1].rgbtRed) / 6.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtRed = ibluraverage;

                fbluraverage = (imagetwo[i][j].rgbtGreen + imagetwo[i][j - 1].rgbtGreen + imagetwo[i - 1][j].rgbtGreen + imagetwo[i - 1][j -
                                1].rgbtGreen + imagetwo[i + 1][j].rgbtGreen + imagetwo[i + 1][j - 1].rgbtGreen) / 6.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtGreen = ibluraverage;

                fbluraverage = (imagetwo[i][j].rgbtBlue + imagetwo[i][j - 1].rgbtBlue + imagetwo[i - 1][j].rgbtBlue + imagetwo[i - 1][j -
                                1].rgbtBlue + imagetwo[i + 1][j].rgbtBlue + imagetwo[i + 1][j - 1].rgbtBlue) / 6.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtBlue = ibluraverage;

            }
            else if ((i == 0) && (0 < j < width - 1))
            {
                //Top Squish

                fbluraverage = (imagetwo[i][j].rgbtRed + imagetwo[i][j + 1].rgbtRed + imagetwo[i][j - 1].rgbtRed + imagetwo[i + 1][j].rgbtRed +
                                imagetwo[i + 1][j + 1].rgbtRed + imagetwo[i + 1][j - 1].rgbtRed) / 6.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtRed = ibluraverage;

                fbluraverage = (imagetwo[i][j].rgbtGreen + imagetwo[i][j + 1].rgbtGreen + imagetwo[i][j - 1].rgbtGreen + imagetwo[i +
                                1][j].rgbtGreen + imagetwo[i + 1][j + 1].rgbtGreen + imagetwo[i + 1][j - 1].rgbtGreen) / 6.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtGreen = ibluraverage;

                fbluraverage = (imagetwo[i][j].rgbtBlue + imagetwo[i][j + 1].rgbtBlue + imagetwo[i][j - 1].rgbtBlue + imagetwo[i + 1][j].rgbtBlue +
                                imagetwo[i + 1][j + 1].rgbtBlue + imagetwo[i + 1][j - 1].rgbtBlue) / 6.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtBlue = ibluraverage;

            }
            else if ((i == height - 1) && (0 < j < width - 1))
            {
                //Bottom Squish

                fbluraverage = (imagetwo[i][j].rgbtRed + imagetwo[i][j + 1].rgbtRed + imagetwo[i][j - 1].rgbtRed + imagetwo[i - 1][j].rgbtRed +
                                imagetwo[i - 1][j + 1].rgbtRed + imagetwo[i - 1][j - 1].rgbtRed) / 6.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtRed = ibluraverage;

                fbluraverage = (imagetwo[i][j].rgbtGreen + imagetwo[i][j + 1].rgbtGreen + imagetwo[i][j - 1].rgbtGreen + imagetwo[i -
                                1][j].rgbtGreen + imagetwo[i - 1][j + 1].rgbtGreen + imagetwo[i - 1][j - 1].rgbtGreen) / 6.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtGreen = ibluraverage;

                fbluraverage = (imagetwo[i][j].rgbtBlue + imagetwo[i][j + 1].rgbtBlue + imagetwo[i][j - 1].rgbtBlue + imagetwo[i - 1][j].rgbtBlue +
                                imagetwo[i - 1][j + 1].rgbtBlue + imagetwo[i - 1][j - 1].rgbtBlue) / 6.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtBlue = ibluraverage;

            }
            else
            {
                fbluraverage = (imagetwo[i][j].rgbtRed + imagetwo[i - 1][j].rgbtRed + imagetwo[i + 1][j].rgbtRed + imagetwo[i][j - 1].rgbtRed +
                                imagetwo[i][j + 1].rgbtRed + imagetwo[i - 1][j - 1].rgbtRed + imagetwo[i - 1][j + 1].rgbtRed + imagetwo[i + 1][j - 1].rgbtRed +
                                imagetwo[i + 1][j + 1].rgbtRed) / 9.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtRed = ibluraverage;

                fbluraverage = (imagetwo[i][j].rgbtGreen + imagetwo[i - 1][j].rgbtGreen + imagetwo[i + 1][j].rgbtGreen + imagetwo[i][j -
                                1].rgbtGreen + imagetwo[i][j + 1].rgbtGreen + imagetwo[i - 1][j - 1].rgbtGreen + imagetwo[i - 1][j + 1].rgbtGreen + imagetwo[i +
                                        1][j - 1].rgbtGreen + imagetwo[i + 1][j + 1].rgbtGreen) / 9.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtGreen = ibluraverage;

                fbluraverage = (imagetwo[i][j].rgbtBlue + imagetwo[i - 1][j].rgbtBlue + imagetwo[i + 1][j].rgbtBlue + imagetwo[i][j - 1].rgbtBlue +
                                imagetwo[i][j + 1].rgbtBlue + imagetwo[i - 1][j - 1].rgbtBlue + imagetwo[i - 1][j + 1].rgbtBlue + imagetwo[i + 1][j - 1].rgbtBlue +
                                imagetwo[i + 1][j + 1].rgbtBlue) / 9.0;
                ibluraverage = round(fbluraverage);
                image[i][j].rgbtBlue = ibluraverage;
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imagetwo[height][width];
    float gx;
    float gy;
    float squaredg;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imagetwo[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if ((i == 0) && (j == 0))
            {
                //Top left
                // Remember I = 0 and J = 0
                gx = (0.0 * (imagetwo[i][j].rgbtRed) + 0.0 * (0) + 2.0 * (imagetwo[i][j + 1].rgbtRed) + 0.0 * (0) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 0.0 * (imagetwo[i + 1][j].rgbtRed) + 1.0 * (imagetwo[i + 1][j + 1].rgbtRed));
                gy = (0.0 * (imagetwo[i][j].rgbtRed) + 0.0 * (0) + 0.0 * (imagetwo[i][j + 1].rgbtRed) + 0.0 * (0) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 2.0 * (imagetwo[i + 1][j].rgbtRed) + 1.0 * (imagetwo[i + 1][j + 1].rgbtRed));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtRed = round(squaredg);

                }
                else
                {
                    image[i][j].rgbtRed = 255;
                }

                gx = (0.0 * (imagetwo[i][j].rgbtGreen) + 0.0 * (0) + 2.0 * (imagetwo[i][j + 1].rgbtGreen) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 0.0 * (0) + 0.0 * (imagetwo[i + 1][j].rgbtGreen) + 1.0 * (imagetwo[i + 1][j + 1].rgbtGreen));
                gy = (0.0 * (imagetwo[i][j].rgbtGreen) + 0.0 * (0) + 0.0 * (imagetwo[i][j + 1].rgbtGreen) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 0.0 * (0) + 2.0 * (imagetwo[i + 1][j].rgbtGreen) + 1.0 * (imagetwo[i + 1][j + 1].rgbtGreen));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtGreen = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtGreen = 255;
                }

                gx = (0.0 * (imagetwo[i][j].rgbtBlue) + 0.0 * (0) + 2.0 * (imagetwo[i][j + 1].rgbtBlue) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 0.0 * (0) + 0.0 * (imagetwo[i + 1][j].rgbtBlue) + 1.0 * (imagetwo[i + 1][j + 1].rgbtBlue));
                gy = (0.0 * (imagetwo[i][j].rgbtBlue) + 0.0 * (0) + 0.0 * (imagetwo[i][j + 1].rgbtBlue) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 0.0 * (0) + 2.0 * (imagetwo[i + 1][j].rgbtBlue) + 1.0 * (imagetwo[i + 1][j + 1].rgbtBlue));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtBlue = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtBlue = 255;
                }

            }
            else if ((i == height - 1) && (j == 0))
            {
                // Remember J = 0
                //Bottom left
                gx = (0.0 * (imagetwo[i][j].rgbtRed) + 0.0 * (0) + 2.0 * (imagetwo[i][j + 1].rgbtRed) + 0.0 * (0) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 0.0 * (imagetwo[i - 1][j].rgbtRed) + 1.0 * (imagetwo[i - 1][j + 1].rgbtRed));
                gy = (0.0 * (imagetwo[i][j].rgbtRed) + 0.0 * (0) + 0.0 * (imagetwo[i][j + 1].rgbtRed) + 0.0 * (0) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + -2.0 * (imagetwo[i - 1][j].rgbtRed) + -1.0 * (imagetwo[i - 1][j + 1].rgbtRed));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtRed = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtRed = 255;
                }

                gx = (0.0 * (imagetwo[i][j].rgbtGreen) + 0.0 * (0) + 2.0 * (imagetwo[i][j + 1].rgbtGreen) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 0.0 * (0) + 0.0 * (imagetwo[i - 1][j].rgbtGreen) + 1.0 * (imagetwo[i - 1][j + 1].rgbtGreen));
                gy = (0.0 * (imagetwo[i][j].rgbtGreen) + 0.0 * (0) + 0.0 * (imagetwo[i][j + 1].rgbtGreen) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 0.0 * (0) + -2.0 * (imagetwo[i - 1][j].rgbtGreen) + -1.0 * (imagetwo[i - 1][j + 1].rgbtGreen));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtGreen = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtGreen = 255;
                }

                gx = (0.0 * (imagetwo[i][j].rgbtBlue) + 0.0 * (0) + 2.0 * (imagetwo[i][j + 1].rgbtBlue) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 0.0 * (0) + 0.0 * (imagetwo[i - 1][j].rgbtBlue) + 1.0 * (imagetwo[i - 1][j + 1].rgbtBlue));
                gy = (0.0 * (imagetwo[i][j].rgbtBlue) + 0.0 * (0) + 0.0 * (imagetwo[i][j + 1].rgbtBlue) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 0.0 * (0) + -2.0 * (imagetwo[i - 1][j].rgbtBlue) + -1.0 * (imagetwo[i - 1][j + 1].rgbtBlue));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtBlue = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtBlue = 255;
                }

            }
            else if ((i == 0) && (j == width - 1))
            {
                // Remember I = 0
                //Top right

                gx = (0.0 * (imagetwo[i][j].rgbtRed) + 0.0 * (0) + -2.0 * (imagetwo[i][j - 1].rgbtRed) + 0.0 * (0) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 0.0 * (imagetwo[i + 1][j].rgbtRed) + -1.0 * (imagetwo[i + 1][j - 1].rgbtRed));
                gy = (0.0 * (imagetwo[i][j].rgbtRed) + 0.0 * (0) + 0.0 * (imagetwo[i][j - 1].rgbtRed) + 0.0 * (0) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 2.0 * (imagetwo[i + 1][j].rgbtRed) + 1.0 * (imagetwo[i + 1][j - 1].rgbtRed));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtRed = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtRed = 255;
                }

                gx = (0.0 * (imagetwo[i][j].rgbtGreen) + 0.0 * (0) + -2.0 * (imagetwo[i][j - 1].rgbtGreen) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 0.0 * (0) + 0.0 * (imagetwo[i + 1][j].rgbtGreen) + -1.0 * (imagetwo[i + 1][j - 1].rgbtGreen));
                gy = (0.0 * (imagetwo[i][j].rgbtGreen) + 0.0 * (0) + 0.0 * (imagetwo[i][j - 1].rgbtGreen) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 0.0 * (0) + 2.0 * (imagetwo[i + 1][j].rgbtGreen) + 1.0 * (imagetwo[i + 1][j - 1].rgbtGreen));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtGreen = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtGreen = 255;
                }

                gx = (0.0 * (imagetwo[i][j].rgbtBlue) + 0.0 * (0) + -2.0 * (imagetwo[i][j - 1].rgbtBlue) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 0.0 * (0) + 0.0 * (imagetwo[i + 1][j].rgbtBlue) + -1.0 * (imagetwo[i + 1][j - 1].rgbtBlue));
                gy = (0.0 * (imagetwo[i][j].rgbtBlue) + 0.0 * (0) + 0.0 * (imagetwo[i][j - 1].rgbtBlue) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 0.0 * (0) + 2.0 * (imagetwo[i + 1][j].rgbtBlue) + 1.0 * (imagetwo[i + 1][j - 1].rgbtBlue));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtBlue = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtBlue = 255;
                }

            }
            else if ((i == height - 1) && (j == width - 1))
            {
                //Bottom right

                gx = (0.0 * (imagetwo[i][j].rgbtRed) + 0.0 * (0) + -2.0 * (imagetwo[i][j - 1].rgbtRed) + 0.0 * (0) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 0.0 * (imagetwo[i - 1][j].rgbtRed) + -1.0 * (imagetwo[i - 1][j - 1].rgbtRed));
                gy = (0.0 * (imagetwo[i][j].rgbtRed) + 0.0 * (0) + 0.0 * (imagetwo[i][j - 1].rgbtRed) + 0.0 * (0) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + -2.0 * (imagetwo[i - 1][j].rgbtRed) + -1.0 * (imagetwo[i - 1][j - 1].rgbtRed));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtRed = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtRed = 255;
                }

                gx = (0.0 * (imagetwo[i][j].rgbtGreen) + 0.0 * (0) + -2.0 * (imagetwo[i][j - 1].rgbtGreen) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 0.0 * (0) + 0.0 * (imagetwo[i - 1][j].rgbtGreen) + -1.0 * (imagetwo[i - 1][j - 1].rgbtGreen));
                gy = (0.0 * (imagetwo[i][j].rgbtGreen) + 0.0 * (0) + 0.0 * (imagetwo[i][j - 1].rgbtGreen) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 0.0 * (0) + -2.0 * (imagetwo[i - 1][j].rgbtGreen) + -1.0 * (imagetwo[i - 1][j - 1].rgbtGreen));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtGreen = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtGreen = 255;
                }

                gx = (0.0 * (imagetwo[i][j].rgbtBlue) + 0.0 * (0) + -2.0 * (imagetwo[i][j - 1].rgbtBlue) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 0.0 * (0) + 0.0 * (imagetwo[i - 1][j].rgbtBlue) + -1.0 * (imagetwo[i - 1][j - 1].rgbtBlue));
                gy = (0.0 * (imagetwo[i][j].rgbtBlue) + 0.0 * (0) + 0.0 * (imagetwo[i][j - 1].rgbtBlue) + 0.0 * (0) + 0.0 * (0) + 0.0 *
                      (0) + 0.0 * (0) + -2.0 * (imagetwo[i - 1][j].rgbtBlue) + -1.0 * (imagetwo[i - 1][j - 1].rgbtBlue));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtBlue = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtBlue = 255;
                }
            }
            //edges
            else if ((0 < i < height - 1) && (j == 0))
            {
                // Remember J = 0
                //Left Squish
                gx = (0 * (imagetwo[i][j].rgbtRed) + 0 * (0) + 2 * (imagetwo[i][j + 1].rgbtRed) + 0 * (imagetwo[i - 1][j].rgbtRed) + 1 *
                      (imagetwo[i - 1][j + 1].rgbtRed) + 0 * (0) + 0 * (0) + 0 * (imagetwo[i + 1][j].rgbtRed) + 1 * (imagetwo[i + 1][j + 1].rgbtRed));
                gy = (0 * (imagetwo[i][j].rgbtRed) + 0 * (0) + 0 * (imagetwo[i][j + 1].rgbtRed) + -2 * (imagetwo[i - 1][j].rgbtRed) + -1 *
                      (imagetwo[i - 1][j + 1].rgbtRed) + 0 * (0) + 0 * (0) + 2 * (imagetwo[i + 1][j].rgbtRed) + 1 * (imagetwo[i + 1][j + 1].rgbtRed));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtRed = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtRed = 255;
                }

                gx = (0 * (imagetwo[i][j].rgbtGreen) + 0 * (0) + 2 * (imagetwo[i][j + 1].rgbtGreen) + 0 * (imagetwo[i - 1][j].rgbtGreen) + 1 *
                      (imagetwo[i - 1][j + 1].rgbtGreen) + 0 * (0) + 0 * (0) + 0 * (imagetwo[i + 1][j].rgbtGreen) + 1 *
                      (imagetwo[i + 1][j + 1].rgbtGreen));
                gy = (0 * (imagetwo[i][j].rgbtGreen) + 0 * (0) + 0 * (imagetwo[i][j + 1].rgbtGreen) + -2 * (imagetwo[i - 1][j].rgbtGreen) + -1 *
                      (imagetwo[i - 1][j + 1].rgbtGreen) + 0 * (0) + 0 * (0) + 2 * (imagetwo[i + 1][j].rgbtGreen) + 1 *
                      (imagetwo[i + 1][j + 1].rgbtGreen));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtGreen = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtGreen = 255;
                }

                gx = (0 * (imagetwo[i][j].rgbtBlue) + 0 * (0) + 2 * (imagetwo[i][j + 1].rgbtBlue) + 0 * (imagetwo[i - 1][j].rgbtBlue) + 1 *
                      (imagetwo[i - 1][j + 1].rgbtBlue) + 0 * (0) + 0 * (0) + 0 * (imagetwo[i + 1][j].rgbtBlue) + 1 * (imagetwo[i + 1][j + 1].rgbtBlue));
                gy = (0 * (imagetwo[i][j].rgbtBlue) + 0 * (0) + 0 * (imagetwo[i][j + 1].rgbtBlue) + -2 * (imagetwo[i - 1][j].rgbtBlue) + -1 *
                      (imagetwo[i - 1][j + 1].rgbtBlue) + 0 * (0) + 0 * (0) + 2 * (imagetwo[i + 1][j].rgbtBlue) + 1 * (imagetwo[i + 1][j + 1].rgbtBlue));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtBlue = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtBlue = 255;
                }


            }
            else if ((0 < i < height - 1) && (j == width - 1))
            {
                //Right Squish
                gx = (0.0 * (imagetwo[i][j].rgbtRed) + 0 * (0) + -2 * (imagetwo[i][j - 1].rgbtRed) + 0 * (imagetwo[i - 1][j].rgbtRed) + -1 *
                      (imagetwo[i - 1][j - 1].rgbtRed) + 0 * (0) + 0 * (0) + 0 * (imagetwo[i + 1][j].rgbtRed) + -1 * (imagetwo[i + 1][j - 1].rgbtRed));
                gy = (0 * (imagetwo[i][j].rgbtRed) + 0 * (0) + 0 * (imagetwo[i][j - 1].rgbtRed) + -2 * (imagetwo[i - 1][j].rgbtRed) + -1 *
                      (imagetwo[i - 1][j - 1].rgbtRed) + 0 * (0) + 0 * (0) + 2 * (imagetwo[i + 1][j].rgbtRed) + 1 * (imagetwo[i + 1][j - 1].rgbtRed));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtRed = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtRed = 255;
                }

                gx = (0.0 * (imagetwo[i][j].rgbtGreen) + 0 * (0) + -2 * (imagetwo[i][j - 1].rgbtGreen) + 0 * (imagetwo[i - 1][j].rgbtGreen) + -1 *
                      (imagetwo[i - 1][j - 1].rgbtGreen) + 0 * (0) + 0 * (0) + 0 * (imagetwo[i + 1][j].rgbtGreen) + -1 *
                      (imagetwo[i + 1][j - 1].rgbtGreen));
                gy = (0 * (imagetwo[i][j].rgbtGreen) + 0 * (0) + 0 * (imagetwo[i][j - 1].rgbtGreen) + -2 * (imagetwo[i - 1][j].rgbtGreen) + -1 *
                      (imagetwo[i - 1][j - 1].rgbtGreen) + 0 * (0) + 0 * (0) + 2 * (imagetwo[i + 1][j].rgbtGreen) + 1 *
                      (imagetwo[i + 1][j - 1].rgbtGreen));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtGreen = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtGreen = 255;
                }

                gx = (0.0 * (imagetwo[i][j].rgbtBlue) + 0 * (0) + -2 * (imagetwo[i][j - 1].rgbtBlue) + 0 * (imagetwo[i - 1][j].rgbtBlue) + -1 *
                      (imagetwo[i - 1][j - 1].rgbtBlue) + 0 * (0) + 0 * (0) + 0 * (imagetwo[i + 1][j].rgbtBlue) + -1 * (imagetwo[i + 1][j - 1].rgbtBlue));
                gy = (0 * (imagetwo[i][j].rgbtBlue) + 0 * (0) + 0 * (imagetwo[i][j - 1].rgbtBlue) + -2 * (imagetwo[i - 1][j].rgbtBlue) + -1 *
                      (imagetwo[i - 1][j - 1].rgbtBlue) + 0 * (0) + 0 * (0) + 2 * (imagetwo[i + 1][j].rgbtBlue) + 1 * (imagetwo[i + 1][j - 1].rgbtBlue));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtBlue = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtBlue = 255;
                }
            }
            else if ((i == 0) && (0 < j < width - 1))
            {
                //Top Squish

                gx = (0 * (imagetwo[i][j].rgbtRed) + 0 * (0) + -2 * (imagetwo[i][j - 1].rgbtRed) + 2 * (imagetwo[i][j + 1].rgbtRed) + 0 *
                      (imagetwo[i + 1][j].rgbtRed) + 0 * (0) + 0 * (0) + -1 * (imagetwo[i + 1][j - 1].rgbtRed) + 1 * (imagetwo[i + 1][j + 1].rgbtRed));
                gy = (0 * (imagetwo[i][j].rgbtRed) + 0 * (0) + 0 * (imagetwo[i][j - 1].rgbtRed) + 0 * (imagetwo[i][j + 1].rgbtRed) + 2 *
                      (imagetwo[i + 1][j].rgbtRed) + 0 * (0) + 0 * (0) + 1 * (imagetwo[i + 1][j - 1].rgbtRed) + 1 * (imagetwo[i + 1][j + 1].rgbtRed));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtRed = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtRed = 255;
                }

                gx = (0 * (imagetwo[i][j].rgbtGreen) + 0 * (0) + -2 * (imagetwo[i][j - 1].rgbtGreen) + 2 * (imagetwo[i][j + 1].rgbtGreen) + 0 *
                      (imagetwo[i + 1][j].rgbtGreen) + 0 * (0) + 0 * (0) + -1 * (imagetwo[i + 1][j - 1].rgbtGreen) + 1 *
                      (imagetwo[i + 1][j + 1].rgbtGreen));
                gy = (0 * (imagetwo[i][j].rgbtGreen) + 0 * (0) + 0 * (imagetwo[i][j - 1].rgbtGreen) + 0 * (imagetwo[i][j + 1].rgbtGreen) + 2 *
                      (imagetwo[i + 1][j].rgbtGreen) + 0 * (0) + 0 * (0) + 1 * (imagetwo[i + 1][j - 1].rgbtGreen) + 1 *
                      (imagetwo[i + 1][j + 1].rgbtGreen));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtGreen = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtGreen = 255;
                }

                gx = (0 * (imagetwo[i][j].rgbtBlue) + 0 * (0) + -2 * (imagetwo[i][j - 1].rgbtBlue) + 2 * (imagetwo[i][j + 1].rgbtBlue) + 0 *
                      (imagetwo[i + 1][j].rgbtBlue) + 0 * (0) + 0 * (0) + -1 * (imagetwo[i + 1][j - 1].rgbtBlue) + 1 * (imagetwo[i + 1][j + 1].rgbtBlue));
                gy = (0 * (imagetwo[i][j].rgbtBlue) + 0 * (0) + 0 * (imagetwo[i][j - 1].rgbtBlue) + 0 * (imagetwo[i][j + 1].rgbtBlue) + 2 *
                      (imagetwo[i + 1][j].rgbtBlue) + 0 * (0) + 0 * (0) + 1 * (imagetwo[i + 1][j - 1].rgbtBlue) + 1 * (imagetwo[i + 1][j + 1].rgbtBlue));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtBlue = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtBlue = 255;
                }
            }
            else if ((i == height - 1) && (0 < j < width - 1))
            {
                //Bottom Squish

                gx = (0 * (imagetwo[i][j].rgbtRed) + 0 * (0) + -2 * (imagetwo[i][j - 1].rgbtRed) + 2 * (imagetwo[i][j + 1].rgbtRed) + 0 *
                      (imagetwo[i - 1][j].rgbtRed) + 0 * (0) + 0 * (0) + -1 * (imagetwo[i - 1][j - 1].rgbtRed) + 1 * (imagetwo[i - 1][j + 1].rgbtRed));
                gy = (0 * (imagetwo[i][j].rgbtRed) + 0 * (0) + 0 * (imagetwo[i][j - 1].rgbtRed) + 0 * (imagetwo[i][j + 1].rgbtRed) + -2 *
                      (imagetwo[i - 1][j].rgbtRed) + 0 * (0) + 0 * (0) + -1 * (imagetwo[i - 1][j - 1].rgbtRed) + -1 * (imagetwo[i - 1][j + 1].rgbtRed));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtRed = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtRed = 255;
                }

                gx = (0 * (imagetwo[i][j].rgbtGreen) + 0 * (0) + -2 * (imagetwo[i][j - 1].rgbtGreen) + 2 * (imagetwo[i][j + 1].rgbtGreen) + 0 *
                      (imagetwo[i - 1][j].rgbtGreen) + 0 * (0) + 0 * (0) + -1 * (imagetwo[i - 1][j - 1].rgbtGreen) + 1 *
                      (imagetwo[i - 1][j + 1].rgbtGreen));
                gy = (0 * (imagetwo[i][j].rgbtGreen) + 0 * (0) + 0 * (imagetwo[i][j - 1].rgbtGreen) + 0 * (imagetwo[i][j + 1].rgbtGreen) + -2 *
                      (imagetwo[i - 1][j].rgbtGreen) + 0 * (0) + 0 * (0) + -1 * (imagetwo[i - 1][j - 1].rgbtGreen) + -1 *
                      (imagetwo[i - 1][j + 1].rgbtGreen));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtGreen = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtGreen = 255;
                }

                gx = (0 * (imagetwo[i][j].rgbtBlue) + 0 * (0) + -2 * (imagetwo[i][j - 1].rgbtBlue) + 2 * (imagetwo[i][j + 1].rgbtBlue) + 0 *
                      (imagetwo[i - 1][j].rgbtBlue) + 0 * (0) + 0 * (0) + -1 * (imagetwo[i - 1][j - 1].rgbtBlue) + 1 * (imagetwo[i - 1][j + 1].rgbtBlue));
                gy = (0 * (imagetwo[i][j].rgbtBlue) + 0 * (0) + 0 * (imagetwo[i][j - 1].rgbtBlue) + 0 * (imagetwo[i][j + 1].rgbtBlue) + -2 *
                      (imagetwo[i - 1][j].rgbtBlue) + 0 * (0) + 0 * (0) + -1 * (imagetwo[i - 1][j - 1].rgbtBlue) + -1 *
                      (imagetwo[i - 1][j + 1].rgbtBlue));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtBlue = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtBlue = 255;
                }
            }
            else
            {
                // Neither J or I are 0
                gx = (0 * (imagetwo[i][j].rgbtRed) + -2 * (imagetwo[i][j - 1].rgbtRed) + 2 * (imagetwo[i][j + 1].rgbtRed) + 0 *
                      (imagetwo[i - 1][j].rgbtRed) + 1 * (imagetwo[i - 1][j + 1].rgbtRed) + -1 * (imagetwo[i - 1][j - 1].rgbtRed) + -1 *
                      (imagetwo[i + 1][j - 1].rgbtRed) + 0 * (imagetwo[i + 1][j].rgbtRed) + 1 * (imagetwo[i + 1][j + 1].rgbtRed));
                gy = (0 * (imagetwo[i][j].rgbtRed) + 0 * (imagetwo[i][j - 1].rgbtRed) + 0 * (imagetwo[i][j + 1].rgbtRed) + -2 *
                      (imagetwo[i - 1][j].rgbtRed) + -1 * (imagetwo[i - 1][j + 1].rgbtRed) + -1 * (imagetwo[i - 1][j - 1].rgbtRed) + 1 *
                      (imagetwo[i + 1][j - 1].rgbtRed) + 2 * (imagetwo[i + 1][j].rgbtRed) + 1 * (imagetwo[i + 1][j + 1].rgbtRed));
                squaredg = sqrt((gx * gx) + (gy * gy));
                if (squaredg <= 255)
                {
                    image[i][j].rgbtRed = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtRed = 255;
                }

                gx = (0 * (imagetwo[i][j].rgbtGreen) + -2 * (imagetwo[i][j - 1].rgbtGreen) + 2 * (imagetwo[i][j + 1].rgbtGreen) + 0 *
                      (imagetwo[i - 1][j].rgbtGreen) + 1 * (imagetwo[i - 1][j + 1].rgbtGreen) + -1 * (imagetwo[i - 1][j - 1].rgbtGreen) + -1 *
                      (imagetwo[i + 1][j - 1].rgbtGreen) + 0 * (imagetwo[i + 1][j].rgbtGreen) + 1 * (imagetwo[i + 1][j + 1].rgbtGreen));
                gy = (0 * (imagetwo[i][j].rgbtGreen) + 0 * (imagetwo[i][j - 1].rgbtGreen) + 0 * (imagetwo[i][j + 1].rgbtGreen) + -2 *
                      (imagetwo[i - 1][j].rgbtGreen) + -1 * (imagetwo[i - 1][j + 1].rgbtGreen) + -1 * (imagetwo[i - 1][j - 1].rgbtGreen) + 1 *
                      (imagetwo[i + 1][j - 1].rgbtGreen) + 2 * (imagetwo[i + 1][j].rgbtGreen) + 1 * (imagetwo[i + 1][j + 1].rgbtGreen));
                squaredg = sqrt((gx * gx) + (gy * gy));

                if (squaredg <= 255)
                {
                    image[i][j].rgbtGreen = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtGreen = 255;
                }

                gx = (0 * (imagetwo[i][j].rgbtBlue) + -2 * (imagetwo[i][j - 1].rgbtBlue) + 2 * (imagetwo[i][j + 1].rgbtBlue) + 0 *
                      (imagetwo[i - 1][j].rgbtBlue) + 1 * (imagetwo[i - 1][j + 1].rgbtBlue) + -1 * (imagetwo[i - 1][j - 1].rgbtBlue) + -1 *
                      (imagetwo[i + 1][j - 1].rgbtBlue) + 0 * (imagetwo[i + 1][j].rgbtBlue) + 1 * (imagetwo[i + 1][j + 1].rgbtBlue));
                gy = (0 * (imagetwo[i][j].rgbtBlue) + 0 * (imagetwo[i][j - 1].rgbtBlue) + 0 * (imagetwo[i][j + 1].rgbtBlue) + -2 *
                      (imagetwo[i - 1][j].rgbtBlue) + -1 * (imagetwo[i - 1][j + 1].rgbtBlue) + -1 * (imagetwo[i - 1][j - 1].rgbtBlue) + 1 *
                      (imagetwo[i + 1][j - 1].rgbtBlue) + 2 * (imagetwo[i + 1][j].rgbtBlue) + 1 * (imagetwo[i + 1][j + 1].rgbtBlue));
                squaredg = sqrt((gx * gx) + (gy * gy));

                if (squaredg <= 255)
                {
                    image[i][j].rgbtBlue = round(squaredg);
                }
                else
                {
                    image[i][j].rgbtBlue = 255;
                }
            }
        }
    }

    return;
}
