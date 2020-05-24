#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // printf("Hi, please enter your name: \n");
    string name = get_string("Hi, please enter your name: ");
    printf("Hi, %s\n", name);
    return 0;
}
