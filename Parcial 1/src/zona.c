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

#define C_INACTIVO -1
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

int buscarPrimerEspacioLlenoZonas(eZona zonas[], int len) {

	int ok = 0;

	if(zonas != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			if(zonas[i].isEmpty == 0) {
				ok = 1;
				break;
			}
		}
	}
		return ok;
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

int buscarZonaIdCensista(eZona zonas[], int len, int id) {

	int indice = -1;

	    if(zonas != NULL && len > 0)
	    {
	        for(int i = 0; i < len ; i++)
	        {
	            if(zonas[i].idCensista == id)
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
			system("pause");
		} else {
			mostrarCensistasLiberados(censistas,lenCensista);
			printf("Ingrese ID del censista para asignar: ");
			fflush(stdin);
			scanf("%d", &idCensista);
			indiceCensista = buscarCencistaIdLiberado(censistas,lenCensista, idCensista);

			if(indiceCensista == -1) {
				printf("No hay un censista con esa ID\n");
				system("pause");
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
			system("pause");
		} else if (!zonas[indiceZona].tieneCensistaAsignado) {
			printf("No se le puede dar finalizada ya que ningun censista paso por esa zona\n");
			system("pause");
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
            if(zonas[i].isEmpty == 0 && zonas[i].tieneCensistaAsignado)
            {
            	mostrarZona(zonas[i],censistas,lenCensista,localidades, lenLocalidades);
                flag = 1;
            }
        }
        if(!flag)
        {
            printf("No hay zonas para mostrar\n");
            system("pause");
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
            if(zonas[i].isEmpty == 0 && zonas[i].tieneCensistaAsignado == 1)
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

        printf("   **** LISTA DE ZONAS SIN CENSISTA ****\n");
        printf("---------------------------------------------------------------------------------------\n");
        printf(" ID | LOCALIDAD  |                   CALLES               	| ESTADO \n");
        printf("-------------------------------------------------------------------------------------------\n");
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
            system("pause");
        }
    }
    return todoOk;
}

void mostrarZonaSinCensista(eZona unaZona,eCensista censistas[],int lenCensista,eLocalidad localidades[], int lenLocalidades)
{
	char estado[12];
	char descLocalidad[20];

	cargarDescripcionLocalidad(localidades,lenLocalidades,unaZona.idLocalidad,descLocalidad);


	if(unaZona.estado == Z_PENDIENTE) {
		strcpy(estado,"PENDIENTE");
	} else  {
		strcpy(estado,"FINALIZADA");
	}

		printf(" %d    %-15s     %s,%s,%s,%s         %s\n",
				unaZona.id,
				descLocalidad,
				unaZona.calles[0],
				unaZona.calles[1],
				unaZona.calles[2],
				unaZona.calles[3],
				estado
			   );

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
    printf("%d  %s,%s   %s    %s,%s,%s,%s   %s\n",
    		unaZona.id,
			nombre,
			apellido,
			descLocalidad,
    		unaZona.calles[0],
			unaZona.calles[1],
			unaZona.calles[2],
			unaZona.calles[3],
			estado
           );

}


int bajaCensista(eCensista censistas[], int len,eZona zonas[], int lenZonas) {

	int todoOk = 1;
	int indice;
	int indiceZona;
	int id;
	int confirma = 0;

	if(censistas != NULL && len > 0)    {

		printf("     **** BAJA CENSISTA ****\n\n");
		mostrarCensistas(censistas,len);
		printf("\nIngrese id del censista a dar de baja: ");
		fflush(stdin);
		scanf("%d", &id);

		indice = buscarCencistaId(censistas,len,id);

		if(indice == -1) {
			printf("El id: %d no esta en el sistema\n",id);
			todoOk = 0;
			system("pause");
		} else {
				mostrarCensista(censistas[indice]);
				printf("Confirma baja? Presione 1 para SI: ");
				fflush(stdin);
				scanf("%d", &confirma);
			if(censistas[indice].estado == C_ACTIVO) {
				if(confirma == 1) {
					censistas[indice].estado = C_INACTIVO;
					indiceZona = buscarZonaIdCensista(zonas,len, id);
					zonas[indiceZona].tieneCensistaAsignado = 0;
				} else {
					printf("Baja cancelada\n");
					todoOk = 0;
					system("pause");
				}
			} else {
				if(confirma == 1) {
					censistas[indice].isEmpty = 1;
				} else {
					printf("Baja cancelada\n");
					todoOk = 0;
					system("pause");
				}
			}
		}
	}
	return todoOk;
}

int mostrarCensistasLoc(eCensista censistas[], int len,eZona zonas[], int lenZonas)
{
    int todoOk = 0;
    int flag = 0;

    if(censistas != NULL  && len > 0)
    {
        todoOk = 1;

        printf("            **** LISTA DE CENCISTAS ****\n");
        printf("-----------------------------------------------------------------\n");
        printf(" ID  NOMBRE  APELLIDO  EDAD  FECHA NACIMIENTO  DIRECCION  ESTADO \n");
        printf("-----------------------------------------------------------------\n");
        for(int i = 0; i < len; i++)
        {
            if(censistas[i].isEmpty == 0)
            {
            	for(int j = 0;j<lenZonas;j++) {
            		if(zonas[j].idLocalidad == 1000 ||zonas[j].idLocalidad == 1003)
            		mostrarCensista(censistas[i]);
            		flag = 1;
            	}
            }
        }
        if(!flag)
        {
            printf("No hay cencistas para mostrar\n");
            system("pause");
        }
    }
    return todoOk;
}
