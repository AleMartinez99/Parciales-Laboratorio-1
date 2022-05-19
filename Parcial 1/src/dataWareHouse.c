#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataWareHouse.h"
#include "censista.h"
#include "zona.h"

char nombres[10][21] = {
    "Juan",
    "Alejandro",
    "Sofia",
    "Luis",
    "Mabel",
    "Facundo",
    "Julieta",
    "Fernando",
    "Lucia",
    "Miguel"
};

char apellidos[10][21] = {
	"Bernaert",
	"Herrieven",
	"Stibbs",
	"Shorland",
	"Godlonton",
	"Hoofe",
	"Allmen",
	"Ridolfo",
	"Lassey",
	"Giacomasso"
};

char calles[24][50] = {
	"Portage",
	"Duke",
	"High Crossing",
	"Av. Street",
	"Calypso",
	"Graceland",
	"Del Mar",
	"Av. Elcano",
	"Maywood",
	"8th",
	"Kedzie Place",
	"Sullivan Trail",
	"Summit Avenue",
	"Portage Avenue",
	"Grayhawk Center",
	"Marcy Park",
	"Nelson Terrace",
	"Dayton Avenue",
	"Center Point",
	"Logan Alley",
	"Darwin Park",
	"Dakota Alley",
	"Lotheville Hill",
	"Commercial Drive",
};


int alturas[10] = {5004,2025,9844,1,3687,1445,2545,1673,5882,6790};

int dias[10] = {10,15,5,7,28,17,15,1,3,21};
int meses[10] = {10,1,5,7,12,1,3,5,4,9};
int anios[10] = {1999,2001,1940,1988,2000,1955,1972,2000,1999,1998};


int hardcodearCensistas(eCensista censistas[], int len, int cantidad, int* pId){
    int todoOk = 0;

    if(censistas != NULL && len > 0 && cantidad >= 0 && cantidad <= len && pId != NULL) {
        todoOk = 1;
        for(int i = buscarLibre(censistas,len); i < cantidad; i++) {
        	censistas[i].id = *pId;
            (*pId)++;
            strcpy(censistas[i].nombre, nombres[i]);
            strcpy(censistas[i].apellido, apellidos[i]);

            censistas[i].edad = 2022 - anios[i];

            censistas[i].fechaNacimiento.dia = dias[i];
            censistas[i].fechaNacimiento.mes = meses[i];
            censistas[i].fechaNacimiento.anio = anios[i];

            strcpy(censistas[i].direccion.calle, calles[i]);

            censistas[i].direccion.altura = alturas[i];

            censistas[i].estado = 0;
            censistas[i].isEmpty = 0;
        }
    }
    return todoOk;
}

int idLocalidad[10] = {1003,1001,1003,1000,1000,1002,1000,1003,1002,1000};

int hardcodearZonas(eZona zonas[], int len, int cantidad, int* pId){
    int todoOk = 0;
    int j = 0;

    if(zonas != NULL && len > 0 && cantidad >= 0 && cantidad <= len && pId != NULL) {
        todoOk = 1;
        for(int i = buscarLibreZona(zonas,len); i < cantidad; i++) {
        	zonas[i].id = *pId;
            (*pId)++;

            for(int k = 0; k<4;k++) {
            	strcpy(zonas[i].calles[k],calles[k]);
            }

            zonas[i].idLocalidad = idLocalidad[j];
            zonas[i].estado = 0;
            zonas[i].isEmpty = 0;
            zonas[i].tieneCensistaAsignado = 0;
            j++;
        }
    }
    return todoOk;
}

