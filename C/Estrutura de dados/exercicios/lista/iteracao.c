//Crie a função iterativa ordenada(lista), que devolve 1 se a lista "lista" estiver ordenada de forma
//crescente e sem itens repetidos (ou 0, caso contrário). 
#include <stdio.h>
#include "../../lib/lista.h" 

int ordenada( Lista lista ){
    
    while( lista->prox != NULL ){
        
        if( lista->item > lista->prox->item || lista->item == lista->prox->item ) return 0;
        
        lista = lista->prox;
    }
    return 1;
}


void main(){

    Lista ordenada_comum = no( 1, no( 2, no( 3, no( 4, NULL ) ) ) );
    Lista ordenada_repetida = no( 1, no( 2, no( 3, no( 4, no( 4, NULL ) ) ) ) );
    Lista desordenada = no( 1, no( 2, no( 4, no( 3, no( 4, NULL ) ) ) ) );
    
    printf( "%d ", ordenada( ordenada_comum ) );     //1
    printf( "%d ", ordenada( ordenada_repetida ) );  //0
    printf( "%d ", ordenada( desordenada ) );        //0
}