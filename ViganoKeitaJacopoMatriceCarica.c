#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define R 10
#define C 10

void inizializzaMatrice(int*, int, int);
void caricaAzteca(int*, int, int);
void caricaDoppi(int*, int, int);
void caricaTraslata(int*, int, int);
void caricaZigZag(int*, int, int);
void caricaDiagonale(int*, int, int);
void visualizzaMatrice(int*, int, int);

int main() {
	int mat[R*C];
	inizializzaMatrice(mat, R, C);
	printf("\n\ncarica azteca:\n\n");
	caricaAzteca(mat, R, C);
	visualizzaMatrice(mat, R, C);
	printf("\n\ncarica a doppi gradini:\n\n");
	caricaDoppi(mat, R, C);
	visualizzaMatrice(mat, R, C);
	printf("\n\ncarica traslata:\n\n");
	caricaTraslata(mat, R, C);
	visualizzaMatrice(mat, R, C);
	printf("\n\ncarica zigzag:\n\n");
	caricaZigZag(mat, R, C);
	visualizzaMatrice(mat, R, C);
	printf("\n\ncarica diagonale:\n\n");
	caricaDiagonale(mat, R, C);
	visualizzaMatrice(mat, R, C);
	system("PAUSE");
	return 0;
}

void inizializzaMatrice(int* matrice, int r, int c){
	int i, j;
		for (i=0; i<r; i++){
			for (j=0; j<c; j++){	
				matrice[i*c+j]=0;
			}
		}
}

void caricaAzteca(int* matrice, int r, int c){
	int i, j, k, l, m, u;
	u=r; m=1; k=0;
	for (l=0; l<(r/3); l++){
		for (i=0; i<u; i++){
			for (j=0; j<u; j++){
					matrice[((i+k)*c)+(j+k)]=m;
			}
		}
		k=k+2;
		m=m+2;
		u=u-4;
	}
}

void caricaDoppi(int*matrice, int r, int c){
	int i, j, k, l, m, u;
	u=r; m=1; k=0;
	for (l=0; l<(r/2); l++){
		for (i=0; i<u; i++){
			for (j=0; j<u; j++){
					matrice[((i+k)*c)+(j+k)]=m;
			}
		}
		m++;
		k++;
		u=u-2;
	}
}

void caricaTraslata(int*matrice, int r, int c){
	int i, j;
	for (i=0; i<r; i++){
		for (j=0; j<c; j++){
				matrice[i*c+j]=i+1+j;
		}
	}
}

void caricaZigZag(int*matrice, int r, int c){
	int i, j; 
	for (i=0; i<r; i++){
			if (i%2==0){
				for (j=0; j<c; j++){
					matrice[i*r+j]=i*r+j+1;
				}
			}
			else{
				for (j=0; j<c; j++){
					matrice[i*r-j+r-1]=i*r+j+1;
				}
			}
		}
}

void caricaDiagonale(int*matrice, int r, int c){
	int i, j, k, l; k=0; l=1;
	for (i=0; i<r; i++){
		for (j=0; j<(c-k); j++){
				matrice[i*c+(j+k)]=j+1;
		}
		k++;
	}
	for (i=0; i<r; i++){
		for (j=0; j<l; j++){
				matrice[i*c+j]=l-j;
		}
		l++;
	}
}

void visualizzaMatrice(int* matrice, int r, int c){
	int i, j;
		for (i=0; i<r; i++){
			for (j=0; j<c; j++){	
				printf("%4d", matrice[i*c+j]);
			}
			printf("\n\n");
		}
}
