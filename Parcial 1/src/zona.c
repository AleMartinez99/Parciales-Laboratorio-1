#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "miBiblioteca.h"
#include "censista.h"
#include "zona.h"
#include "localidades.h"

#define Z_PENDIENTE 0
#define Z_FINALIZADO 1

#define C_LIBERADO 0
#define C_ACTIVO 1

int inicializarZonas(eZona zonas[], int lenZonas)
{
    int todoOk = 0;

    if(zonas != NULL && lenZonas > 0)
    {
        todoOk = 1;

        for(int i = 0; i < lenZonas; i++)
        {
        	zonas[i].estado = Z_PENDIENTE;
        	zonas[i].tieneCensistaAsignado = 0;
        	zonas[i].isEmpty = 1;
        }
    }
    return todoOk;
}

int buscarLibreZona(eZona zonas[], int lenZonas)
{
    int indice = -1;

    if(zonas != NULL && lenZonas > 0)
    {
        for(int i = 0; i < lenZonas; i++)
        {
            if(zonas[i].estado == Z_PENDIENTE)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int buscarZonaId(eZona zonas[], int len, int id)
{
    int indice = -1;

    if(zonas != NULL && len > 0)
    {
        for(int i = 0; i < len ; i++)
        {
            if(zonas[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int cargarZona(eZona zonas[],int lenZonas,eLocalidad localidades[], int lenLocalidades,int* id) {

	int ok = 0;
	int indice;
	eZona auxZona;

	if(zonas != NULL && lenZonas > 0 && localidades != NULL && lenLocalidades > 0) {

		printf("   **** CARGAR ZONA ****\n\n");

		indice = buscarLibreZona(zonas,lenZonas);

		if(indice != -1) {

			auxZona.id = *id;
			(*id)++;

			mostrarLocalidades(localidades,lenLocalidades);
			printf("Ingrese ID de la localidad que corresponda: ");
			fflush(stdin);
			scanf("%d", &auxZona.idLocalidad);

			while(!validarIdLocalidad(auxZona.idLocalidad,localidades,lenLocalidades)){
				printf("ID INVALIDA, ingresela nuevamente: ");
				fflush(stdin);
				scanf("%d", &auxZona.idLocalidad);
			}

			for(int i = 0;i<4;i++) {
				printf("Ingrese calle %d", i+1);
				fflush(stdin);
				gets(auxZona.calles[i]);
				miCorregirVariasCadenasEnUna(auxZona.calles[i]);
			}
			auxZona.estado = Z_PENDIENTE;
			auxZona.isEmpty = 0;

			zonas[indice] = auxZona;

		} else {
			printf("No hay mas zonas disponibles\n");
			system("pause");
		}
	}
	return ok;
}

int asignarZona(eZona zonas[],int lenZonas,eCensista censistas[],int lenCensista,eLocalidad localidades[], int lenLocalidades) {

	int ok = 0;
	int idZona;
	int idCensista;
	int indiceZona;
	int indiceCensista;

	if(zonas != NULL && lenZonas > 0) {

		printf("   **** ASIGNAR ZONA A CENSISTA ****\n\n");

		mostrarZonasSinCensista(zonas,lenZonas,censistas,lenCensista,localidades,lenLocalidades);
		printf("Ingrese ID de la zona que a asignar: ");
		fflush(stdin);
		scanf("%d", &idZona);
		indiceZona = buscarZonaId(zonas,lenZonas,idZona);

		if(indiceZona == -1) {
			printf("No hay una zona con esa ID\n");
		} else {
			mostrarCensistasLiberados(censistas,lenCensista);
			printf("Ingrese ID del censista para asignarle la zona con id: %d", idZona);
			fflush(stdin);
			scanf("%d", &idCensista);
			indiceCensista = buscarCencistaIdLiberado(censistas,lenCensista, idCensista);

			if(indiceCensista == -1) {
				printf("No hay un censista con esa ID\n");
			} else {
				zonas[indiceZona].idCensista = idCensista;
				zonas[indiceZona].tieneCensistaAsignado = 1;
				censistas[indiceCensista].estado = C_ACTIVO;
				ok = 1;
			}
		}
	}
	return ok;
}

int cargaDeDatos(eZona zonas[],int lenZonas,eCensista censistas[],int lenCensista,eLocalidad localidades[], int lenLocalidades) {

	int ok = 0;
	int idZona;
	int indiceZona;
	int indiceCensista;

	if(zonas != NULL && lenZonas > 0) {

		printf("   **** CARGA DE DATOS ****\n\n");

		mostrarZonas(zonas,lenZonas, censistas, lenCensista, localidades,lenLocalidades);
		printf("Ingrese ID de la zona que a finalizar: ");
		fflush(stdin);
		scanf("%d", &idZona);

		indiceZona = buscarZonaId(zonas,lenZonas,idZona);

		if(indiceZona == -1) {
			printf("No existe una zona con esa ID\n");
		} else if (!zonas[indiceZona].tieneCensistaAsignado) {
			printf("No se le puede dar finalizada ya que ningun censista paso por esa zona\n");
		} else {

			utnGetNumeroSoloMinimo(&zonas[indiceZona].cantCensadosSitu,"Ingrese cantidad de censados IN SITU: ","Ingrese un numero mayor o igual a 0: ",0);
			utnGetNumeroSoloMinimo(&zonas[indiceZona].cantCensadosVirtual,"Ingrese cantidad de censados virtual: ","Ingrese un numero mayor o igual a 0: ",0);
			utnGetNumeroSoloMinimo(&zonas[indiceZona].cantAusentes,"Ingrese cantidad de censados ausentes: ","Ingrese un numero mayor o igual a 0: ",0);
			zonas[indiceZona].estado = Z_FINALIZADO;

			indiceCensista = buscarCencistaId(censistas,lenCensista,zonas[indiceZona].idCensista);
			censistas[indiceCensista].estado = C_LIBERADO;
			ok = 1;
		}
	}

	return ok;
}

int mostrarZonas(eZona zonas[],int lenZonas,eCensista censistas[],int lenCensista,eLocalidad localidades[], int lenLocalidades)
{
    int todoOk = 0;
    int flag = 0;

    if(zonas != NULL  && lenZonas > 0)
    {
        todoOk = 1;

        printf("          		**** LISTA DE ZONAS ****\n");
        printf("------------------------------------------------------------\n");
        printf(" ID | CENSISTA RESPONSABLE | LOCALIDAD  | CALLES | ESTADO \n");
        printf("------------------------------------------------------------\n");
        for(int i = 0; i < lenZonas; i++)
        {
            if(zonas[i].isEmpty == 0)
            {
            	mostrarZona(zonas[i],censistas,lenCensista,localidades, lenLocalidades);
                flag = 1;
            }
        }
        if(!flag)
        {
            printf("No hay zonas para mostrar\n");
        }
    }
    return todoOk;
}

int mostrarZonasConCensista(eZona zonas[],int lenZonas,eCensista censistas[],int lenCensista,eLocalidad localidades[], int lenLocalidades)
{
    int todoOk = 0;
    int flag = 0;

    if(zonas != NULL  && lenZonas > 0)
    {
        todoOk = 1;

        printf("         **** LISTA DE ZONAS CON CENSISTA****\n");
        printf("------------------------------------------------------------\n");
        printf(" ID | CENSISTA RESPONSABLE | LOCALIDAD  | CALLES | ESTADO \n");
        printf("------------------------------------------------------------\n");
        for(int i = 0; i < lenZonas; i++)
        {
            if(zonas[i].isEmpty == 0 && zonas[i].tieneCensistaAsignado)
            {
            	mostrarZona(zonas[i],censistas,lenCensista,localidades, lenLocalidades);
                flag = 1;
            }
        }
        if(!flag)
        {
            printf("No hay zonas para mostrar\n");
        }
    }
    return todoOk;
}

int mostrarZonasSinCensista(eZona zonas[],int lenZonas,eCensista censistas[],int lenCensista,eLocalidad localidades[], int lenLocalidades)
{
    int todoOk = 0;
    int flag = 0;

    if(zonas != NULL  && lenZonas > 0)
    {
        todoOk = 1;

        printf(" **** LISTA DE ZONAS SIN CENSISTA****\n");
        printf("---------------------------------------------\n");
        printf(" ID | LOCALIDAD  | CALLES | ESTADO \n");
        printf("---------------------------------------------\n");
        for(int i = 0; i < lenZonas; i++)
        {
            if(zonas[i].isEmpty == 0 && zonas[i].tieneCensistaAsignado == 0)
            {
            	mostrarZonaSinCensista(zonas[i],censistas,lenCensista,localidades, lenLocalidades);
                flag = 1;
            }
        }
        if(!flag)
        {
            printf("No hay zonas para mostrar\n");
        }
    }
    return todoOk;
}

void mostrarZonaSinCensista(eZona unaZona,eCensista censistas[],int lenCensista,eLocalidad localidades[], int lenLocalidades)
{
	char estado[12];
	char descLocalidad[15];

	cargarDescripcionLocalidad(localidades,lenLocalidades,unaZona.idLocalidad,descLocalidad);

	if(unaZona.estado == Z_PENDIENTE) {
		strcpy(estado,"PENDIENTE");
	} else  {
		strcpy(estado,"FINALIZADA");
	}
    printf("%d   %s    %s   %s\n",
    		unaZona.id,
			descLocalidad,
    		unaZona.calles[0],
			estado
           );
    for(int i = 1;i < 4;i++){
    	printf("           %s\n",unaZona.calles[i]);
    }
}

void mostrarZona(eZona unaZona,eCensista censistas[],int lenCensista,eLocalidad localidades[], int lenLocalidades)
{
	char estado[12];
	char descLocalidad[15];
	char nombre[20];
	char apellido[20];

	cargarDescripcionLocalidad(localidades,lenLocalidades,unaZona.idLocalidad,descLocalidad);
	cargarDescripcionCensistaNombre(censistas,lenCensista,unaZona.idCensista, nombre);
	cargarDescripcionCensistaApellido(censistas,lenCensista,unaZona.idCensista,apellido);

	if(unaZona.estado == Z_PENDIENTE) {
		strcpy(estado,"PENDIENTE");
	} else  {
		strcpy(estado,"FINALIZADA");
	}
    printf("%d  %s,%s   %s    %s   %s\n",
    		unaZona.id,
			nombre,
			apellido,
			descLocalidad,
    		unaZona.calles[0],
			estado
           );
    for(int i = 1;i < 4;i++){
    	printf("                  %s   \n",unaZona.calles[i]);
    }
}


