#include <stdio.h>
#include <string.h>
#include "funciones.h"
#include "lecturas.h"

void ingresarProducto(char matrizProductos[MAX_PRODUCTOS][MAX_NOMBRE], float matrizPrecios[MAX_PRODUCTOS], int matrizCantidad[MAX_PRODUCTOS], int matrizCodigos[MAX_PRODUCTOS], int *numProductos)
{
    if (*numProductos >= MAX_PRODUCTOS) {
        printf("No se pueden ingresar más productos. La capacidad máxima se ha alcanzado.\n");
        return;
    }
    printf("Ingresando nuevo producto:\n");
    printf("Ingrese el codigo del producto: ");
    matrizCodigos[*numProductos]=validarEnteroPositivo();
    printf("Ingrese el nombre del producto: ");
    scanf("%s", matrizProductos[*numProductos]);
    printf("Ingrese el precio del producto: ");
    matrizPrecios[*numProductos] = validarFlotantePositivo();
    printf("Ingrese la cantidad del producto: ");
    matrizCantidad[*numProductos] = validarEnteroPositivo();
    (*numProductos)++;
    printf("Producto ingresado correctamente.\n");
}

void enlistarProductos(char matrizProductos[MAX_PRODUCTOS][MAX_NOMBRE], float matrizPrecios[MAX_PRODUCTOS], int matrizCantidad[MAX_PRODUCTOS], int matrizCodigos[MAX_PRODUCTOS], int numProductos)
{
    printf("Listado de productos:\n");
    if (numProductos == 0) {
        printf("No hay productos ingresados.\n");
        return;
    }
    for (int i = 0; i < numProductos; i++) {
        printf("Codigo: %d, Nombre: %s, Precio: %.2f, Cantidad: %d\n", matrizCodigos[i], matrizProductos[i], matrizPrecios[i], matrizCantidad[i]);
    }
}

void borrarProducto(char matrizProductos[MAX_PRODUCTOS][MAX_NOMBRE], float matrizPrecios[MAX_PRODUCTOS], int matrizCantidad[MAX_PRODUCTOS], int matrizCodigos[MAX_PRODUCTOS], int *numProductos, int codigo)
{
    int indiceBorrar = -1;
    for (int i = 0; i < *numProductos; i++) {
        if (matrizCodigos[i] == codigo) {
            indiceBorrar = i;
            break;
        }
    }
    if (indiceBorrar == -1) {
        printf("No se encontro ningún producto con ese codigo.\n");
        return;
    }
    for (int i = indiceBorrar; i < (*numProductos - 1); i++) {
        matrizCodigos[i] = matrizCodigos[i + 1];
        strcpy(matrizProductos[i], matrizProductos[i + 1]);
        matrizPrecios[i] = matrizPrecios[i + 1];
        matrizCantidad[i] = matrizCantidad[i + 1];
    }
    (*numProductos)--;
    printf("Producto borrado correctamente.\n");
}

void modificarPrecio(float matrizPrecios[MAX_PRODUCTOS], int matrizCodigos[MAX_PRODUCTOS], int numProductos, int codigo, float nuevoPrecio)
{
    int encontrado = 0;
    for (int i = 0; i < numProductos; i++) {
        if (matrizCodigos[i] == codigo) {
            matrizPrecios[i] = nuevoPrecio;
            encontrado = 1;
            break;
        }
    }
    if (encontrado) {
        printf("Precio modificado correctamente.\n");
    } else {
        printf("No se encontro ningún producto con ese codigo.\n");
    }
}

void modificarCantidad(int matrizCantidad[MAX_PRODUCTOS],int matrizCodigos[MAX_PRODUCTOS], int numProductos, int codigo, int nuevaCantidad)
{
    int encontrado = 0;
    for (int i = 0; i < numProductos; i++) {
        if (matrizCodigos[i] == codigo) {
            matrizCantidad[i] = nuevaCantidad;
            encontrado = 1;
            break;
        }
    }
    if (encontrado) {
        printf("Cantidad modificada correctamente.\n");
    } else {
        printf("No se encontro ningun producto con ese codigo.\n");
    }
}

void buscarProducto(char matrizProductos[MAX_PRODUCTOS][MAX_NOMBRE], float matrizPrecios[MAX_PRODUCTOS], int matrizCantidad[MAX_PRODUCTOS], int matrizCodigos[MAX_PRODUCTOS], int numProductos, int codigo)
{
    int encontrado = 0;
    for (int i = 0; i < numProductos; i++) {
        if (matrizCodigos[i] == codigo) {
            printf("Informacion del producto:\n");
            printf("Codigo: %d, Nombre: %s, Precio: %.2f, Cantidad: %d\n", matrizCodigos[i], matrizProductos[i], matrizPrecios[i], matrizCantidad[i]);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("No se encontro ningun producto con ese codigo.\n");
    }
}

void almacenarArchivo(char matrizProductos[MAX_PRODUCTOS][MAX_NOMBRE], float matrizPrecios[MAX_PRODUCTOS], int matrizCantidad[MAX_PRODUCTOS], int matrizCodigos[MAX_PRODUCTOS], int numProductos)
{
    FILE *archivo;
    archivo = fopen("productos.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo.\n");
        return;
    }
    for (int i = 0; i < numProductos; i++) {
        fprintf(archivo, "%d %s %.2f %d\n", matrizCodigos[i], matrizProductos[i], matrizPrecios[i], matrizCantidad[i]);
    }
    fclose(archivo);
    printf("Productos almacenados correctamente en el archivo productos.txt.\n");
}

void cargarArchivo(char matrizProductos[MAX_PRODUCTOS][MAX_NOMBRE], float matrizPrecios[MAX_PRODUCTOS], int matrizCantidad[MAX_PRODUCTOS], int matrizCodigos[MAX_PRODUCTOS], int *numProductos)
{
    FILE *archivo;
    archivo = fopen("productos.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo productos.txt.\n");
        return;
    }

    int codigo, cantidad;
    float precio;
    char nombre[MAX_NOMBRE];
    int i = 0;

    while (fscanf(archivo, "%d %s %f %d", &codigo, nombre, &precio, &cantidad) == 4) {
        matrizCodigos[i] = codigo;
        strcpy(matrizProductos[i], nombre);
        matrizPrecios[i] = precio;
        matrizCantidad[i] = cantidad;
        i++;
    }

    *numProductos = i;

    fclose(archivo);
}
