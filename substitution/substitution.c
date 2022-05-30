#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//variables

int character, i;
int count = 0;
int letter = 0;
string plaintext;
char output[100];
char newcharacter;

//pulls from initializer

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("No key provided/more than one key\n");
        return 1;
    }

    strcpy(output, "");

    //checking length

    if (strlen(argv[1]) == 26)
    {
        count = 0;
        for (i = 0; i <= strlen(argv[1]); i++)
        {
            character = argv[1][i];
            if ((character >= 65 && character <= 90) || (character >= 97 && character <= 122))
            {
                letter++;
            }

            //checking repetition

            for (int j = i + 1; j < strlen(argv[1]); j++)
            {
                if (argv[1][i] == argv[1][j])
                {
                    count++;
                }
            }
        }

        //everything is good

        if (letter == 26 && count == 0)
        {

            plaintext = get_string("plaintext: ");
            string cipher = argv[1];
            for (i = 0; i <= strlen(plaintext); i++)
            {
                character = plaintext[i];

                //lowercase

                if (character >= 97 && character <= 122)
                {
                    newcharacter = tolower(argv[1][character - 97]);
                    strcat(output, &newcharacter);
                }

                //uppercase

                else if (character >= 65 && character <= 90)
                {

                    newcharacter = toupper(argv[1][character - 65]);
                    strcat(output, &newcharacter);
                }

                //everything else

                else
                {
                    newcharacter = character;
                    strcat(output, &newcharacter);
                }
            }

            //printing final

            printf("ciphertext: %s\n", output);

            return 0;

        }

        //wrong if input equals something other than number

        else if (letter < 26)
        {
            printf("Key must only contain alphabetic characters\n");
            return 1;
        }

        //wrong if repetition

        else if (count > 0)
        {
            printf("Key must not contain repeated characters\n");
            return 1;
        }


        return 0;
    }

    //wrong if less than 26 letter key

    else if (strlen(argv[1]) < 26)
    {
        printf("Key must contain 26 characters");
        return 1;
    }

    //wrong if repetition

    else if (count > 0 && argv[1][i] != '0')
    {
        printf("Key must not contain repeated characters\n");
        return 1;
    }


    return 0;
}


