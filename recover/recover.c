#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <unistd.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    if (argc == 2)
    {

        int jpeg_count = 0;
        string inputname = argv[1];
        BYTE buffer[512];
        FILE *img;
        FILE *fp;
        char newjpeg[8];
        bool jpeg_found = false;
        bool makenew = false;

        fp = fopen(inputname, "r");
        if (fp == NULL)
        {
            return 1;
        }

        while (fread(buffer, sizeof(BYTE), 512, fp) > 0)
        {
            if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0) && jpeg_found == false)
            {
                // f("*** Starting first JPEG: %d\n",jpeg_count);
                jpeg_found = true;
                sprintf(newjpeg, "%03i.jpg", jpeg_count);
                img = fopen(newjpeg, "w");
                // f("*** Opening JPEG: %s\n",newjpeg);
                fwrite(buffer, sizeof(BYTE), 512, img);
            }
            else if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0) && jpeg_found == true)
            {
                jpeg_count++;
                // f("*** Starting new JPEG: %d\n",jpeg_count);
                fclose(img);
                sprintf(newjpeg, "%03i.jpg", jpeg_count);
                img = fopen(newjpeg, "w");
                fwrite(buffer, sizeof(BYTE), 512, img);
            }
            else if (jpeg_found == true)
            {
                // f("-- Continuing JPEG: %s\n",newjpeg);
                fwrite(buffer, sizeof(BYTE), 512, img);
            }
        }
        fclose(img);
        fclose(fp);
    }
    else
    {
        return 1;
    }
}
