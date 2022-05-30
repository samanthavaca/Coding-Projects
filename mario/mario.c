#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //question asked
    float height = get_float("Height: ");
    //if the height is more than 8 it repeats
    if (height > 8)
    {
        height = get_float("Height: ");
    }
    //if the height is less than 1 it repeats
    if (height < 1)
    {
        height = get_float("Height: ");
    }
    //1-8 pyramids
    //1 pyramid
    if (height == 1)
    {
        printf("#  #\n");
    }
    //2 pyramid
    if (height == 2)
    {
        printf(" #  #\n##  ##\n");
    }
    //3 pyramid
    if (height == 3)
    {
        printf("  #  #\n ##  ##\n###  ###\n");
    }
    //4 pyramid
    if (height == 4)
    {
        printf("   #  #\n  ##  ##\n ###  ###\n####  ####\n");
    }
    //5 pyramid
    if (height == 5)
    {
        printf("    #  #\n   ##  ##\n  ###  ###\n ####  ####\n#####  #####\n");
    }
    //6 pyramid
    if (height == 6)
    {
        printf("     #  #\n    ##  ##\n   ###  ###\n  ####  ####\n #####  #####\n######  ######\n");
    }
    //7 pyramid
    if (height == 7)
    {
        printf("       #  #\n      ##  ##\n     ###  ###\n    ####  ####\n   #####  #####\n  ######  ######\n #######  #######\n");
    }
    //8 pyramid
    if (height == 8)
    {
        printf("       #  #\n      ##  ##\n     ###  ###\n    ####  ####\n   #####  #####\n  ######  ######\n #######  #######\n########  ########\n");
    } 

}
