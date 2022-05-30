#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //question put in the string
    string name = get_string("What is your name?\n");
    //what is put in the screen when run
    printf("Hello, %s\n", name);
}
