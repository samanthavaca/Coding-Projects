#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{

    //variables

    char l[200];
    int count = 0, i;
    int index = 0;
    float index1 = 0, roundValue;
    int countletters = 0, w;
    int countothers = 0, e;
    int countwords = 0, s;
    int onecharacter;
    int finall = 0;
    int finals = 0;

    //getting input

    string phrase = get_string("Text: ");

    //checking sentences

    for (i = 0; phrase[i] != '\0'; i++)
    {
        if (phrase[i] == '.' && phrase[i + 1] != '.')
        {
            count++;
        }

        if (phrase[i] == '!' && phrase[i + 1] != '!')
        {
            count++;
        }

        if (phrase[i] == '?' && phrase[i + 1] != '?')
        {
            count++;
        }
    }

    //checking letters

    for (w = 0; phrase[w] != '\0'; w++)
    {
        if (phrase[w] != ' ')
        {
            countletters++;
        }

    }

    //checking others

    for (e = 0; phrase[e] != '\0'; e++)
    {
        onecharacter = phrase[e];
        if ((onecharacter <= 64 && onecharacter != 32) || (onecharacter >= 91 && onecharacter <= 96) || (onecharacter >= 123))
        {
            countothers++;
        }

    }

    //checking words

    for (s = 0; phrase[s] != '\0'; s++)
    {
        if (phrase[s] == ' ' && phrase[s + 1] != ' ')
        {
            countwords++;
        }
    }

    //subtracting others

    countletters = countletters - countothers;
    if (countwords > 0)
    {
        countwords = countwords + 1;
    }

    //doing the math

    index1 = 0.0588 * countletters / countwords * 100 - 0.296 * count / countwords * 100 - 15.8;

    //getting the results

    if (round(index1) < 1)
    {
        printf("Before Grade 1\n");
    }

    if (round(index1) == 1)
    {
        printf("Grade 1\n");
    }

    if (round(index1) == 2)
    {
        printf("Grade 2\n");
    }

    if (round(index1) == 3)
    {
        printf("Grade 3\n");
    }

    if (round(index1) == 4)
    {
        printf("Grade 4\n");
    }

    if (round(index1) == 5)
    {
        printf("Grade 5\n");
    }

    if (round(index1) == 6)
    {
        printf("Grade 6\n");
    }

    if (round(index1) == 7)
    {
        printf("Grade 7\n");
    }

    if (round(index1) == 8)
    {
        printf("Grade 8\n");
    }

    if (round(index1) == 9)
    {
        printf("Grade 9\n");
    }

    if (round(index1) == 10)
    {
        printf("Grade 10\n");
    }

    if (round(index1) == 11)
    {
        printf("Grade 11\n");
    }

    if (round(index1) == 12)
    {
        printf("Grade 12\n");
    }

    if (round(index1) == 13)
    {
        printf("Grade 13\n");
    }

    if (round(index1) == 14)
    {
        printf("Grade 14\n");
    }

    if (round(index1) == 15)
    {
        printf("Grade 15\n");
    }

    if (round(index1) >= 16)
    {
        printf("Grade 16+\n");
    }

}