/*
Nome: Eduardo Felipe Santos Pinheiro RA:18101578
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

FILE* openFile(char* file){
   FILE *pFile;
   if((pFile = fopen(file,"r")) == NULL){
       printf("Erro: Arquivo nao encontrado!\n");
       exit(1);
   }
   return pFile;
}

char *readFile(FILE* file, char* string, int* sizeString){
    while ( !feof(file) ){
        sizeString[0]++;
        string = (char*) realloc( string, sizeString[0]*sizeof(char) );
        fscanf(file, "%c", &string[ sizeString[0] - 2 ]);           
    }
    string[ sizeString[0] - 2 ] = '\0';
    return string;
}

void readExtension(char *fileName, char *extension){
    int i = 0, j = 0;

    for (i; i>-1; i++){
        if (fileName[i] == '.'){
            for(j; j<4; j++){
                extension[j] = fileName[i+1];
                i++;
            }            
            break;
        }           
    }
}

int compareString(char* string1, char* string2, int sizeString){
    int i = 0;
    for (i; i<sizeString; i++){
        if (string1[i] != string2[i]) return 0;
    }
    return 1;
}

void buildNameFile(char* fileName, char* extension){
    int i = 0, j = 0;

    for (i; i>-1; i++){
        if (fileName[i] == '.'){
            for(j; j<4; j++){
                fileName[i+1] = extension[j];
                i++;
            }            
            break;
        }           
    }
}

void invert(char* text, int sizeText, char* extension, char* nameFile){           
    int i = 0;
    char extensionCompare[] = "inv";
    FILE* invert;
    
    if (compareString(extension, extensionCompare, 4) == 0){        
        for(i; i<sizeText-2; i++){
            text[i]++;
        } 
        extension = "inv";
    } else {
        for(i; i<sizeText-2; i++){
            text[i]--;
        }  
        extension = "dnv";        
    }    
    
    buildNameFile(nameFile, extension);
    invert = fopen(nameFile,"w");
    for(i=0; i<sizeText-2; i++){
        fprintf(invert, "%c", text[i]);
    } 
}

void cript(char* text, int sizeText, char* extension, char* nameFile, char* key){
    int i = 0, j = 0;
    FILE* criptFile;
    char extensionCompare[] = "crp";

    if (compareString(extension, extensionCompare, 4) == 0) extension = "crp";
    else extension = "drp";
    
    buildNameFile(nameFile, extension);
    criptFile = fopen(nameFile,"w");

    for (i; i<sizeText-2; i++){
        if(key[j] == '\0') j = 0;

        text[i] = text[i] ^ key[j]; 
        fprintf(criptFile, "%c", text[i]);
        j++;        
    } 

     
}

void dos(char* text, int sizeText, char* extension, char* nameFile){
    int i = 0, j = 0;
    
    extension = "dos";
    buildNameFile(nameFile, extension);
    FILE* dos = fopen(nameFile,"w");

    for (i; i<sizeText-2; i++){
        if (text[i] == 0x0A){
            sizeText++;
            text = (char*) realloc( text, sizeText*sizeof(char) );
            j = sizeText-2;
            for(j; j>i; j--){
                text[j] = text[j-1];
            }
            text[i] = 0x0D;
            i++;
        }
    }
    
    for(i=0; i<sizeText-2; i++){
        fprintf(dos, "%c", text[i]);
    }    
}

void unix(char* text, int sizeText, char* extension, char* nameFile){
    int i = 0, j = 0;
    
    extension = "unx";
    buildNameFile(nameFile, extension);
    FILE* unix = fopen(nameFile,"w");

    for (i; i<sizeText-2; i++){
        if (text[i] == 0x0A){
            j = i-1;
            
            for (j; j<sizeText-1; j++){
                text[j] = text[j+1];
            }

            sizeText--;
            text = (char*) realloc( text, sizeText*sizeof(char) );
        }
    }
    
    for(i=0; i<sizeText-2; i++){
        fprintf(unix, "%c", text[i]);
    }    
}

void main(){
    int sizeText[1] = {1};

    char nameFile[100], type, key[100], extension[4], 

    *text = malloc(sizeText[0] * sizeof(char));
    
    printf("Digite o nome do arquivo e o tipo de conversao:\n");
    scanf("%s %c", &nameFile, &type);
    if (type == 'C'){
        printf("Digite a chave:\n");
        scanf("%s", &key);
    }

    FILE* file = openFile(nameFile);
    text = readFile(file, text, sizeText);       
    readExtension(nameFile, extension);
    
    switch(type){
        case 'I':
            invert(text, sizeText[0], extension, nameFile);
            break;
        case 'C':
            cript(text, sizeText[0], extension, nameFile, key);
            break;
        case 'D':
            dos(text, sizeText[0], extension, nameFile);
            break;
        case 'U':
            unix(text, sizeText[0], extension, nameFile);
            break;    
    }
    
    if (type != 'I' && type != 'C' && type != 'D' && type != 'U') printf("\nErro: Operacao invalida!");    
}