#include <stdio.h>
#include <stdlib.h> 
#include <time.h>


void findLargestLine( int **matrix, int size, int *result) {
	int i;
	int contador =0;
	int maximo =0; /*Aqui defini las variables mas importantes para la matriz y lo que se busca dentro de ellas*/

		for(i = 0; i < size; i++) {
		       for (int j = 0; j < size; j++) { /*ciclo para recorrer la matriz*/
		              
			       if (*(*(matrix + i) + j) == 1) { /*Aqui use aritmetica de punteros para ver si en las posiciones hay 1*/
				     
				      contador ++;
				      if (contador > maximo) {
					
	                                      maximo = contador; /*Actualiza para ver cual es la cadena de 1s mas grande*/
				      }

			       }    else {
				   
				      contador  = 0; /*aqui se reinicia el contador si la posicion es 0*/
			        }
			
		       }
		}

		*result = maximo; /*Le da el valor del resultado al puntero*/
}



void allocateMatrix(int ***matrix, int size) {
	*matrix = (int **)malloc(size * sizeof(int *)); /*ESta funcion no tiene mucha complejidad solo se aplico la teoria de clases*/

        if (*matrix == NULL) {
		printf("Error, no se puede asignar el espacio en memoria");
		exit(1);
	}

	for (int i = 0; i < size; i++) { /*Esto nada mas se usa para verificar si el malloc funciono*/
		*(*matrix + i) = (int *)malloc(size * sizeof(int));
		if (*(*matrix + i) == NULL) {
			printf("Error no se puede asignar el espacio en memoria");
			exit(1);
		}
        }
}
 

void fillMatrix(int **matrix, int size) {
	srand(time(NULL)); /*Aqui hago casi que lo mismo del laboratorio anterior solo que con punteros*/
        for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
			*(*(matrix + i) + j) = rand() % 2; /*aqui desreferencio para acceder al valor del puntero y llenar la matriz*/
		}
	}
}


void printMatrix(int **matrix, int size) {
	printf("Matrix (%d%d):\n", size, size);
	for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
			printf ( "%d " , *(* (matrix + i) + j));
		}
		printf("\n");
	}
}

void freeMatrix(int **matrix, int size) {
	 for (int i = 0; i < size; i++) {
		 free(matrix[i]);
	 }
	 free(matrix);
}

int main () {  /*Aqui nada mas se agregan las funciones hechas y se le pide al usuario el tamano de la matriz */
	int size, largestLine;
	int **matrix = NULL;

	printf("Coloque el tamano de la matriz: ");
	scanf("%d", &size);

	allocateMatrix(&matrix, size);
	fillMatrix(matrix, size);
	printMatrix(matrix, size);

	findLargestLine(matrix, size, &largestLine);
	printf("La secuencia de 1s mas grande es: %d\n", largestLine);

	freeMatrix(matrix, size);

	return 0;
}






