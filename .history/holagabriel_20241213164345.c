#include <cs50.h>
#include <stdio.h>

int main(void) {
    string nombre = get_string("What's your name?\n");
    printf("Hola, %s\n", nombre);
    return 0;
}