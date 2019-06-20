#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../lib/pilha.h"
#include "../lib/fila.h"

int main(){
    char palindrome[256];
    printf("Palindrome? ");
    gets(palindrome);

    Pilha inverte = pilha( 256 );
    Fila mantem = fila( 256 );

    for( int i = 0; palindrome[i]; i++ ) {

        if( isalpha( palindrome[i] ) ) {
            
            enfileira( toupper( palindrome[i] ), mantem );
            empilha( toupper( palindrome[i] ), inverte );
        } 
    }

    while( !vaziaf( mantem ) && desenfileira( mantem ) == desempilha( inverte ) );

    printf( "%s Palindrome", vaziap( inverte ) ? "E" : "Nao e");

    destroip( &inverte );
    destroif( &mantem );
    getchar();
    return 0;
}