#include <stdio.h>
#include <string.h>
#include "lecturas.h"
#include "funciones.h"

int main()
{
    char matrizProductos[MAX_PRODUCTOS][MAX_NOMBRE];
    float matrizPrecios[MAX_PRODUCTOS];
    int matrizCantidad[MAX_PRODUCTOS];
    int matrizCodigos[MAX_PRODUCTOS];
    int numProductos = 0;
    int opcion, codigo, cantidad;
    float precio;

    cargarArchivo(matrizProductos, matrizPrecios, matrizCantidad, matrizCodigos, &numProductos);

    do {
        printf("\n*** Sistema de Inventario de Pinta Autps ***\n");
        printf("1. Ingresar un producto\n");
        printf("2. Enlistar productos\n");
        printf("3. Borrar un producto\n");
        printf("4. Modificar precio de un producto\n");
        printf("5. Modificar cantidad de un producto\n");
        printf("6. Buscar un producto\n");
        printf("7. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarProducto(matrizProductos, matrizPrecios, matrizCantidad, matrizCodigos, &numProductos);
                almacenarArchivo(matrizProductos, matrizPrecios, matrizCantidad, matrizCodigos, numProductos);
                break;
            case 2:
                enlistarProductos(matrizProductos, matrizPrecios, matrizCantidad, matrizCodigos, numProductos);
                almacenarArchivo(matrizProductos, matrizPrecios, matrizCantidad, matrizCodigos, numProductos);
                break;
            case 3:
                printf("Ingrese el codigo del producto a borrar: ");
                scanf("%d", &codigo);
                borrarProducto(matrizProductos, matrizPrecios, matrizCantidad, matrizCodigos, &numProductos, codigo);
                almacenarArchivo(matrizProductos, matrizPrecios, matrizCantidad, matrizCodigos, numProductos);
                break;
            case 4:
                printf("Ingrese el codigo del producto a modificar el precio: ");
                scanf("%d", &codigo);
                printf("Ingrese el nuevo precio: ");
                precio = validarFlotantePositivo();
                modificarPrecio(matrizPrecios, matrizCodigos, numProductos, codigo, precio);
                almacenarArchivo(matrizProductos, matrizPrecios, matrizCantidad, matrizCodigos, numProductos);
                break;
            case 5:
                printf("Ingrese el codigo del producto a modificar la cantidad: ");
                scanf("%d", &codigo);
                printf("Ingrese la nueva cantidad: ");
                cantidad = validarEnteroPositivo();
                modificarCantidad(matrizCantidad, matrizCodigos,numProductos, codigo, cantidad);
                almacenarArchivo(matrizProductos, matrizPrecios, matrizCantidad, matrizCodigos, numProductos);
                break;
            case 6:
                printf("Ingrese el codigo del producto a buscar: ");
                scanf("%d", &codigo);
                buscarProducto(matrizProductos, matrizPrecios, matrizCantidad, matrizCodigos, numProductos, codigo);
                break;
            case 7:
                printf("Gracias por utilizar el sistema. ¡Hasta luego!\n");
                break;
            default:
                printf("Opción invalida. Por favor, ingrese un número del 1 al 7.\n");
        }
    } while (opcion != 7);

    return 0;
}
