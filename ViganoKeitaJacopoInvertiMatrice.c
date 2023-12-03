#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MIN 1
#define MAX 10
#define R 5
#define C 5

void inizializzaMatrice(int*,int, int);
void caricaMatrice(int*, int, int, int, int);
void invertiMatrice(int*, int, int);
void caricaMatriceInversa(int*, int, int);
void visualizzaMatrice(int*, int, int);

int main () {
    int matrice[R*C];
    srand((unsigned)time(NULL));
    printf("Matrice caricata:\n\n");
    caricaMatrice(matrice, R, C, MAX, MIN);
    visualizzaMatrice(matrice, R, C);
    printf("Matrice invertita\n\n");
    //caricaMatriceInversa(matrice, R, C);
    invertiMatrice(matrice, R, C);
    visualizzaMatrice(matrice, R, C);
    system("PAUSE");
    return 0;
}

void inizializzaMatrice(int*m, int r, int c){
    int i, j;
    for (i=0; i<r; i++){
        for (j=0; j<c; j++){
            m[i*r+j]=0;
        }
    }
}
void caricaMatrice(int*m, int r, int c, int max, int min){
    int i, j;
    for (i=0; i<r; i++){
        for (j=0; j<c; j++){
            m[i*r+j]=rand()%(max+1-min)+min;
        }
    }
}

void invertiMatrice(int*m, int r, int c){
	int i, j, k, l, n, u; n=0; u=0; k=r-1; l=c-1;
	for (i=0; i<(r/2); i++){
		for (j=0; j<c; j++){
			u=m[i*r+j];
			m[i*r+j]=m[k*r+l];
			m[k*r+l]=u;
			l--;
		}
	}
	if (r%2==1){
		u=0; l=c-1;
		for (j=0; j<(c/2); j++){
			u=m[(r/2)*r+j];
			m[(r/2)*r+j]=m[(r/2)*r+l];
			m[(r/2)*r+l]=u;
			l--;
		}
	}
}

void caricaMatriceInversa(int *matE, int r, int c){
    int i, j;
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            matE[i*c+j]=r*c-(i*c+j)-1;
        }
    }
}

void visualizzaMatrice(int*m, int r, int c){
    int i, j;
    for (i=0; i<r; i++){
        for (j=0; j<c; j++){
            printf("%4d", m[i*r+j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
