#include "localidades.h"
#include "censista.h"

#ifndef ZONA_H_
#define ZONA_H_

typedef struct {
	int id;
	char calles[3][50];
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
/// @brief permite cargar una zona
///
/// @pre
/// @post
/// @param zonas
/// @param lenZonas
/// @param localidades
/// @param lenLocalidades
/// @param id
/// @return 1 para ok, 0 para no
int cargarZona(eZona zonas[],int lenZonas,eLocalidad localidades[], int lenLocalidades,int* id);
/// @brief inicializa las zonas dandole estado pendiente, e isEmpty en 1
///
/// @pre
/// @post
/// @param zonas
/// @param lenZonas
/// @return 1 para si, 0 para no
int inicializarZonas(eZona zonas[], int lenZonas);
/// @brief permite asignar un censista a una zona
///
/// @pre
/// @post
/// @param zonas
/// @param lenZonas
/// @param censistas
/// @param lenCensista
/// @param localidades
/// @param lenLocalidades
/// @return
int asignarZona(eZona zonas[],int lenZonas,eCensista censistas[],int lenCensista,eLocalidad localidades[], int lenLocalidades);
/// @brief permite cargar datos extras a la zona
///
/// @pre
/// @post
/// @param zonas
/// @param lenZonas
/// @param censistas
/// @param lenCensista
/// @param localidades
/// @param lenLocalidades
/// @return 1 para si, 0 para no
int cargaDeDatos(eZona zonas[],int lenZonas,eCensista censistas[],int lenCensista,eLocalidad localidades[], int lenLocalidades);
/// @brief permite buscar la primer zona liberada
///
/// @pre
/// @post
/// @param zonas
/// @param lenZonas
/// @return -1 sino encontro, o el indice si encontro
int buscarLibreZona(eZona zonas[], int lenZonas);
/// @brief busca el primer campo lleno
///
/// @pre
/// @post
/// @param zonas
/// @param len
/// @return 1 si encontro, 0 sino
int buscarPrimerEspacioLlenoZonas(eZona zonas[], int len);
/// @brief
///
/// @pre
/// @post
/// @param zonas
/// @param len
/// @param id
/// @return
int buscarZonaIdCensista(eZona zonas[], int len, int id);
/// @brief mostra las zonas
///
/// @pre
/// @post
/// @param zonas
/// @param lenZonas
/// @param censistas
/// @param lenCensista
/// @param localidades
/// @param lenLocalidades
/// @return 1 si hay, 0 sino hay
int mostrarZonas(eZona zonas[],int lenZonas,eCensista censistas[],int lenCensista,eLocalidad localidades[], int lenLocalidades);
/// @brief muestra solo las zonas que tengan censista
///
/// @pre
/// @post
/// @param zonas
/// @param lenZonas
/// @param censistas
/// @param lenCensista
/// @param localidades
/// @param lenLocalidades
/// @return 1 para ok, 0 sino hay para mostrar
int mostrarZonasConCensista(eZona zonas[],int lenZonas,eCensista censistas[],int lenCensista,eLocalidad localidades[], int lenLocalidades);
/// @brief muestra solo las zonas que no tengan censista
///
/// @pre
/// @post
/// @param zonas
/// @param lenZonas
/// @param censistas
/// @param lenCensista
/// @param localidades
/// @param lenLocalidades
/// @return 1 para ok, 0 sino hay para mostrar
int mostrarZonasSinCensista(eZona zonas[],int lenZonas,eCensista censistas[],int lenCensista,eLocalidad localidades[], int lenLocalidades);
/// @brief muestra zona
///
/// @pre
/// @post
/// @param unaZona
/// @param censistas
/// @param lenCensista
/// @param localidades
/// @param lenLocalidades
void mostrarZona(eZona unaZona,eCensista censistas[],int lenCensista,eLocalidad localidades[], int lenLocalidades);
/// @brief muestra zona
///
/// @pre
/// @post
/// @param unaZona
/// @param censistas
/// @param lenCensista
/// @param localidades
/// @param lenLocalidades
void mostrarZonaSinCensista(eZona unaZona,eCensista censistas[],int lenCensista,eLocalidad localidades[], int lenLocalidades);
/// @brief permite dar de baja a un censista
///
/// @pre
/// @post
/// @param censistas
/// @param len
/// @param zonas
/// @param lenZonas
/// @return 1 si pudo,0 sino
int bajaCensista(eCensista censistas[], int len,eZona zonas[], int lenZonas);

int mostrarCensistasLoc(eCensista censistas[], int len,eZona zonas[], int lenZonas);
