#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../lib/pilha.h"

int calcula( char *e ) {    

    Pilha valores = pilha( 256 );
    
    for( int i = 0; e[i]; i++ ) {
        
        if ( isdigit( e[i] ) ) { empilha( e[i] - '0', valores ); }
        
        else { 

            switch( e[i] ) {
                case '+':
                    empilha( desempilha( valores ) + desempilha( valores ), valores );
                    break;
                case '-':
                    empilha( desempilha( valores ) - desempilha( valores ), valores );
                    break;
                case '*':
                    empilha( desempilha( valores ) * desempilha( valores ), valores );
                    break;
                case '/':
                    empilha( desempilha( valores ) / desempilha( valores ), valores );
                    break;
            }
        }         
    }

    int resultado = desempilha( valores );
    destroip( &valores );
    return resultado; 
}

int main(){
    
    char expressao[256];
    printf("Expressão? ");
    gets(expressao);
    
    printf("Resultado %i", calcula( expressao ) );
    
    getchar();
    return 0;
}