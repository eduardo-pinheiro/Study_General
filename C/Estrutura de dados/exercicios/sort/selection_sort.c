//Crie a função recursiva posmax(vetor, final), que devolve a posição do maior item existente no vetor de inteiros
//vetor[0..final]. Em seguida, usando essa função e a ideia do Selection Sort, crie a função recursiva selection_sort(vetor, tam)
//que ordena um vetor de inteiros vetor[0..tam-1] em ordem crescente.
#include <stdio.h>

#define MAX 4
#define troca( a, b ) { int x = a; a = b; b = x; } 

int posmax( int vetor[], int final ){
    
    if( final == 0 ) return final;
    
    int maior = posmax(vetor, final - 1);
    
    if( vetor[maior] < vetor[final] ) return final;
    else return maior;
}   


void selection_sort( int vetor[], int tam ){
    
    if( tam == 0 ) return;
    
    int maior = posmax( vetor, tam - 1 );
    
    troca( vetor[maior], vetor[tam - 1] );
    selection_sort( vetor, tam - 1 );    
}


void main(){

    int vetor[MAX] = {5,4,3,2};
    
    selection_sort( vetor, MAX );
    
    for( int i = 0; i < MAX; i++ ){
        
        printf("%d ", vetor[i]);
    }
}