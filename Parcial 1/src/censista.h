#include "fecha.h"
#include "direccion.h"


#ifndef CENSISTA_H_
#define CENSISTA_H_

typedef struct {

	char nombre[21];
	char apellido[21];
	int edad;
	eFecha fechaNacimiento;
	eDireccion direccion;
	int estado;
	int id;
	int isEmpty;

}eCensista;

#endif /* CENSISTA_H_ */
/// @brief menu general
///
/// @pre
/// @post
/// @return retorna la opcion elegida
int menu();
/// @brief Inicializa todos los campos censista en 1
///
/// @pre
/// @post
/// @param censistas
/// @param len
/// @return 1 ok, 0 no pudo
int inicializarCensistas(eCensista censistas[], int len);
/// @brief busca censista por id
///
/// @pre
/// @post
/// @param censistas
/// @param len
/// @param id
/// @return -1 sino, indice si encontro
int buscarCencistaId(eCensista censistas[], int len, int id);
/// @brief busca censista liberado por id
///
/// @pre
/// @post
/// @param censistas
/// @param len
/// @param id
/// @return -1 sino, indice si encontro
int buscarCencistaIdLiberado(eCensista censistas[], int len, int id);
/// @brief busca primer espacio libre
///
/// @pre
/// @post
/// @param censistas
/// @param len
/// @return -1 sino, indice si encontro
int buscarLibre(eCensista censistas[], int len);
/// @brief busca primer espacio ocupado
///
/// @pre
/// @post
/// @param censistas
/// @param len
/// @return 1 si encontro, 0 sino
int buscarPrimerEspacioLleno(eCensista censistas[], int len);
/// @brief da de alta un censista
///
/// @pre
/// @post
/// @param censistas
/// @param len
/// @param pId
/// @return 1 si pudo, 0 sino
int altaCensista(eCensista censistas[], int len, int* pId);
/// @brief muestra censistas
///
/// @pre
/// @post
/// @param unCensista
void mostrarCensista(eCensista unCensista);
/// @brief muestra censistas
///
/// @pre
/// @post
/// @param censistas
/// @param tam
/// @return 1 si, 0 sino hay pa mostrar
int mostrarCensistas(eCensista censistas[], int tam);
/// @brief permite cambiar cualquier campo de la estrucutra censista
///
/// @pre
/// @post
/// @param censistas
/// @param len
/// @return 1 si, 0 sino hay pa mostrar
int modificarCensista(eCensista censistas[], int len);
/// @brief permite pasandole un id, cargar el nombre de esa estructura en una cadena
///
/// @pre
/// @post
/// @param censistas
/// @param tam
/// @param id
/// @param nombre
/// @return 1 si pudo, 0 sino
int cargarDescripcionCensistaNombre(eCensista censistas[],int tam,int id,char nombre[]);
/// @brief permite pasandole un id, cargar el apellido de esa estructura en una cadena
///
/// @pre
/// @post
/// @param censistas
/// @param tam
/// @param id
/// @param apellido
/// @return 1 si pudo, 0 sino
int cargarDescripcionCensistaApellido(eCensista censistas[],int tam,int id,char apellido[]);
/// @brief muestra los censistas liberaddos
///
/// @pre
/// @post
/// @param censistas
/// @param tam
/// @return 1 si pudo, 0 si no hay pa mostrar
int mostrarCensistasLiberados(eCensista censistas[], int tam);

