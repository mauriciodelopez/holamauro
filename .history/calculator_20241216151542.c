#include "cs50.h"
#include <stdio.h>
//arguments function prototype return value
int add(int a, int b);

int main (void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("%i\n", add(x, y));

}

int add (int a, int b)
{
    return a + b;
}