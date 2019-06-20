#include <stdio.h>
#include <stdlib.h>
#include "../lib/pilha.h" //depende de stdio.h e stdlib.h 

int main()
{   
    int n;
    Pilha P = pilha( 32 );
    printf("Decimal?: ");
    scanf("%d", &n);

    do { empilha( n%2, P ); n /= 2; } while( n != 0 );

    printf( "Binario: " );
    while( !vaziap(P) ) printf( "%d", desempilha( P ) );

    destroip( &P );
    getchar();
    return 0;
}