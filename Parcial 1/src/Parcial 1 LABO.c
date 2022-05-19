#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"
#include "censista.h"
#include "localidades.h"
#include "zona.h"
#include "dataWareHouse.h"

#define C_INACTIVO -1
#define C_LIBERADO 0
#define C_ACTIVO 1

#define Z_PENDIENTE 0
#define Z_FINALIZADO 1

#define LEN_CENSISTAS 100
#define LEN_LOCALIDADES 4
#define LEN_ZONAS 100

int main(void) {
	setbuf(stdout, NULL);

	eCensista censistas[LEN_CENSISTAS];
	eZona zonas[LEN_ZONAS];

	int seguir;
	int nextId = 1;
	int nextIdZona = 1;

	eLocalidad localidades[LEN_LOCALIDADES] = {
	                {1000,"Avellaneda"},
	                {1001,"Bernal"},
	                {1002,"Quilmes"},
	                {1003,"Lanus"}
	};

	inicializarCensistas(censistas,LEN_CENSISTAS);
	inicializarZonas(zonas,LEN_ZONAS);

	do {
		switch(menu()) {
			case 1:
				if(buscarLibre(censistas,LEN_CENSISTAS) != -1){
					altaCensista(censistas,LEN_CENSISTAS,&nextId);
				} else {
					printf("La lista esta llena\n");
					system("pause");
				}
				break;
			case 2:
				if(buscarPrimerEspacioLleno(censistas,LEN_CENSISTAS)) {
					if(modificarCensista(censistas,LEN_CENSISTAS)) {
						printf("MODIFICACION realizada con exito\n");
					}
				} else {
					printf("No hay censistas para modificar\n");
					system("pause");
				}
				break;
			case 3:
				if(buscarPrimerEspacioLleno(censistas,LEN_CENSISTAS)) {
					if(bajaCensista(censistas,LEN_CENSISTAS,zonas,LEN_ZONAS)) {
						printf("BAJA realizada con exito\n");
					}
				} else {
					printf("No hay censistas para dar de baja\n");
					system("pause");
				}
				break;
			case 4:
				 if(buscarLibreZona(zonas,LEN_ZONAS) != -1) {
					 cargarZona(zonas,LEN_ZONAS, localidades,LEN_LOCALIDADES,&nextIdZona);
				 } else {
					 printf("No hay mas zonas para cargar\n");
				 }
				break;
			case 5:
				if(buscarPrimerEspacioLlenoZonas(zonas,LEN_CENSISTAS) == 1) {
					asignarZona(zonas,LEN_ZONAS, censistas, LEN_CENSISTAS,localidades,LEN_LOCALIDADES);
				} else {
					printf("No hay zonas para asignar\n");
					system("pause");
				}
				break;
			case 6:
				if(buscarPrimerEspacioLlenoZonas(zonas, LEN_CENSISTAS) != 0) {
					cargaDeDatos(zonas, LEN_ZONAS, censistas, LEN_CENSISTAS, localidades,  LEN_LOCALIDADES);
				} else {
					printf("No hay zonas para cargar datos\n");
					system("pause");
				}
				break;
			case 7:
				mostrarCensistas(censistas,LEN_CENSISTAS);
				break;
			case 8:
				 mostrarZonasConCensista(zonas, LEN_ZONAS, censistas, LEN_CENSISTAS, localidades,  LEN_LOCALIDADES);
				 printf("\n------------------------------------------------------------------------------------\n");
				 mostrarZonasSinCensista(zonas, LEN_ZONAS, censistas, LEN_CENSISTAS, localidades,  LEN_LOCALIDADES);
				break;
			case 9:
				hardcodearCensistas(censistas,LEN_CENSISTAS, 8, &nextId);
				break;
			case 10:
				hardcodearZonas(zonas,LEN_ZONAS ,8, &nextIdZona);
				break;
			case 11:
				seguir = 0;
				break;
			default:
				printf("Opcion invalida\n");
				system("pause");
		}
	}while(seguir);

	printf("Ha salido con exito\n");
	system("pause");

	return EXIT_SUCCESS;
}
