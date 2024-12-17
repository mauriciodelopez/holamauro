#include "cs50.h"
#include <stdio.h>

int main(void) {
    string nombre = get_string("¿Cuál es tu nombre be?\n");
    printf("Hola, %s\n", nombre);
    return 0;
}