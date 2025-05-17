#include <stdio.h>
int main(void){
    float peso, altura, imc;

    printf ("Altura en metros:");
        scanf ("%f", &altura);
        
    printf ("Peso en kg:");
        scanf ("%f", &peso);
        
    imc = peso / (altura * altura);
    
    printf ("\nsu indice de masa corporal es: %.2f\n", imc);
    
    if (imc<18.5) { 
        printf ("\nUsted tiene bajo peso\n");
    }
    else if (imc<24.9){
printf ("\nSu peso se encuentra normal\n");
    }
    else if (imc<29.9){
        printf("\nUsted tiene sobre peso\n");
    }
    else { printf ("\nUsted tiene obesidad\n");
    }
    printf("\nÍndice | Condición\n");
    printf("-----------------------------\n");
    printf("<18.5        | Bajo peso\n");
    printf("18.5 a 24.9  | Normal\n");
    printf("25.0 a 29.9  | Sobrepeso\n");
    printf(">=30         | Obesidad\n");


return 0;
}
