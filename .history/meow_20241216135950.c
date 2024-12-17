#include "cs50.h"
#include <stdio.h>

void meow (int n);// This is the function prototype & it is declared here before the main function
int main(void)
{
    meow(3); // This is the function call & parameters are passed here
}

// This is the function that will be called in the main function
void meow(int n)
{
    for(int i = 0; i<n; i++)
{
    printf("meow\n");
}

}