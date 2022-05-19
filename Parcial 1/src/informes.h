#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "localidades.h"
#include "censista.h"
#include "zona.h"

#ifndef INFORMES_H_
#define INFORMES_H_



#endif /* INFORMES_H_ */

int promedioCensistas(eCensista censistas[],int lenCensistas,eZona zonas[],int lenZonas,eLocalidad localidades[], int lenLocalidades);
int censistaMayorZonaCensada(eCensista censistas[],int lenCensistas,eZona zonas[],int lenZonas,eLocalidad localidades[], int lenLocalidades);
void informarLocalidadConMasAusentes(eCensista censistas[],int lenCensistas,eZona zonas[],int lenZonas,eLocalidad localidades[], int lenLocalidades);
int ordenadosYMostrarApellidoYNombre(eCensista censistas[],int lenCensistas);
int cantCensistasActivosPendiente(eCensista censistas[], int lenCensista,eZona zonas[],int lenZonas);

