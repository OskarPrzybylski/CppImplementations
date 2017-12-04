#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

double determinant(int rozmiar, double* macierz);

double lol(double** const wyz[]kl);

int main(int argc, char* argv[]){
char sizechar;
int sizeint;
double* arguments;
int i=0;
double wynik;
FILE *fp;
if(argc != 2){
printf("blad! podaj tylko jedna nazwe pliku \n");
return 1;
}

fp = fopen(argv[1],"r");
if(fp == NULL){
printf("zla sciezka do pliku lub plik nie istnieje \n");
return 1;
}


fscanf(fp, "%c ", &sizechar);
if(!isdigit(sizechar)){
printf("rozmiar nie jest liczba");
return 1;

}
else{
sizeint = sizechar - '0';
}
arguments = (double*)calloc(sizeint*sizeint,sizeof(double));
for(i=0;i<(sizeint*sizeint);i++){
if((fscanf(fp, "%lf ", &arguments[i])) == 0){
printf("to nie liczba");
return 1;
}
}


wynik = determinant(sizeint, arguments);
printf("Wyznacznik tej macierzy to: %f\n", wynik);
free(arguments);
fclose(fp);
return 0;


}


double determinant(int size, double* arguments){
int i;
int j;
int k;
double wsk;
double final=1;
for(i=0;i<size-1;i++){
for(j=i+1;j<size;j++){

wsk = arguments[i+j*size]/arguments[i+i*size];
for(k=0;k<size;k++){
arguments[j*size+k] = arguments[j*size+k] - (arguments[k+i*size] * wsk);
}
}


}
for(i=0;i<size;i++){
final *= arguments[i*size + i];
}
printf("Twoja macierz po konwersji do macierzy trojkatnej gornej:\n");
for(j=0;j<size;j++){
for(i=0;i<size;i++){
printf("%f ", arguments[i+j*size]);
}
printf("\n");
}
return final;
}


