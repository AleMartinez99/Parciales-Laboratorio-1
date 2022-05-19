#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"
#include "string.h"
#include "ctype.h"

int miValidarChar(char cadena[]) {
    int ok = 1;

    for(int i =0;i<strlen(cadena);i++) {
        if(!isalpha(cadena[i])) {
            ok = 0;
            break;
        }
    }
    return ok;
}

int miCorregirVariasCadenasEnUna(char cadena[]) {

	int ok = 0;
	int i = 1;
	if(cadena != NULL ) {
		ok = 1;
		strlwr(cadena);
		cadena[0] = toupper(cadena[0]);
		while(cadena[i] != '\0'){ // USO WHILE PORQ NO SE LA CANT DE ITERACIONES, DPS DE UN ESPACIO EN BLANCO EL SIGUIENTE CARACTER LO PAS OA MAYUSCULA
			if(cadena[i] == ' ') {
				cadena[i+1] = toupper(cadena[i+1]);
			}
			i++;
		}
	}
	return ok;
}

int miCorregirUnaCadena (char cadena[]) {

    int ok= 0;

    if(cadena != NULL) {
        ok = 1;
        strlwr(cadena);
        cadena[0] = toupper(cadena[0]);
    }
    return ok;
}

int miIngresarEntero(char mensaje[])
{
    int num;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%d",&num);

    return num;

}

int miValidarLargoCadena(char cadena[]) {

    int cantidad = 0;

    if(cadena != NULL) {

        while(cadena[cantidad] != '\0') {
            cantidad++;
        }
    }
  return cantidad;

}

int utnGetCadena(char cadena[],char mensaje[],char mensajeError1[], int lenArray) {

	int retorno = 0;
	char auxChar[lenArray];

	if(cadena != NULL && mensaje != NULL && mensajeError1 != NULL  && lenArray > 0) {
		do {
			printf("%s", mensaje);
			fflush(stdin);
			gets(auxChar);
			if(strlen(auxChar) < 3 || strlen(auxChar) > lenArray - 1) {
				printf("%s",mensajeError1);
			}
		}while(retorno != 1);

		strcpy(cadena,auxChar);
	}
	return retorno;
}

int utnGetCadenaSoloCaracteres(char cadena[],char mensaje[],char mensajeError1[], char mensajeError2[], int lenArray) {

	int retorno = 0;
	char auxChar[lenArray];

	if(cadena != NULL && mensaje != NULL && mensajeError1 != NULL && mensajeError2 != NULL && lenArray > 0) {
		do {
			printf("%s", mensaje);
			fflush(stdin);
			gets(auxChar);
			if(strlen(auxChar) < 3 || strlen(auxChar) > 20) {
				printf("%s",mensajeError1);
			} else {
				if(!miValidarChar(auxChar)) {
					printf("%s", mensajeError2);
					retorno = 0;
				} else {
					retorno = 1;
				}
			}
		}while(retorno != 1);

		strcpy(cadena,auxChar);
	}
	return retorno;
}

int utnGetNumeroSoloMinimo( int* pResultado,char* mensaje,char* mensajeError,int minimo) {

    int retorno = 0;
    int auxInt;   // USO ESTE AUXILIAR PARA RECIEN CUANDO EL NUMERO ESTA VALIDADO LO PASO A LA VARIABLE RESULTADO

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL) {

            printf("%s", mensaje);
            fflush(stdin);
            scanf("%d", &auxInt);

       do {

            if(auxInt >= minimo) {
                *pResultado = auxInt;
                retorno = 1;
                break;
            } else {
                printf("%s\n", mensajeError);
                fflush(stdin);
                scanf("%d", &auxInt);

            }

       }while(retorno != 1);
    }

    return retorno;
}

int utnGetNumero( int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo) {

    int retorno = 0;
    int auxInt;   // USO ESTE AUXILIAR PARA RECIEN CUANDO EL NUMERO ESTA VALIDADO LO PASO A LA VARIABLE RESULTADO

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo) {

            printf("%s", mensaje);
            fflush(stdin);
            scanf("%d", &auxInt);

       do {

            if(auxInt >= minimo && auxInt <= maximo) {
                *pResultado = auxInt;
                retorno = 1;
                break;
            } else {
                printf("%s\n", mensajeError);
                fflush(stdin);
                scanf("%d", &auxInt);

            }

       }while(retorno != 1);
    }

    return retorno;
}

int utnGetNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo) {

    int retorno = 0;
    float auxFloat;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo) {

        do {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%f", &auxFloat);

            if(auxFloat >= minimo && auxFloat <= maximo) {
                *pResultado = auxFloat;
                retorno = 1;
                break;
            } else {
                printf("%s\n", mensajeError);

            }
        }while(retorno != 1);
    }
    return retorno;
}

int utnGetNumeroFlotanteSoloMinimo(float* pResultado,char* mensaje,char* mensajeError,float minimo) {

    int retorno = 0;
    float auxFloat;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL) {

        do {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%f", &auxFloat);

            if(auxFloat >= minimo ) {
                *pResultado = auxFloat;
                retorno = 1;
                break;
            } else {
                printf("%s\n", mensajeError);

            }
        }while(retorno != 1);
    }
    return retorno;
}
