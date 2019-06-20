//Crie a função recursiva insere( num, vetor, final), que insere um item x num vetor de inteiros vetor[0..final]. 
//Em seguida, usando essa função e a ideia do Insertion Sort, crie a função recursiva insertion_sort(vetor, tam),
//que ordena um vetor de inteiros vetor[0..tam-1] em ordem crescente.
#include <stdio.h>

#define MAX 4

void insere( int num, int vetor[], int final ){
    
    if( final > 0 && num < vetor[final - 1] ){
        
        vetor[final] = vetor[final - 1];
        insere( num, vetor, final - 1);
    } 
    else {
        
        vetor[final] = num;
    }
}


void insertion_sort( int vetor[], int tam ){
    
    if( tam == 0 ) return;
    
    insertion_sort( vetor, tam - 1 );
    insere( vetor[tam], vetor, tam);
}


void main(){

    int vetor[MAX] = {5,4,3,2};

    insertion_sort( vetor, MAX);
    
    for( int i = 0; i < MAX; i++ ) printf("%d ", vetor[i]);
}