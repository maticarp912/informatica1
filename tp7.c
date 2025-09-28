/* Repo URL: https://github.com/maticarp912/informatica1 */
#include <stdio.h>

#define TAM 5
#define MIN_CODE 1
#define MAX_CODE 999999999

static void limpiarBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

static int leerEnteroEnRango(const char *prompt, int min, int max) {
    int valor;
    for (;;) {
        printf("%s", prompt);
        if (scanf("%d", &valor) == 1) {
            if (valor >= min && valor <= max) {
                limpiarBuffer();
                return valor;
            } else {
                printf("Error. El código de barras debe estar entre %d y %d\n", min, max);
            }
        } else {
            printf("Error. Debe ingresar un número entero.\n");
        }
        limpiarBuffer();
    }
}

static double leerDoubleMin(const char *prompt, double min) {
    double valor;
    for (;;) {
        printf("%s", prompt);
        if (scanf("%lf", &valor) == 1) {
            if (valor >= min) {
                limpiarBuffer();
                return valor;
            } else {
                printf("Error. El precio no puede ser negativo.\n");
            }
        } else {
            printf("Error. Debe ingresar un número (use punto para decimales).\n");
        }
        limpiarBuffer();
    }
}

int main(void) {
    int codigos[TAM];
    double precios[TAM];

    printf("Ingrese %d productos, se solicitará el código y precio:\n", TAM);

    for (int i = 0; i < TAM; i++) {
        codigos[i] = leerEnteroEnRango("Ingrese el código de barras (1-999999999): ", MIN_CODE, MAX_CODE);
        precios[i] = leerDoubleMin("Ingrese el precio: ", 0.0);
    }

    printf("\n%-12s%-12s\n", "Código", "Precio");
    for (int i = 0; i < TAM; i++) {
        printf("%-12d%-.2f\n", codigos[i], precios[i]);
    }

    int idx_max = 0, idx_min = 0;
    for (int i = 1; i < TAM; i++) {
        if (precios[i] > precios[idx_max]) idx_max = i;
        if (precios[i] < precios[idx_min]) idx_min = i;
    }

    printf("\nMás caro:   [%d] %.2f\n", codigos[idx_max], precios[idx_max]);
    printf("Más barato: [%d] %.2f\n", codigos[idx_min], precios[idx_min]);
    return 0;
}
