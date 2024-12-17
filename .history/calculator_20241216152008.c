#include <stdio.h>
#include "cs50.h"

// arguments: int a, int b
// function prototype: int add(int a, int b)
// return value: int
int add(int a, int b);

int main(void)
{
    // function: get_int
    // arguments: "x: "
    int x = get_int("x: ");
    
    // function: get_int
    // arguments: "y: "
    int y = get_int("y: ");

    // function: printf
    // arguments: "%i\n", add(x, y)
    // return value: int (from add function)
    printf("%i\n", add(x, y));

    // return value: 0 (indicates successful execution)
    return 0;
}

// function: int add(int a, int b)
// arguments: int a, int b
// return value: int
int add(int a, int b)
{
    // return value: a + b
    return a + b;
}