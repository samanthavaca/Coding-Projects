#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{   
    char NumberLength[3];
    char NumberInText[17];
    char NumberInAmerican[16];
    char FirstTwo[3];
    char EveryTwo[10];
    char multiply[2];
    char TempSub[3];
    char TempDigits[3];
    char TempFinalDigits[3];
    char TempFinalSub[3];

    int Luhns;
    int FinalCheck;
    int FirstDigit;
    int SecondDigit;
    int ThirdDigit;
    int FourthDigit;
    int FifthDigit;
    int SixthDigit;
    int SeventhDigit;
    int EighthDigit;
    int NinthDigit;
    int TenthDigit;
    int EleventhDigit;
    int TwelvthDigit;
    int ThirteenthDigit;
    int FourteenthDigit;
    int FifteenthDigit;
    int SixteenthDigit;

    int EighthDigit_First;
    int EighthDigit_Second;
    int SeventhDigit_First;
    int SeventhDigit_Second;
    int SixthDigit_First;
    int SixthDigit_Second;
    int FifthDigit_First;
    int FifthDigit_Second;
    int FourthDigit_First;
    int FourthDigit_Second;
    int ThirdDigit_First;
    int ThirdDigit_Second;
    int SecondDigit_First;
    int SecondDigit_Second;
    int FirstDigit_First;
    int FirstDigit_Second;

    int NinthDigit_First = 0;
    int NinthDigit_Second = 0;
    int TenthDigit_First = 0;
    int TenthDigit_Second = 0;
    int EleventhDigit_First = 0;
    int EleventhDigit_Second = 0;
    int TwelvthDigit_First = 0;
    int TwelvthDigit_Second = 0;
    int ThirteenthDigit_First = 0;
    int ThirteenthDigit_Second = 0;
    int FourteenthDigit_First = 0;
    int FourteenthDigit_Second = 0;
    int FifteenthDigit_First = 0;
    int FifteenthDigit_Second = 0;
    int SixteenthDigit_First = 0;
    int SixteenthDigit_Second = 0;

    int FinalDigit_First;
    int FinalDigit_Second;


    long long creditnum = get_long_long("Number: ");
    
    sprintf(NumberLength, "%lli", creditnum);

    sprintf(NumberInText, "%lli", creditnum);
    FirstTwo[0] = NumberInText[0];
    FirstTwo[1] = NumberInText[1];
    FirstTwo[2] = '\0';

    //American Express Check
    if (strcmp(FirstTwo, "34") == 0 || strcmp(FirstTwo, "37") == 0)
    {


        // Not multiply by two 
        memcpy(TempSub, &NumberInText[14], 1);
        EighthDigit = atoi(TempSub);

        memcpy(TempSub, &NumberInText[12], 1);
        SeventhDigit = atoi(TempSub);

        memcpy(TempSub, &NumberInText[10], 1);
        SixthDigit = atoi(TempSub);

        memcpy(TempSub, &NumberInText[8], 1);
        FifthDigit = atoi(TempSub);

        memcpy(TempSub, &NumberInText[6], 1);
        FourthDigit = atoi(TempSub);

        memcpy(TempSub, &NumberInText[4], 1);
        ThirdDigit = atoi(TempSub);

        memcpy(TempSub, &NumberInText[2], 1);
        SecondDigit = atoi(TempSub);

        memcpy(TempSub, &NumberInText[0], 1);
        FirstDigit = atoi(TempSub);

        // ENd of NOT of multiplying by two 

        // Multiplied by two 

        memcpy(TempSub, &NumberInText[13], 1);
        TenthDigit = atoi(TempSub) * 2;

        memcpy(TempSub, &NumberInText[11], 1);
        EleventhDigit = atoi(TempSub) * 2;

        memcpy(TempSub, &NumberInText[9], 1);
        TwelvthDigit = atoi(TempSub) * 2;

        memcpy(TempSub, &NumberInText[7], 1);
        ThirteenthDigit = atoi(TempSub) * 2;

        memcpy(TempSub, &NumberInText[5], 1);
        FourteenthDigit = atoi(TempSub) * 2;

        memcpy(TempSub, &NumberInText[3], 1);
        FifteenthDigit = atoi(TempSub) * 2;

        memcpy(TempSub, &NumberInText[1], 1);
        SixteenthDigit = atoi(TempSub) * 2;

        // End of multiply by two

        printf("NumberValues: %d %d %d %d %d %d %d\n", TenthDigit, EleventhDigit, TwelvthDigit, ThirteenthDigit, FourteenthDigit,
               FifteenthDigit, SixteenthDigit);


        if (TenthDigit > 9)
        {
            sprintf(TempDigits, "%d", TenthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            TenthDigit_First = atoi(TempSub);
            memcpy(TempSub, &TempDigits[1], 1);
            TenthDigit_Second = atoi(TempSub);
        } 
        else 
        {
            sprintf(TempDigits, "%d", TenthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            TenthDigit_First = atoi(TempSub);
            TenthDigit_Second = 0;
        }
        if (EleventhDigit > 9)
        {
            sprintf(TempDigits, "%d", EleventhDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            EleventhDigit_First = atoi(TempSub);
            memcpy(TempSub, &TempDigits[1], 1);
            EleventhDigit_Second = atoi(TempSub);
        } 
        else 
        {
            sprintf(TempDigits, "%d", EleventhDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            EleventhDigit_First = atoi(TempSub);
            EleventhDigit_Second = 0;
        }
        if (TwelvthDigit > 9)
        {
            sprintf(TempDigits, "%d", TwelvthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            TwelvthDigit_First = atoi(TempSub);
            memcpy(TempSub, &TempDigits[1], 1);
            TwelvthDigit_Second = atoi(TempSub);
            printf("Two Digits On Twelvth Digit: %d, %d\n", TwelvthDigit_First, TwelvthDigit_Second);
        } 
        else 
        {
            sprintf(TempDigits, "%d", TwelvthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            TwelvthDigit_First = atoi(TempSub);
            TwelvthDigit_Second = 0;
        }
        if (ThirteenthDigit > 9)
        {
            sprintf(TempDigits, "%d", ThirteenthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            ThirteenthDigit_First = atoi(TempSub);
            memcpy(TempSub, &TempDigits[1], 1);
            ThirteenthDigit_Second = atoi(TempSub);
        } 
        else 
        {
            sprintf(TempDigits, "%d", ThirteenthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            ThirteenthDigit_First = atoi(TempSub);
            ThirteenthDigit_Second = 0;
        }
        if (FourteenthDigit > 9)
        {
            sprintf(TempDigits, "%d", FourteenthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            FourteenthDigit_First = atoi(TempSub);
            memcpy(TempSub, &TempDigits[1], 1);
            FourteenthDigit_Second = atoi(TempSub);
        } 
        else 
        {
            sprintf(TempDigits, "%d", FourteenthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            FourteenthDigit_First = atoi(TempSub);
            FourteenthDigit_Second = 0;
        }
        if (FifteenthDigit > 9)
        {
            sprintf(TempDigits, "%d", FifteenthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            FifteenthDigit_First = atoi(TempSub);
            memcpy(TempSub, &TempDigits[1], 1);
            FifteenthDigit_Second = atoi(TempSub);
        } 
        else 
        {
            sprintf(TempDigits, "%d", FifteenthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            FifteenthDigit_First = atoi(TempSub);
            FifteenthDigit_Second = 0;
        }
        if (SixteenthDigit > 9)
        {   
            sprintf(TempDigits, "%d", SixteenthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            SixteenthDigit_First = atoi(TempSub);
            memcpy(TempSub, &TempDigits[1], 1);
            SixteenthDigit_Second = atoi(TempSub);
        } 
        else 
        {
            sprintf(TempDigits, "%d", SixteenthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            SixteenthDigit_First = atoi(TempSub);
            SixteenthDigit_Second = 0;
        }


        Luhns = TenthDigit_First + TenthDigit_Second + EleventhDigit_First + EleventhDigit_Second + TwelvthDigit_First 
                + TwelvthDigit_Second + ThirteenthDigit_First + ThirteenthDigit_Second + FourteenthDigit_First 
                + FourteenthDigit_Second + FifteenthDigit_First + FifteenthDigit_Second + SixteenthDigit_First 
                + SixteenthDigit_Second;

        FinalCheck = Luhns + FirstDigit + SecondDigit + ThirdDigit + FourthDigit + FifthDigit + SixthDigit 
                     + SeventhDigit + EighthDigit;


  
        sprintf(TempDigits, "%d", FinalCheck);
        memcpy(TempSub, &TempDigits[0], 1);
        FinalDigit_First = atoi(TempSub);
        memcpy(TempSub, &TempDigits[1], 1);
        FinalDigit_Second = atoi(TempSub);

        if (FinalDigit_Second == 0 && strcmp(FirstTwo, "34") == 0)
        {
            printf("AMEX\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "37") == 0)
        {
            printf("AMEX\n");
        }
        else if (FinalDigit_Second > 0) 
        {
            printf("INVALID\n");
        }
    } 
    // VISA Card Check- 13 numbers
    else if(strlen(NumberLength)== 13)
    {

        /* Not multiply by two */

        memcpy(TempSub, &NumberInText[12], 1);
        SeventhDigit = atoi(TempSub);

        memcpy(TempSub, &NumberInText[10], 1);
        SixthDigit = atoi(TempSub);

        memcpy(TempSub, &NumberInText[8], 1);
        FifthDigit = atoi(TempSub);

        memcpy(TempSub, &NumberInText[6], 1);
        FourthDigit = atoi(TempSub);

        memcpy(TempSub, &NumberInText[4], 1);
        ThirdDigit = atoi(TempSub);

        memcpy(TempSub, &NumberInText[2], 1);
        SecondDigit = atoi(TempSub);

        memcpy(TempSub, &NumberInText[0], 1);
        FirstDigit = atoi(TempSub);

        /* ENd of NOT of multiplying by two */

        /* Multiplied by two */

        memcpy(TempSub, &NumberInText[11], 1);
        EleventhDigit = atoi(TempSub) * 2;

        memcpy(TempSub, &NumberInText[9], 1);
        TwelvthDigit = atoi(TempSub) * 2;

        memcpy(TempSub, &NumberInText[7], 1);
        ThirteenthDigit = atoi(TempSub) * 2;

        memcpy(TempSub, &NumberInText[5], 1);
        FourteenthDigit = atoi(TempSub) * 2;

        memcpy(TempSub, &NumberInText[3], 1);
        FifteenthDigit = atoi(TempSub) * 2;

        memcpy(TempSub, &NumberInText[1], 1);
        SixteenthDigit = atoi(TempSub) * 2;

        /* End of multiply by two */

        if (EleventhDigit > 9)
        {
            sprintf(TempDigits, "%d", EleventhDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            EleventhDigit_First = atoi(TempSub);
            memcpy(TempSub, &TempDigits[1], 1);
            EleventhDigit_Second = atoi(TempSub);
        } 
        else 
        {
            sprintf(TempDigits, "%d", EleventhDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            EleventhDigit_First = atoi(TempSub);
            EleventhDigit_Second = 0;
        }
        if (TwelvthDigit > 9)
        {
            sprintf(TempDigits, "%d", TwelvthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            TwelvthDigit_First = atoi(TempSub);
            memcpy(TempSub, &TempDigits[1], 1);
            TwelvthDigit_Second = atoi(TempSub);
        } 
        else 
        {
            sprintf(TempDigits, "%d", TwelvthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            TwelvthDigit_First = atoi(TempSub);
            TwelvthDigit_Second = 0;
        }
        if (ThirteenthDigit > 9)
        {
            sprintf(TempDigits, "%d", ThirteenthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            ThirteenthDigit_First = atoi(TempSub);
            memcpy(TempSub, &TempDigits[1], 1);
            ThirteenthDigit_Second = atoi(TempSub);
        } 
        else 
        {
            sprintf(TempDigits, "%d", ThirteenthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            ThirteenthDigit_First = atoi(TempSub);
            ThirteenthDigit_Second = 0;
        }
        if (FourteenthDigit > 9)
        {
            sprintf(TempDigits, "%d", FourteenthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            FourteenthDigit_First = atoi(TempSub);
            memcpy(TempSub, &TempDigits[1], 1);
            FourteenthDigit_Second = atoi(TempSub);
        } 
        else 
        {
            sprintf(TempDigits, "%d", FourteenthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            FourteenthDigit_First = atoi(TempSub);
            FourteenthDigit_Second = 0;
        }
        if (FifteenthDigit > 9)
        {
            sprintf(TempDigits, "%d", FifteenthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            FifteenthDigit_First = atoi(TempSub);
            memcpy(TempSub, &TempDigits[1], 1);
            FifteenthDigit_Second = atoi(TempSub);
        } 
        else 
        {
            sprintf(TempDigits, "%d", FifteenthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            FifteenthDigit_First = atoi(TempSub);
            FifteenthDigit_Second = 0;
        }
        if (SixteenthDigit > 9)
        {   
            sprintf(TempDigits, "%d", SixteenthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            SixteenthDigit_First = atoi(TempSub);
            memcpy(TempSub, &TempDigits[1], 1);
            SixteenthDigit_Second = atoi(TempSub);
        } 
        else 
        {
            sprintf(TempDigits, "%d", SixteenthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            SixteenthDigit_First = atoi(TempSub);
            SixteenthDigit_Second = 0;
        }

        Luhns = EleventhDigit_First + EleventhDigit_Second + TwelvthDigit_First 
                + TwelvthDigit_Second + ThirteenthDigit_First + ThirteenthDigit_Second + FourteenthDigit_First 
                + FourteenthDigit_Second + FifteenthDigit_First + FifteenthDigit_Second + SixteenthDigit_First 
                + SixteenthDigit_Second;


        FinalCheck = Luhns + FirstDigit + SecondDigit + ThirdDigit + FourthDigit + FifthDigit + SixthDigit 
                     + SeventhDigit;


  
        sprintf(TempDigits, "%d", FinalCheck);
        memcpy(TempSub, &TempDigits[0], 1);
        FinalDigit_First = atoi(TempSub);
        memcpy(TempSub, &TempDigits[1], 1);
        FinalDigit_Second = atoi(TempSub);

        if (FinalDigit_Second == 0 && strcmp(FirstTwo, "40") == 0)
        {
            printf("VISA\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "41") == 0)
        {
            printf("VISA\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "42") == 0)
        {
            printf("VISA\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "43") == 0)
        {
            printf("VISA\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "44") == 0)
        {
            printf("VISA\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "45") == 0)
        {
            printf("VISA\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "46") == 0)
        {
            printf("VISA\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "47") == 0)
        {
            printf("VISA\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "48") == 0)
        {
            printf("VISA\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "49") == 0)
        {
            printf("VISA\n");
        } 
        else 
        {
            printf("INVALID\n");
        }


    } 
    //VISA and MasterCard check aka 16
    else if(strlen(NumberLength)== 16)
    {

        memcpy(TempSub, &NumberInText[15], 1);
        NinthDigit = atoi(TempSub);
    
        memcpy(TempSub, &NumberInText[14], 1);
        EighthDigit = atoi(TempSub) * 2;

        memcpy(TempSub, &NumberInText[13], 1);
        TenthDigit = atoi(TempSub);

        memcpy(TempSub, &NumberInText[12], 1);
        SeventhDigit = atoi(TempSub) * 2;

        memcpy(TempSub, &NumberInText[11], 1);
        EleventhDigit = atoi(TempSub);

        memcpy(TempSub, &NumberInText[10], 1);
        SixthDigit = atoi(TempSub) * 2;

        memcpy(TempSub, &NumberInText[9], 1);
        TwelvthDigit = atoi(TempSub);

        memcpy(TempSub, &NumberInText[8], 1);
        FifthDigit = atoi(TempSub) * 2;

        memcpy(TempSub, &NumberInText[7], 1);
        ThirteenthDigit = atoi(TempSub);

        memcpy(TempSub, &NumberInText[6], 1);
        FourthDigit = atoi(TempSub) * 2;

        memcpy(TempSub, &NumberInText[5], 1);
        FourteenthDigit = atoi(TempSub);

        memcpy(TempSub, &NumberInText[4], 1);
        ThirdDigit = atoi(TempSub) * 2;

        memcpy(TempSub, &NumberInText[3], 1);
        FifteenthDigit = atoi(TempSub);

        memcpy(TempSub, &NumberInText[2], 1);
        SecondDigit = atoi(TempSub) * 2;

        memcpy(TempSub, &NumberInText[1], 1);
        SixteenthDigit = atoi(TempSub);

        memcpy(TempSub, &NumberInText[0], 1);
        FirstDigit = atoi(TempSub) * 2;

        if (EighthDigit > 9)
        {
            sprintf(TempDigits, "%d", EighthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            EighthDigit_First = atoi(TempSub);
            memcpy(TempSub, &TempDigits[1], 1);
            EighthDigit_Second = atoi(TempSub);
        } 
        else 
        {
            sprintf(TempDigits, "%d", EighthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            EighthDigit_First = atoi(TempSub);
            EighthDigit_Second = 0;
        }

        if (SeventhDigit > 9)
        {
            sprintf(TempDigits, "%d", SeventhDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            SeventhDigit_First = atoi(TempSub);
            memcpy(TempSub, &TempDigits[1], 1);
            SeventhDigit_Second = atoi(TempSub);
        } 
        else 
        {
            sprintf(TempDigits, "%d", SeventhDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            SeventhDigit_First = atoi(TempSub);
            SeventhDigit_Second = 0;
        }
        if (SixthDigit > 9)
        {
            sprintf(TempDigits, "%d", SixthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            SixthDigit_First = atoi(TempSub);
            memcpy(TempSub, &TempDigits[1], 1);
            SixthDigit_Second = atoi(TempSub);
        } 
        else 
        {
            sprintf(TempDigits, "%d", SixthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            SixthDigit_First = atoi(TempSub);
            SixthDigit_Second = 0;
        }
        if (FifthDigit > 9)
        {
            sprintf(TempDigits, "%d", FifthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            FifthDigit_First = atoi(TempSub);
            memcpy(TempSub, &TempDigits[1], 1);
            FifthDigit_Second = atoi(TempSub);
        } 
        else 
        {
            sprintf(TempDigits, "%d", FifthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            FifthDigit_First = atoi(TempSub);
            FifthDigit_Second = 0;
        }
        if (FourthDigit > 9)
        {
            sprintf(TempDigits, "%d", FourthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            FourthDigit_First = atoi(TempSub);
            memcpy(TempSub, &TempDigits[1], 1);
            FourthDigit_Second = atoi(TempSub);
        } 
        else 
        {
            sprintf(TempDigits, "%d", FourthDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            FourthDigit_First = atoi(TempSub);
            FourthDigit_Second = 0;
        }
        if (ThirdDigit > 9)
        {
            sprintf(TempDigits, "%d", ThirdDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            ThirdDigit_First = atoi(TempSub);
            memcpy(TempSub, &TempDigits[1], 1);
            ThirdDigit_Second = atoi(TempSub);
        } 
        else 
        {
            sprintf(TempDigits, "%d", ThirdDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            ThirdDigit_First = atoi(TempSub);
            ThirdDigit_Second = 0;
        }
        if (SecondDigit > 9)
        {
            sprintf(TempDigits, "%d", SecondDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            SecondDigit_First = atoi(TempSub);
            memcpy(TempSub, &TempDigits[1], 1);
            SecondDigit_Second = atoi(TempSub);
        } 
        else 
        {
            sprintf(TempDigits, "%d", SecondDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            SecondDigit_First = atoi(TempSub);
            SecondDigit_Second = 0;
        }
        if (FirstDigit > 9)
        {   
            sprintf(TempDigits, "%d", FirstDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            FirstDigit_First = atoi(TempSub);
            memcpy(TempSub, &TempDigits[1], 1);
            FirstDigit_Second = atoi(TempSub);
        } 
        else 
        {
            sprintf(TempDigits, "%d", FirstDigit);
            memcpy(TempSub, &TempDigits[0], 1);
            FirstDigit_First = atoi(TempSub);
            FirstDigit_Second = 0;
        }

        Luhns = FirstDigit_First + FirstDigit_Second + SecondDigit_First + SecondDigit_Second + ThirdDigit_First 
                + ThirdDigit_Second + FourthDigit_First + FourthDigit_Second + FifthDigit_First + FifthDigit_Second 
                + SixthDigit_First + SixthDigit_Second + SeventhDigit_First + SeventhDigit_Second + EighthDigit_First 
                + EighthDigit_Second;


        FinalCheck = Luhns + NinthDigit + TenthDigit + EleventhDigit + TwelvthDigit + ThirteenthDigit + FourteenthDigit 
                     + FifteenthDigit + SixteenthDigit;

  
        sprintf(TempDigits, "%d", FinalCheck);
        memcpy(TempSub, &TempDigits[0], 1);
        FinalDigit_First = atoi(TempSub);
        memcpy(TempSub, &TempDigits[1], 1);
        FinalDigit_Second = atoi(TempSub);

        if (FinalDigit_Second == 0 && strcmp(FirstTwo, "34") == 0)
        {
            printf("AMERICAN EXPRESS\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "37") == 0)
        {
            printf("AMERICAN EXPRESS\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "51") == 0)
        {
            printf("MASTERCARD\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "52") == 0)
        {
            printf("MASTERCARD\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "53") == 0)
        {
            printf("MASTERCARD\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "54") == 0)
        {
            printf("MASTERCARD\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "55") == 0)
        {
            printf("MASTERCARD\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "22") == 0)
        {
            printf("MASTERCARD\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "40") == 0)
        {
            printf("VISA\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "41") == 0)
        {
            printf("VISA\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "42") == 0)
        {
            printf("VISA\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "43") == 0)
        {
            printf("VISA\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "44") == 0)
        {
            printf("VISA\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "45") == 0)
        {
            printf("VISA\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "46") == 0)
        {
            printf("VISA\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "47") == 0)
        {
            printf("VISA\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "48") == 0)
        {
            printf("VISA\n");
        }
        else if (FinalDigit_Second == 0 && strcmp(FirstTwo, "49") == 0)
        {
            printf("VISA\n");
        } 
        else 
        {
            printf("INVALID\n");
        }

    } 
    else if(strlen(NumberLength) < 13)
    {
        printf("INVALID\n");
    } 
    else if(strlen(NumberLength) > 16)
    {
        printf("INVALID\n");
    } 
    else if(strlen(NumberLength) == 15)
    {
        printf("INVALID\n");
    }

}
