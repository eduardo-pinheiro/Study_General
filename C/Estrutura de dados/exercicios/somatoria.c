//Crie uma função recursiva soma(num) que dado o numero natural num, retorne a somatorio do mesmo.
#include <stdio.h>

int soma( int num ){

    if( num == 0 ) return num;
    
    return soma( num - 1 ) + num;
}

void main(){
    
    int num;
    
    printf("Digite um numero e veja a somatoria: \n");
    scanf("%d", &num);
    
    printf("A somatoria de %d = %d", num, soma( num ) );
}