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

}eCensista;

#endif /* CENSISTA_H_ */

int menu();
int inicializarCensistas(eCensista censistas[], int len);
int buscarCencistaId(eCensista censistas[], int len, int id);
int buscarCencistaIdLiberado(eCensista censistas[], int len, int id);
int buscarLibre(eCensista censistas[], int len);
int buscarPrimerEspacioLleno(eCensista censistas[], int len);
int altaCensista(eCensista censistas[], int len, int* pId);
void mostrarCensista(eCensista unCensista);
int mostrarCensistas(eCensista censistas[], int tam);
int modificarCensista(eCensista censistas[], int len);
int cargarDescripcionCensistaNombre(eCensista censistas[],int tam,int id,char nombre[]);
int cargarDescripcionCensistaApellido(eCensista censistas[],int tam,int id,char apellido[]);
int mostrarCensistasLiberados(eCensista censistas[], int tam);
int bajaCensista(eCensista censistas[], int len);
