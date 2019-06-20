/*
   Eduardo Felipe Santos Pinheiro 18101578
   Eduardo Ferreira de Lima 18101362
   Lucas Vinicius Gomes Silva  18101246
   Wiliam Otto Keltke Santos Junior 18101498
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int getCurrentYear(){
   time_t rawtime;
   struct tm *info;
   time( &rawtime );
   info = localtime( &rawtime );
   return info->tm_year;
}
int getYear(){
   int y, currentY = (1900+getCurrentYear());
   printf("Digite o ano desejado: ");
   scanf("%d",&y);
   if(y < 2016)
      printf("O ano deve ser, no minimo, 2016\n");
   else if( y > currentY)
      printf("Ano maior que o atual\n");
   else return y;
      getYear();
}
 
int getMonth(){
   int m;
   printf("Digite o mes desejado: ");
   scanf("%d",&m);
   if(m >12 || m < 1){
      printf("Mes invalido\n");
      getMonth();
   } else return m;
}
 
int daysInMonth(int month, int year){
   if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
      return 31;
   else if(month == 4 || month == 6 || month == 9 || month == 11)
      return 30;
   else if(month ==2){
      if(year % 4 == 0)
         return 29;
      else return 28;
   }  
}
 
FILE* openFile(char* file){
   FILE *pFile;
   if((pFile = fopen(file,"r")) == NULL){
       printf("Error\n");
       exit(1);
   }
   return pFile;
}
 
double finalPrice(double price, double profit){
   return price +((profit/100)* price);
}
 
double discountPrice(){
   double randVar;
   do{
      if(rand()%2 == 0)
         randVar = (rand()%9) * -1;
      else
         randVar = (rand()%9);
   } while( randVar == 0);
   return randVar;
}
 
double variablePrice(double price){
   if(rand()%100 < 35){
      return price + ((discountPrice()/100)*price);
   } else
      return price;
}
 
int countLines(FILE* pFile){
   char caracter;
   int lines = 1;
 
   while(!feof(pFile)){
      fread(&caracter, 1, 1, pFile);
 
      if (caracter == '\n')
          lines++;
   }
 
   return lines;
}
 
 
typedef struct Product_list{
   int productCode;
   char storage;
   double qttStorage;
   double unityCost;
   double profitMargin;  
   struct Product_list *next;
} product;
 
product *insert_beginning(product *start, product *p){
   p->next = start;
   start = p;
   return start;
}
 
product *insert(product *start, product *p, FILE *pFile){
   p = malloc(sizeof(product));      
   fscanf(pFile,"%d;%c;%lf;%lf;%lf;", &p->productCode, &p->storage, &p->qttStorage, &p->unityCost, &p->profitMargin);
         
   start = insert_beginning(start, p);
   return start;
}
 
void show(product *p){
   while(p!=NULL){
      printf("Codigo: %d, Nome: %c, Qtd: %0.2lf\n", p->productCode, p->storage, p->qttStorage);
      p=p->next;
   }
}
 
double soldQtt (char storage, double max){
   double k, d;
   
   d = (double) rand () / ((double) RAND_MAX + 1);
   k = d * (max + 1);
   if(storage == 'U')
   k = (int)k;
   if(storage == 'P')
      k += k *0.1;
   if(k == 0.0)  
   k = soldQtt(storage, max);
   return k;
}
 
 
int main(void){
   FILE* pFile = openFile("produtos.txt");
   product *start,*p;
   start = NULL;
   int month, year, qttDay, qttLines, i=0;
 
   year = getYear();
   month = getMonth();
   printf("Quantidade de vendas por dia: ");
   scanf("%d",&qttDay);
   qttLines = qttDay * daysInMonth(month, year);
     
   int lines = countLines(pFile);
   int vetor[lines];
   rewind(pFile);
   
   for(i; i<lines; i++){
     start = insert(start,p, pFile);
   }
 
   pFile = fopen("sales.txt","w");
   
   i = 1;
   for(i; i<= daysInMonth(month, year); i++){
      int j=0;
      for(j;j<qttDay; j++){
      product *newStart;
     
      newStart = start;
      int k = 0, final = rand()%lines;
      for(k;k<final;k++)
         newStart = newStart->next;
      double sold = soldQtt(newStart->storage, newStart->qttStorage);
      double price = finalPrice(newStart->unityCost, newStart->profitMargin);
      price = variablePrice(price);
      fprintf(pFile,"%d;%02d;%02d;%d;%0.3lf;%0.2lf;\n",year, month, i,newStart->productCode,sold, price);
     
      }
     
   }
   
   return 0;
}