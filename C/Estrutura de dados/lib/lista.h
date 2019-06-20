#include <stdlib.h>

#define fmt "%d "
typedef int Item;
typedef struct  no {
    Item item;
    struct no *prox;
} *Lista;

Lista no( Item x, Lista p ){
    Lista n = malloc( sizeof( struct no ) );
    n->item = x;
    n->prox = p;
    return n;
}

void exibe( Lista L ){
    while( L != NULL ){
        printf( fmt, L->item );
        L = L->prox;
    }    
}

Lista range( int n ){
    Lista l = NULL;
    
    while( n ){
        l = no( n, l );
        n--;
    }

    return l;
}

void anexa( Lista *A, Lista B ){
    if( B == NULL ) return;
    while( *A != NULL ) A = &(*A)->prox;
    *A = B;
}

void destroi( Lista *L ){
    while( *L != NULL ){
        Lista n = *L;
        *L = n->prox;
        free( n );
    }    
}

int len( Lista l ){
    if( l == NULL ) return 0;
    return len( l->prox ) + 1; 
}

int pert( Item x, Lista l ){
    if( l == NULL ) return 0;
    if( x == l->item ) return 1;
    return pert( x, l->prox );
}

Lista clone( Lista l ){
    if( l == NULL ) return NULL;
    return no( l->item, clone( l->prox ) );
}

void exibe_inv( Lista l ){
    if( l == NULL ) return;
    exibe_inv( l->prox );
    printf( fmt, l->item );
}