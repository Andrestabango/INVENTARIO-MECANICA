#include <stdio.h>
#include <string.h>
#include "lecturas.h"

int validarEnteroPositivo() {
    int numero;
    while (1) {
        if (scanf("%d", &numero) == 1 && numero >= 0) {
            return numero;
        }
        printf("Error. Ingrese un valor valido: ");
        while (getchar() != '\n'); // Limpiar el buffer de entrada
    }
}

float validarFlotantePositivo() {
    float numero;
    while (1) {
        if (scanf("%f", &numero) == 1 && numero >= 0) {
            return numero;
        }
        printf("Error. Ingrese un valor valido: ");
        while (getchar() != '\n'); // Limpiar el buffer de entrada
    }
}
