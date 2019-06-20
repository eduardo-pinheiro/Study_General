#include <stdio.h>

int pot( int numero, int potencia){
    if (potencia == 0) return 1;
    return numero * pot(numero, potencia-1);
}

int main(){
    int numero, potencia;
    printf("Digite um numero e sua potencia: \n");
    scanf("%d %d", &numero, &potencia);

    int resultado = pot(numero, potencia);

    printf("\n%d elavado a %d e: %d", numero, potencia, resultado);
}