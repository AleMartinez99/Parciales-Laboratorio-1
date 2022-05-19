#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "censista.h"
#include "zona.h"
// A
int cantCensistasActivosPendiente(eCensista censistas[], int lenCensista,eZona zonas[],int lenZonas) {

	int cantCensistas = -1;
	int idCensista;
	int indiceZona;

	if(censistas != NULL && lenCensista > 0 && zonas != NULL && lenZonas > 0) {
		cantCensistas = 0;
		for(int i = 0; i< lenCensista;i++) {
			idCensista = censistas[i].id;
			indiceZona = buscarZonaIdCensista(zonas,lenZonas,idCensista);
			if(censistas[i].estado == 1 && zonas[indiceZona].estado == 0) {
				cantCensistas++;
			}
		}
	}
	return cantCensistas;
}

// B

int ordenadosYMostrarApellidoYNombre(eCensista censistas[],int lenCensistas) {
	int ok = 0;
	eCensista aux;

	if(censistas != NULL && lenCensistas > 0) {

		for(int i = 0;i < lenCensistas -1;i++) {
			for(int j = i+ 1; j < lenCensistas;j++) {

				if(stricmp(censistas[i].apellido, censistas[j].apellido) < 1 ||
					(stricmp(censistas[i].apellido, censistas[j].apellido) == 0 && stricmp(censistas[i].nombre, censistas[j].nombre) < 1)) {

					aux = censistas[i];
					censistas[i] = censistas[j];
					censistas[j] = aux;

				}
			}
		}

	}

	return ok;
}

// C

void informarLocalidadConMasAusentes(eCensista censistas[],int lenCensistas,eZona zonas[],int lenZonas,eLocalidad localidades[], int lenLocalidades) {
	int ausentes[] = {0,0,0,0}; // 1000,1001,1002,1003
	int indiceMax;
	int maximo;
	char localidad[20];

	for(int i = 0;i < lenZonas;i++) {
		if(zonas[i].estado == 1 &&zonas[i].idLocalidad == 1000) {
			ausentes[0] += zonas[i].cantAusentes;
		}
	}
	for(int i = 0;i < lenZonas;i++) {
			if(zonas[i].estado == 1 &&zonas[i].idLocalidad == 1001) {
				ausentes[1] += zonas[i].cantAusentes;
			}
		}
	for(int i = 0;i < lenZonas;i++) {
			if(zonas[i].estado == 1 &&zonas[i].idLocalidad == 1003) {
				ausentes[2] += zonas[i].cantAusentes;
			}
		}
	for(int i = 0;i < lenZonas;i++) {
			if(zonas[i].estado == 1 &&zonas[i].idLocalidad == 1004) {
				ausentes[3] += zonas[i].cantAusentes;
			}
	}

	maximo = ausentes[0];
	indiceMax = 0;
	for(int i =1;i<3;i++) {
		if(ausentes[i] > maximo){
			maximo = ausentes[i];
			indiceMax = i;
		}
	}

	cargarDescripcionLocalidad(localidades, lenLocalidades, indiceMax + 1000,localidad);

	printf("La localidad con mas ausentes es: %s", localidad);

}

// D

int censistaMayorZonaCensada(eCensista censistas[],int lenCensistas,eZona zonas[],int lenZonas,eLocalidad localidades[], int lenLocalidades) {
	int ok = 0;
	int mayorCensada[lenZonas];
	int suma;
	int indiceMax;
	int flag = 1;
	int max;
	int idCensista;
	int indiceCensista;
	if(censistas != NULL && lenCensistas > 0 && zonas != NULL && lenZonas > 0 && localidades != NULL && lenLocalidades > 0) {
		ok = 1;
		for(int i = 0;i<lenZonas;i++) {
			if(zonas[i].estado == 1) {
				suma = zonas[i].cantCensadosSitu + zonas[i].cantCensadosVirtual;
				mayorCensada[i] = suma;
				if(mayorCensada[i] > max || flag) {
					max = mayorCensada[i];
					indiceMax = i;
					flag = 0;
				}
			}
			idCensista = zonas[indiceMax].idCensista;
			indiceCensista = buscarCencistaId(censistas,lenCensistas,idCensista);

			printf("El censista cuya zona fue las mas censada es:\n");
			mostrarCensista(censistas[indiceCensista]);
		}
	}
	return ok;
}

// E

int promedioCensistas(eCensista censistas[],int lenCensistas,eZona zonas[],int lenZonas,eLocalidad localidades[], int lenLocalidades) {

	int ok;
	int sumaCensados[lenCensistas];
	int cantidadZonasCensadas[lenCensistas];
	float promedios[lenCensistas];

	for(int i = 0;i<lenCensistas;i++) {
		sumaCensados[i] = 0;
		cantidadZonasCensadas[i] = 0;
	}

	if(censistas != NULL && lenCensistas > 0 && zonas != NULL && lenZonas > 0 && localidades != NULL && lenLocalidades > 0) {
		ok = 1;
		for(int i = 0;i<lenCensistas;i++) {

			for(int j = 0;j<lenZonas;j++) {
				if(zonas[j].idCensista == censistas[i].id) {
					sumaCensados[i] += zonas[j].cantCensadosSitu + zonas[j].cantCensadosVirtual;
					cantidadZonasCensadas[i]++;
				}
			}
		}
		for(int i = 0;i<lenCensistas;i++) {
			promedios[i] = sumaCensados[i] / cantidadZonasCensadas[i];
			printf("El censista %s tiene un promedio de %.2f censados",censistas[i].nombre,promedios[i]);
		}
	}

	return ok;
}
