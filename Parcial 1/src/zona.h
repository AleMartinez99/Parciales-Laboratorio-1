#include "localidades.h"

#ifndef ZONA_H_
#define ZONA_H_

typedef struct {
	int id;
	char calles[3][31];
	int idLocalidad;
	int idCensista;
	int estado;
	int tieneCensistaAsignado;
	int cantCensadosSitu;
	int cantCensadosVirtual;
	int cantAusentes;
	int isEmpty;
} eZona;

#endif /* ZONA_H_ */

int cargarZona(eZona zonas[],int lenZonas,eLocalidad localidades[], int lenLocalidades,int* id);
int inicializarZonas(eZona zonas[], int lenZonas);
int asignarZona(eZona zonas[],int lenZonas,eCensista censistas[],int lenCensista,eLocalidad localidades[], int lenLocalidades);
int cargaDeDatos(eZona zonas[],int lenZonas,eCensista censistas[],int lenCensista,eLocalidad localidades[], int lenLocalidades);

int mostrarZonas(eZona zonas[],int lenZonas,eCensista censistas[],int lenCensista,eLocalidad localidades[], int lenLocalidades);
int mostrarZonasConCensista(eZona zonas[],int lenZonas,eCensista censistas[],int lenCensista,eLocalidad localidades[], int lenLocalidades);
int mostrarZonasSinCensista(eZona zonas[],int lenZonas,eCensista censistas[],int lenCensista,eLocalidad localidades[], int lenLocalidades);
void mostrarZona(eZona unaZona,eCensista censistas[],int lenCensista,eLocalidad localidades[], int lenLocalidades);
void mostrarZonaSinCensista(eZona unaZona,eCensista censistas[],int lenCensista,eLocalidad localidades[], int lenLocalidades);



