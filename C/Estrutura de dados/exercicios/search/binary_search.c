//Crie a função recursiva binary_search(num, vetor, inicio, final), que faz uma busca binária (binary search) no vetor de inteiros
//ordenado vetor[inicio..final] e devolve 1 se o item num estiver armazenado em vetor (ou 0, caso contrário)#include <stdio.h>
#include <stdio.h>

#define MAX 17
#define MAX2 20

//Estudo antes da prova
int binary_search( int num, int vetor[], int inicio, int final ){

    int meio = ( ( final - inicio ) / 2 ) + inicio;

    if( num == vetor[meio] ) return 1;
    
    else if ( meio == final - 1 && num == vetor[final] ) return 1;
    
    else if ( meio == inicio ) return 0;
    
    else if( num < vetor[meio] ) return binary_search( num, vetor, inicio, meio); 
    else if( num > vetor[meio] ) return binary_search( num, vetor, meio, final); 
}


//Feita na prova
int bb( int x, int v[], int p, int u ){
    
    int m = ( u - p )/2 + p;

    if ( x == v[m] ) return 1;
    
    else if ( m == p && x == v[u] ) return 1;
    
    else if( m == p) return 0;

    else if( x > v[m] ) return bb( x, v, m, u );
    else if( x < v[m] ) return bb( x, v, p, m );
}

void main() {
    
    //Teste da função de estudo
    int vetor[MAX] = {1,1,2,3,3,4,5,6,6,7,8,9,10,12,13,20,20};
    
    printf( "%d ", binary_search( 3, vetor, 0, MAX - 1 ) ); //1
    printf( "%d ", binary_search( 5, vetor, 0, MAX - 1 ) ); //1
    printf( "%d ", binary_search( 9, vetor, 0, MAX - 1 ) ); //1
    printf( "%d ", binary_search( 10, vetor, 0, MAX - 1 ) ); //1
    printf( "%d ", binary_search( 1, vetor, 0, MAX - 1 ) ); //1
    printf( "%d ", binary_search( 20, vetor, 0, MAX - 1 ) ); //1
    printf( "%d ", binary_search( 30, vetor, 0, MAX - 1 ) ); //0
    printf( "%d ", binary_search( -5, vetor, 0, MAX - 1 ) ); //0
    printf( "%d ", binary_search( -55, vetor, 0, MAX - 1 ) ); //0
    printf( "%d ", binary_search( 0, vetor, 0, MAX - 1 ) ); //0


    //Teste da função feita na prova
    int vetor2[MAX2] = {1,1,2,3,3,4,5,6,6,7,8,9,10,12,13,20,20,35,47,88};
    
    printf( "\n\n%d ", bb( 3, vetor2, 0, MAX2 - 1 ) ); //1
    printf( "%d ", bb( 5, vetor2, 0, MAX2 - 1 ) ); //1
    printf( "%d ", bb( 9, vetor2, 0, MAX2 - 1 ) ); //1
    printf( "%d ", bb( 10, vetor2, 0, MAX2 - 1 ) ); //1
    printf( "%d ", bb( 1, vetor2, 0, MAX2 - 1 ) ); //1
    printf( "%d ", bb( 20, vetor2, 0, MAX2 - 1 ) ); //1
    printf( "%d ", bb( 30, vetor2, 0, MAX2 - 1 ) ); //0
    printf( "%d ", bb( -5, vetor2, 0, MAX2 - 1 ) ); //0
    printf( "%d ", bb( -55, vetor2, 0, MAX2 - 1 ) ); //0
    printf( "%d ", bb( 0, vetor2, 0, MAX2 - 1 ) ); //0
    printf( "%d ", bb( 35, vetor2, 0, MAX2 - 1 ) ); //1
    printf( "%d ", bb( 47, vetor2, 0, MAX2 - 1 ) ); //1
    printf( "%d ", bb( 88, vetor2, 0, MAX2 - 1 ) ); //1
    printf( "%d ", bb( 89, vetor2, 0, MAX2 - 1 ) ); //0   
}
