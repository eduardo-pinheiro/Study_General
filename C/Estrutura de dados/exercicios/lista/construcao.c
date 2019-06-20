//Crie a função recursiva progressao_passo(de, ate, passo), que constrói e devolve uma lista com uma sequência
//progressiva de itens, iniciando em "de" e aumentando até no máximo "ate", de "passo" em "passo". 
#include <stdio.h>
#include "../../lib/lista.h" 

Lista progressao_passo( int de, int ate, int passo ){
    
    if( de > ate ) return NULL;

    return no( de, progressao_passo( de + passo, ate, passo ) );
}


void main(){
 
    Lista legal = progressao_passo(0, 7, 2);
    exibe( legal );
}