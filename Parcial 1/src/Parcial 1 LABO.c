#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"
#include "censista.h"
#include "localidades.h"
#include "zona.h"

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
					if(bajaCensista(censistas,LEN_CENSISTAS)) {
						printf("BAJA realizada con exito\n");
					}
				} else {
					printf("No hay censistas para dar de baja\n");
					system("pause");
				}
				break;
			case 4:
				cargarZona(zonas,LEN_ZONAS, localidades,LEN_LOCALIDADES,&nextIdZona);
				break;
			case 5:
				asignarZona(zonas,LEN_ZONAS, censistas, LEN_CENSISTAS,localidades,LEN_LOCALIDADES);
				break;
			case 6:
				cargaDeDatos(zonas, LEN_ZONAS, censistas, LEN_CENSISTAS, localidades,  LEN_LOCALIDADES);
				break;
			case 7:
				mostrarCensistas(censistas,LEN_CENSISTAS);
				break;
			case 8:
				 mostrarZonasConCensista(zonas, LEN_ZONAS, censistas, LEN_CENSISTAS, localidades,  LEN_LOCALIDADES);
				 printf("\n----------------------------------------------------------------------------\n");
				 mostrarZonasSinCensista(zonas, LEN_ZONAS, censistas, LEN_CENSISTAS, localidades,  LEN_LOCALIDADES);
				break;
			case 9:
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
