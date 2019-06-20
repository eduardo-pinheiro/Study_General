#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../lib/pilha.h"

char *posfixa( char *e ) {
    static char posfixa[256];
    Pilha sinal = pilha(256);
    int cont = 0;

    for( int i = 0; e[i]; i++ ) {
        if( isdigit( e[i] ) ) { posfixa[ cont++ ] = e[i]; }
        else if( strchr( "+-/*", e[i] ) ) { empilha( e[i], sinal ); }
        else if( e[i] == ')' ) { posfixa[ cont++ ] = desempilha( sinal ); }
    }

    destroip( &sinal );
    return posfixa;
}

int main(){
    char expressao[256];
    printf( "expressão? " );
    gets( expressao );
    printf( "Posfixa: %s", posfixa( expressao ) );
    getchar();
    return 0;
}