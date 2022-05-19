#include <stdio.h>
#include <stdlib.h>

#ifndef MIBIBLIOTECA_H_
#define MIBIBLIOTECA_H_


#endif /* MIBIBLIOTECA_H_ */
/// @brief Pide un numero flotante al usuario
///
/// @pre
/// @post
/// @param pResultado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @return retorna 1 para OK, 0 sino pudo
int utnGetNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo);

/// @brief Pide un numero entero al usuario
///
/// @pre
/// @post
/// @param pResultado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @return retorna 1 para OK, 0 sino pudo
int utnGetNumero( int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo);

/// @brief Permite poner la primera letra mayuscula a una cadena y el resto en minuscula
///
/// @pre
/// @post
/// @param cadena
/// @return retorna 1 para OK, 0 sino pudo
int miCorregirUnaCadena (char cadena[]);

/// @brief Pide un numero flotante al usuario, mayor a un minimo
///
/// @pre
/// @post
/// @param pResultado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @return retorna 1 para OK, 0 sino pudo
int utnGetNumeroFlotanteSoloMinimo(float* pResultado,char* mensaje,char* mensajeError,float minimo);

/// @brief Pide un numero entero al usuario
///
/// @pre
/// @post
/// @param mensaje
/// @return retorna 1 para OK, 0 sino pudo
int miIngresarEntero(char mensaje[]);
/// @brief Pide una cadena y valida que solo contenga letras
///
/// @pre
/// @post
/// @param cadena
/// @return 1 para OK, 0 si tiene otros caracteres
int miValidarChar(char cadena[]);

/// @brief Pide una cadena y retorna la cantidad de caracteres
///
/// @pre
/// @post
/// @param cadena
/// @return
int miValidarLargoCadena(char cadena[]);

/// @brief Verifica que una cadena solo contenga letras
///
/// @pre
/// @post
/// @param cadena
/// @param mensaje
/// @param mensajeError1
/// @param mensajeError2
/// @param lenArray
/// @return 1 para OK, 0 si tiene otros caracteres
int utnGetCadenaSoloCaracteres(char cadena[],char mensaje[],char mensajeError1[], char mensajeError2[], int lenArray);

/// @brief
///
/// @pre
/// @post
/// @param cadena
/// @return
int miCorregirVariasCadenasEnUna(char cadena[]);

/// @brief
///
/// @pre
/// @post
/// @param cadena
/// @param mensaje
/// @param mensajeError1
/// @param lenArray
/// @return
int utnGetCadena(char cadena[],char mensaje[],char mensajeError1[], int lenArray);

/// @brief Pide un numero entero al usuario
///
/// @pre
/// @post
/// @param pResultado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @return retorna 1 para OK, 0 sino pudo
int utnGetNumeroSoloMinimo( int* pResultado,char* mensaje,char* mensajeError,int minimo);
