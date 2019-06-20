// Crie a função recursiva empurra(vetor, tam), que empurra o maior item existente no vetor de inteiros vetor[0..tam] 
// para a posição tam desse vetor. Em seguida, usando essa função e a ideia do Bubble Sort, crie a função recursiva
// bubble_sort(vetor, final), que ordena um vetor de inteiros vetor[0..final-1] em ordem crescente.
#include <stdio.h>

#define MAX 4
#define troca( a, b ) { int x = a; a = b; b = x; } 

void empurra( int vetor[], int tam ){
    
    if( tam == 0 ) return;
    
    empurra( vetor, tam - 1 );
    if( vetor[tam - 1] > vetor[tam]) troca( vetor[tam - 1], vetor[tam]);
}


void bubble_sort( int vetor[], int final ){
    
    if ( final == 0 ) return;
    
    empurra( vetor, final );
    bubble_sort( vetor, final - 1 );
}


void main(){

    int vetor[MAX] = {5,4,3,2};
    
    bubble_sort( vetor, MAX );
    
    for( int i = 0; i < MAX; i++ ){
        
        printf("%d ", vetor[i]);
    }
}