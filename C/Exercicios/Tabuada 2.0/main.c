#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
    int c, i, valor;
    
    while(c != 27){
        system("cls");

        printf("Digite um inteiro para ver sua tabuada: ");
        scanf("%d", &valor);

        for (i=1; i<=9; i++) printf("%d * %d = %d \n", i, valor, valor*i);

        printf("\nPara sair digite ESC, qualquer outra tecla continuara o programa:");
        
        c = getch();
    }
    return 0;
}