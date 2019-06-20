#include <stdlib.h>
#include <time.h>

typedef int Item;

typedef struct arv {
    struct arv *esq;
    Item item;
    struct arv *dir;
} *Arv;

Arv arv( Arv e, Item x, Arv d ) {
    Arv n = malloc( sizeof( struct arv ) );
    n->esq = e;
    n->item = x;
    n->dir = d;
    return n;
}

void ins( Item x, Arv *A ) {
    if( *A == NULL ) *A = arv( NULL, x, NULL );
    else if ( x <= (*A)->item ) ins( x, &(*A)->esq );
    else ins( x, &(*A)->dir);
}

void exibe( Arv A, int n ) {
    if( A == NULL ) return;
    exibe( A->dir, n+1);
    printf( "%*s%d\n", 3*n, "", A->item );
    exibe( A->esq, n+1);
}



//Algoritmos de construção

Arv aleatoria( Item p, Item u ) {
    if( p > u ) return NULL;
    int m = p + rand() % ( u - p + 1 );
    return arv( aleatoria( p, m - 1), m, aleatoria( m + 1, u ) );
}

Arv balanceada( int p, int u ) {
    if( p > u ) return NULL;
    int m = ( p + u ) / 2;
    return arv( balanceada( p, m - 1 ), m, balanceada( m + 1, u ) );
}

Arv completa( int h ) {
    if( h == 0 ) return NULL;
    return arv( completa( h - 1 ), h, completa( h - 1 ) );
}



/* ALGORITMOS PARA ARVORE DE BUSCA BINÁRIA */
//Algoritmos de Busca

int busca( Item x, Arv A ) {
    if( A == NULL ) return 0;
    if( x == A->item ) return 1;
    if( x < A->item ) return busca( x, A->esq );
    else return busca( x, A->dir );
}

Item buscaMaior( Arv A ) {
    if( A == NULL ) abort;
    if( A->dir == NULL ) return A->item;
    buscaMaior( A->dir );
}

Item buscaMenor( Arv A ) {
    if( A == NULL ) abort;
    if( A->esq == NULL ) return A->item;
    buscaMaior( A->dir );
}



//Algoritmos de exibição

void emOrdem( Arv A ) {
    if( A == NULL ) return;
    emOrdem( A-> esq );
    printf( "%d ", A->item );
    emOrdem( A-> dir );
}

void preOrdem( Arv A ) {
    if( A == NULL ) return;
    printf( "%d ", A->item );
    preOrdem( A->esq );
    preOrdem( A->dir );
}

void posOrdem( Arv A ) {
    if( A == NULL ) return;
    emOrdem( A-> esq );
    emOrdem( A-> dir );
    printf( "%d ", A->item );
}



//Algoritmos para remoção

Item rem_max( Arv *A ) {
   if( *A == NULL ) abort();
   if( (*A)->dir != NULL ) return rem_max( &(*A)->dir );
   Arv n = *A;
   Item x = n->item;
   *A = n->esq;
   free( n );
   return x;
}

Item rem_min(Arv *A) {
   if( *A == NULL ) abort();
   if( (*A)->esq != NULL ) return rem_min( &(*A)->esq );
   Arv n = *A;
   Item x = n->item;
   *A = n->dir;
   free( n );
   return x;
}