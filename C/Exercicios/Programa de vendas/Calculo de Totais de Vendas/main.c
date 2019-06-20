#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct product{
   int productCode;
   char stockType;
   double stockInitial;
   double costPrice;
   double profit;
   double profitability;
   double contribution;
   double allSales;
};

struct date{
   int day;
   int month;
   int year;
};
 
struct sales{
   struct date date;
   int productCode;
   double productQuantity;
   double productPrice;
};

struct general{
   double allSales;
   double allProductQuantity;
   double allUsefulDay;
   double allProfit;
};
 
int compareDates( struct date date1, struct date date2){
   if ( (date1.year < date2.year) || (date1.year == date2.year && date1.month < date2.month) || (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day) ){
     return 2; 
   }else if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day){
     return 0; 
   }else{
      return 1; 
   }
}
 
int weekDay(struct date date) {
   time_t hour;
   struct tm *phour;
   time(&hour);
   phour = localtime(&hour);
   phour->tm_year = date.year - 1900;
   phour->tm_mon = date.month - 1;
   phour->tm_mday = date.day;
   mktime(phour);
   return phour->tm_wday;
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
 
FILE* openFile(char* file){
   FILE *pFile;
   if((pFile = fopen(file,"r")) == NULL){
       printf("Error\n");
       exit(1);
   }
   return pFile;
}
 
void orderByProduct( struct sales *sales, FILE* pFile, int lines ){
   int j, c, first = 0, i;
   struct sales compare;
 
   fscanf(pFile,"%d; %d; %d; %d; %lf; %lf;", &sales[0].date.year, &sales[0].date.month, &sales[0].date.day, &sales[0].productCode, &sales[0].productQuantity, &sales[0].productPrice);
 
   for (i=1; i<lines; i++){
     
      fscanf(pFile,"%d; %d; %d; %d; %lf; %lf;", &compare.date.year, &compare.date.month, &compare.date.day, &compare.productCode, &compare.productQuantity, &compare.productPrice);
     
      for (j=0; j<lines; j++){          
 
         if (compare.productCode >= sales[j].productCode){
 
            for(c = lines-1; c>j; c--){
 
               sales[c] = sales[c-1];
               
            }
 
            sales[j] = compare;
            break;
         }   
      }       
   }  
}
 
void orderByDate( struct sales *sales, FILE* pFile, int lines ){
   int j, c, first = 0, date, i;
   struct sales compare;
 
   fscanf(pFile,"%d; %d; %d; %d; %lf; %lf;", &sales[0].date.year, &sales[0].date.month, &sales[0].date.day, &sales[0].productCode, &sales[0].productQuantity, &sales[0].productPrice);
 
   for (i=1; i<lines; i++){
     
      fscanf(pFile,"%d; %d; %d; %d; %lf; %lf;", &compare.date.year, &compare.date.month, &compare.date.day, &compare.productCode, &compare.productQuantity, &compare.productPrice);
     
      for (j=0; j<lines; j++){      
 
         date = compareDates(compare.date, sales[j].date);
 
         if (date == 1 || date == 0){
 
            for(c = lines-1; c>j; c--){
 
               sales[c] = sales[c-1];
               
            }
 
            sales[j] = compare;
            break;
         }   
      }    
   }  
}

void productOrder( struct product *product, FILE* pFile, int lines ){
   int j, c, first = 0, i;
   struct product compare;
 
   fscanf(pFile,"%d; %c; %lf; %lf; %lf;", &product[0].productCode, &product[0].stockType, &product[0].stockInitial, &product[0].costPrice, &product[0].profit);
   
   for (i=1; i<lines; i++){

      fscanf(pFile,"%d; %c; %lf; %lf; %lf;", &compare.productCode, &compare.stockType, &compare.stockInitial, &compare.costPrice, &compare.profit);
         
      for (j=0; j<lines; j++){          
 
         if (compare.productCode >= product[j].productCode){
 
            for(c = lines-1; c>j; c--){
 
               product[c] = product[c-1];
               
            }
 
            product[j] = compare;
            break;
         }  
      }       
   }  
}

void productOrderProfitability(struct product *product, int lines){
   int i, j;
   struct product c;

   for (i = 1; i < lines; i++) {
      for (j = 0; j < i; j++) {
         if (product[i].profitability > product[j].profitability) {
            c = product[i];
            product[i] = product[j];
            product[j] = c;
        }
      }
   }
}

void productOrderContribution(struct product *product, int lines){
   int i, j;
   struct product c;

   for (i = 1; i < lines; i++) {
      for (j = 0; j < i; j++) {
         if (product[i].contribution > product[j].contribution) {
            c = product[i];
            product[i] = product[j];
            product[j] = c;
        }
      }
   }
}

int selectProduct( int productSearch, struct product *product, int lines ){
   int start = 0, end = lines-1, mid;

   while(start <= end){
      mid = (start + end) / 2;

      if (productSearch > product[mid].productCode){
         end = mid -1;
      } else if (productSearch < product[mid].productCode){
         start = mid + 1;
      } else {
         return mid; break;
      }
   }
}

void loopPerDay( struct sales *sales, int lines, FILE *output, struct general *general ){
   int c = 1, i;   
   double total = 0; 

   fprintf(output,"TOTAIS DE VENDAS POR DIA\nDia;Total;Media/Dia\n");

   general[0].allProductQuantity = 0;
   general[0].allSales = 0;
   general[0].allUsefulDay = 0;

   if ( weekDay(sales[lines-1].date) != 0 ){

      total = sales[lines-1].productPrice * sales[lines-1].productQuantity;

      general[0].allProductQuantity = sales[lines-1].productQuantity;
      general[0].allSales = sales[lines-1].productPrice * sales[lines-1].productQuantity;
      if ( weekDay(sales[lines-1].date) != 6 ) general[0].allUsefulDay = sales[lines-1].productPrice * sales[lines-1].productQuantity;
   } 

   for (i=lines-2; i>=0; i--){
      if ( sales[i].date.year == sales[i+1].date.year && sales[i].date.month == sales[i+1].date.month && sales[i].date.day == sales[i+1].date.day ){
         total += sales[i].productPrice * sales[i].productQuantity;
         c++;
       } else {
         if ( weekDay(sales[i+1].date) != 0 ) fprintf(output,"%02d/%02d/%02d;%0.2lf;%0.2lf\n", sales[i+1].date.day, sales[i+1].date.month, sales[i+1].date.year, total, total / c);
         total = sales[i].productPrice * sales[i].productQuantity;
         c = 1;
      }
      
      if ( weekDay(sales[i].date) != 0 ){
         general[0].allProductQuantity += sales[i].productQuantity;
         general[0].allSales += sales[i].productPrice * sales[i].productQuantity;
         if ( weekDay(sales[i].date) != 6 ) general[0].allUsefulDay += sales[i].productPrice * sales[i].productQuantity;
      } 
   }
   if ( weekDay(sales[0].date) != 0 ) fprintf(output,"%02d/%02d/%02d;%0.2lf;%0.2lf\n\n", sales[0].date.day, sales[0].date.month, sales[0].date.year, total, total / c);
}

void loopPerProduct( struct sales *sales, int salesLines, struct product *product, int productLines, FILE *output, struct general *general ){
   int index, i;

   double 
   productQuantity = sales[salesLines-1].productQuantity, 
   total = 0, 
   profitability;

   general[0].allProfit = 0;

   if ( weekDay(sales[salesLines-1].date) != 0 ) total = sales[salesLines-1].productPrice * sales[salesLines-1].productQuantity;

   fprintf(output, "TOTAIS DE VENDAS POR PRODUTO\nProd;ValrTot;Qtde;Pc Medio;Lucrat\n");   

   for (i=salesLines-2; i>=0; i--){
      if ( sales[i].productCode == sales[i+1].productCode ){
         if ( (weekDay(sales[i].date)) != 0){
            total += sales[i].productPrice * sales[i].productQuantity;
            productQuantity += sales[i].productQuantity;     
         }    
      } else {
         index = selectProduct(sales[i+1].productCode, product, productLines);
         profitability = ( ( (total / productQuantity) / product[index].costPrice ) - 1 ) * 100;
         
         general[0].allProfit += profitability * productQuantity;

         product[index].profitability = profitability;
         product[index].allSales = total;
         product[index].contribution = (total / general[0].allSales) * 100;         

         fprintf(output,"%d;%.2lf;%.0lf;%.2lf;%.1lf\n", sales[i+1].productCode, total, productQuantity, total / productQuantity, profitability);

         if ( (weekDay(sales[i].date)) != 0){
            total = sales[i].productPrice * sales[i].productQuantity;
            productQuantity = sales[i].productQuantity;
         } else {
            total = 0;
            productQuantity = 0;
         }
      }      
   }

   profitability = ( ( (total / productQuantity) / product[0].costPrice ) - 1 ) * 100;   
   general[0].allProfit += profitability * productQuantity;
   fprintf(output,"%d;%.2lf;%.2lf;%.2lf;%.1lf\n\n", sales[0].productCode, total, productQuantity, total / productQuantity, profitability);

   product[0].profitability = profitability;
   product[0].allSales = total;
   product[0].contribution = (total / general[0].allSales) * 100;   
}

void totalStatistic( struct general *general, FILE *output){
   fprintf(output, "TOTAL E ESTATISTICAS DO PERIODO\n");
   fprintf(output, "Total Geral de Vendas (R$): %.2lf\n", general[0].allSales);
   fprintf(output, "Quantidade de produtos vendidos: %.0lf\n", general[0].allProductQuantity);
   fprintf(output, "Media de Vendas por dia util (R$): %.2lf\n", general[0].allUsefulDay);
   fprintf(output, "Media de Vendas por produto (R$): %.2lf\n", general[0].allSales / general[0].allProductQuantity);
   fprintf(output, "Lucratividade Media: %.1lf%%\n\n", general[0].allProfit/general[0].allProductQuantity);
}

void profitability( struct general *general, struct product *product, FILE *output, int lines ){
   int i;

   fprintf(output, "PRODUTOS MAIS LUCRATIVOS\n");
   fprintf(output, "Lucratividade media = %.1lf%%\n", general[0].allProfit/general[0].allProductQuantity);
   fprintf(output, "Prod.;Lucrat.;\n");

   for (i=0; i<lines; i++){
      if (product[i].profitability > general[0].allProfit/general[0].allProductQuantity) fprintf(output, "%d;%0.1lf\n", product[i].productCode, product[i].profitability);
   }  
   fprintf(output, "\n"); 
}

void contribution( struct general *general, struct product *product, FILE *output, int lines ){
   int i;

   fprintf(output, "CONTRIBUICAO DE CADA PRODUTO\nProd.;VlrTot;Contrib;\n");

   for (i=0; i<lines; i++){
      fprintf(output ,"%d %.2lf %.1lf%%\n", product[i].productCode, product[i].allSales, product[i].contribution);
   }   
}

int main(){
   FILE* saleFile = openFile("vendas.txt");
   FILE* productFile = openFile("produtos.txt");
   FILE* totalSalesFile = fopen("TOTVENDAS.TXT","w");   

   int salesLines = countLines(saleFile);
   int productLines = countLines(productFile);
   struct general general[1];
   
   rewind(productFile);
   struct product product[productLines];
   productOrder(product, productFile, productLines); 

   rewind(saleFile);
   struct sales salesPerProduct[salesLines];
   orderByProduct(salesPerProduct, saleFile, salesLines);  
 
   rewind(saleFile);
   struct sales salesPerDate[salesLines];
   orderByDate(salesPerDate, saleFile, salesLines);  

   loopPerDay(salesPerDate, salesLines, totalSalesFile, general); 

   loopPerProduct(salesPerProduct, salesLines, product, productLines, totalSalesFile, general); 

   totalStatistic(general, totalSalesFile);

   productOrderProfitability(product, productLines);
   profitability(general, product, totalSalesFile, productLines);

   productOrderContribution(product, productLines);
   contribution(general, product, totalSalesFile, productLines);
}