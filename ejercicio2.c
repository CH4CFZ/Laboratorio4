#include <stdio.h>
#include <ctype.h> /*Navegando encontre este header como un auxiliar para lo que se requiere*/
#include <string.h>

/*Aqui defini la funcion mas importante pues abre el archivo */
void abrirArchivo(FILE **archivo) {
	
        *archivo = fopen("input.txt", "r");
        if (*archivo == NULL) {
		
                printf("Error: no se pudo cargar el archivo\n");
        }
}

/*En esta funcion depuro las palabras, es decir las hago minusculas y elimino los caracteres no alfanumericos*/
void depurarPalabra(char original[], char depura[]) {
	
        int i = 0, j = 0; /*Estos enteros se utilizan para recorrer las palabras en busca de lo que se quiere depurar*/

        while (original[i] != '\0') {  /*ciclo para recorrer las palabras*/
                if (isalnum((unsigned char)original[i])) { /*Verifica si es alfanumerico*/ 
                  
		       depura[j] = tolower((unsigned char)original[i]); /*genera la palabra en minuscula*/
                       j++;
                }
                i++;
       }

       depura[j] = '\0'; /*Finaliza la cadena de palabras*/
}

/*Aqui se define otra de las funciones fundamentales par ver si las palabras dentro del archivo son palindromos */
int palindromo(char palabra[]) {
	
        int i = 0; 
        int j = strlen(palabra) - 1; /*Aqui inicio las variables para el inicio y final de las palabras */

        while (i < j) {
		
	    /*se compara el inicio y final de la palabra*/
                if (palabra[i] != palabra[j]) { /*si el inicio y final son diferente no es palindromo*/
                return 0;
                }
        i++; /*si son iguales la comparatoria se va hacia el centro a ver si es palindromo*/
        j--;
        }

        return 1;
}

int main() {
	
        FILE *archivo = NULL;
        abrirArchivo(&archivo);

        if (archivo == NULL) {
		
                return 1;
        }  

        char palabra[25]; /*Esta variable lee las palabras del archivo*/ /*Los tamanos se definieron por el año actual XD*/
        char palabraDepura[25]; /*Esta las depura quitando lo que pide el enunciado*/
        char palindromoMasLargo[25] = ""; /*Esta devuelve el palindromo mas largo*/

        while (fscanf(archivo, "%24s", palabra) == 1) {	/*El %24s hace que se lean hasta 24 caracteres*/
                depurarPalabra(palabra, palabraDepura);  /*guarda la palabra depurada en la variable de antes*/

                if (palindromo(palabraDepura)) {

                        if (strlen(palabraDepura) > strlen(palindromoMasLargo)) { /*Aqui vemos cual palindromo es mas largo*/
                                strcpy(palindromoMasLargo, palabraDepura);
                        }
                }
        }

        fclose(archivo);

        printf("El palindromo mas largo encontrado en el archivo es: %s\n", palindromoMasLargo);

        return 0;
}

