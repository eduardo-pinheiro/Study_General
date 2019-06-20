//Crie a função recursiva linear_search(num, vetor, tam), que faz uma busca linear (linear search) no vetor de inteiros
//arbitrário vetor[0..tam-1] e devolve 1 se o item num estiver armazenado em vetor (ou 0, caso contrário).
#include <stdio.h>

#define MAX 10

int linear_search( int num, int vetor[], int tam ){

    if( tam == 0 ) return 0;

    if( num == vetor[tam - 1] ) return 1;

    else return linear_search( num, vetor, tam - 1 );
}


void main() {
    
    int vetor[MAX] = {88,31,96,52,45,19,68,70,29,90};
 
    printf( "%d ", linear_search( 25, vetor, MAX ) ); //0
    printf( "%d ", linear_search( 70, vetor, MAX ) ); //1
    printf( "%d ", linear_search( 00, vetor, MAX ) ); //0
    printf( "%d ", linear_search( 88, vetor, MAX ) ); //1
    printf( "%d ", linear_search( 90, vetor, MAX ) ); //1
}
