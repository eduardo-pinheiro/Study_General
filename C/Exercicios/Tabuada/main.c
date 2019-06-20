#include <stdio.h>
#include <conio.h>

int main(){
    int c, i;

    for(c=1; c<=9; c++) {
        for(i=1; i<=9; i++)
            printf("%d * %d = %d \n", c, i, c*i);
        printf("\n");
    }
}
