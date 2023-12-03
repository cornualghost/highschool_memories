#include <stdio.h>
#include <stdlib.h>
#define MIN 1
#define MAX 1000

int inputDato(char *, int, int);
int menu();
int conteggio(int, int);
void inizializzoVettore(int *, int);
void conversione(int *, int, int, int);
void visualizzazione(int *, int);

int main (){
	int coppieG, coppieG2, coppieG3, coppieG4, i, sceltaG, valoreG;
	coppieG = 0 ; coppieG2 = 0 ; coppieG3 = 0 ;coppieG4 = 0; i = 0; sceltaG = 0; valoreG = 0; 
	printf("Questo programma converte un numero in base decimale in altri formati.\n");
	valoreG = inputDato("Inserire il valore", MIN, MAX);
	coppieG = conteggio(valoreG, 2);
	int sequenzaG[coppieG];
	inizializzoVettore(sequenzaG, coppieG);
	conversione(sequenzaG, valoreG, 2, coppieG);
	coppieG2 = conteggio(valoreG, 8);
	int sequenzaG2[coppieG2];
	inizializzoVettore(sequenzaG2, coppieG2);
	conversione(sequenzaG2, valoreG, 8, coppieG2);
	coppieG3 = conteggio(valoreG, 16);
	int sequenzaG3[coppieG3];
	inizializzoVettore(sequenzaG3, coppieG3);
	conversione(sequenzaG3, valoreG, 16, coppieG3);
	coppieG4 = conteggio(valoreG, 20);
	int sequenzaG4[coppieG4];
	inizializzoVettore(sequenzaG4, coppieG4);
	conversione(sequenzaG4, valoreG, 20, coppieG4);
	do {
		sceltaG=menu();
		switch (sceltaG){
			case 1: 
				printf("Il numero  %d in binario e'", valoreG);
				visualizzazione(sequenzaG, coppieG);
				printf("\n");
				system("PAUSE");
				break;
			case 2:
				printf("Il numero  %d in base ottava e'", valoreG);
				visualizzazione(sequenzaG2, coppieG2);
				printf("\n");
				system("PAUSE");
				break;
			case 3:
				printf("Il numero  %d in base esadecimale e'", valoreG);
				visualizzazione(sequenzaG3, coppieG3);
				printf("\n");
				system("PAUSE");
				break;
			case 4:
				printf("Il numero  %d in base vigesimale e'", valoreG);
				visualizzazione(sequenzaG4, coppieG4);
				printf("\n");
				system("PAUSE");
				break;
		}
	} while (sceltaG != 0);
	printf("\n");
	system("PAUSE");
	return 0;
}

int inputDato(char*msg, int min, int max){
	int dato;
	dato = 0;
	do{
		printf("%s incluso tra %d e %d(estremi inclusi)\n", msg, min, max);
		scanf("%d", &dato);
		if (dato < min || dato > max)
			printf("Il valore deve essere compreso tra %d e %d\n", min, max);
	}while (dato < min || dato > max);
	return dato;
}

int menu(){
	int sceltaL; sceltaL=0;
	do{
		system("CLS");
		printf("Seleziona un' opzione:\n");
		printf("1. Converti in binario\n");
		printf("2. Converti in ottale\n");
		printf("3. Converti in esadecimale\n");
		printf("4. Converti in vigesimale\n");
		printf("0. Esci\n");
		scanf("%d", &sceltaL);
		if (sceltaL < 0 || sceltaL > 4){
			printf("Opzione non valida\n");
			system("PAUSE");
		}
	} while (sceltaL < 0 || sceltaL > 4);
	return sceltaL;
}

int conteggio(int valoreL, int base){
	int conteggioL; conteggioL = 0;
	do{
		valoreL= valoreL / base;
		conteggioL++;
	} while (valoreL != 0);
	return conteggioL;
}

void inizializzoVettore(int* vettore, int indice){
	int i; i = 0;
	for (i = 0; i <= indice; i++){
		vettore[i] = 0;
	}
}

void conversione(int*sequenzaL, int valoreL1, int b, int coppieL){
	int i;
	for ( i = 0; i < coppieL; i++ ){
  		sequenzaL[i] = valoreL1 % b;      
    	valoreL1 = valoreL1 / b;                
    } 	
}

void visualizzazione(int * sequenzaL1, int coppieL1){
	int i; i = 0;
	for (i = coppieL1-1; i >= 0; i--){
		if ( sequenzaL1[i] < 9)
			 printf("%d", sequenzaL1[i]);
		switch (sequenzaL1[i]) {
			case 10: printf("A");
			break;
			case 11: printf("B");
			break;
			case 12: printf("C");
			break;
			case 13: printf("D");
			break;
			case 14: printf("E");
			break;
			case 15: printf("F");
			break;
			case 16: printf("G");
			break;
			case 17: printf("H");
			break;
			case 18: printf("I");
			break;
			case 19: printf("J");
			break;
		}
	}
}
