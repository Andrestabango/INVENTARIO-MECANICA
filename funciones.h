#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 50
void ingresarProducto(char matrizProductos[MAX_PRODUCTOS][MAX_NOMBRE], float matrizPrecios[MAX_PRODUCTOS], int matrizCantidad[MAX_PRODUCTOS], int matrizCodigos[MAX_PRODUCTOS], int *numProductos);
void enlistarProductos(char matrizProductos[MAX_PRODUCTOS][MAX_NOMBRE], float matrizPrecios[MAX_PRODUCTOS], int matrizCantidad[MAX_PRODUCTOS], int matrizCodigos[MAX_PRODUCTOS], int numProductos);
void borrarProducto(char matrizProductos[MAX_PRODUCTOS][MAX_NOMBRE], float matrizPrecios[MAX_PRODUCTOS], int matrizCantidad[MAX_PRODUCTOS], int matrizCodigos[MAX_PRODUCTOS], int *numProductos, int codigo);
void modificarPrecio(float matrizPrecios[MAX_PRODUCTOS], int matrizCodigos[MAX_PRODUCTOS], int numProductos, int codigo, float nuevoPrecio);
void modificarCantidad(int matrizCantidad[MAX_PRODUCTOS],int matrizCodigos[MAX_PRODUCTOS], int numProductos, int codigo, int nuevaCantidad);
void buscarProducto(char matrizProductos[MAX_PRODUCTOS][MAX_NOMBRE], float matrizPrecios[MAX_PRODUCTOS], int matrizCantidad[MAX_PRODUCTOS], int matrizCodigos[MAX_PRODUCTOS], int numProductos, int codigo);
void almacenarArchivo(char matrizProductos[MAX_PRODUCTOS][MAX_NOMBRE], float matrizPrecios[MAX_PRODUCTOS], int matrizCantidad[MAX_PRODUCTOS], int matrizCodigos[MAX_PRODUCTOS], int numProductos);
void cargarArchivo(char matrizProductos[MAX_PRODUCTOS][MAX_NOMBRE], float matrizPrecios[MAX_PRODUCTOS], int matrizCantidad[MAX_PRODUCTOS], int matrizCodigos[MAX_PRODUCTOS], int *numProductos);