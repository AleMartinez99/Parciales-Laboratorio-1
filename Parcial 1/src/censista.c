#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "miBiblioteca.h"
#include "censista.h"
#include "fecha.h"

#define C_INACTIVO -1
#define C_LIBERADO 0
#define C_ACTIVO 1

int menu() {
	int opcion;
	printf("	**** MENU CENSO 2022 ****\n");
	printf("1 - Carga censista\n");
	printf("2 - Modificar censista\n");
	printf("3 - Baja censista\n");
	printf("4 - Cargar zona\n");
	printf("5 - Asignar zona a censar\n");
	printf("6 - Carga de datos\n");
	printf("7 - Mostrar censistas\n");
	printf("8 - Mostrar zonas\n");
	printf("9 - SALIR\n");
	printf("Ingrese opcion: ");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}

int menuModificacion() {

	int opcion;
	printf(" **** MODIFICACION DE CENCISTA ****\n");
	printf("1 - Modificar NOMBRE\n");
	printf("2 - Modificar APELLIDO\n");
	printf("3 - Modificar EDAD\n");
	printf("4 - Modificar Fecha de Nacimiento\n");
	printf("5 - Modificar Direccion\n");
	printf("INGRESE OPCION: ");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}

int menuModificacionFecha() {

	int opcion;

	printf("1 - Modificar DIA\n");
	printf("2 - Modificar MES\n");
	printf("3 - Modificar ANIO\n");
	printf("INGRESE OPCION: ");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}

int menuModificacionDireccion() {

	int opcion;


	printf("1 - Modificar CALLE\n");
	printf("2 - Modificar ALTURA\n");
	printf("INGRESE OPCION: ");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}
int inicializarCensistas(eCensista censistas[], int len)
{
    int todoOk = 0;

    if(censistas != NULL && len > 0)
    {
        todoOk = 1;

        for(int i = 0; i < len; i++)
        {
        	censistas[i].estado = C_LIBERADO;
        }
    }
    return todoOk;
}

int buscarPrimerEspacioLleno(eCensista censistas[], int len) {

	int ok = 0;

	if(censistas != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(censistas[i].estado != C_LIBERADO)
			{
				ok = 1;
				break;
			}
		}
	}
		return ok;
}

int buscarLibre(eCensista censistas[], int len)
{
    int indice = -1;

    if(censistas != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(censistas[i].estado == C_LIBERADO)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int buscarCencistaIdLiberado(eCensista censistas[], int len, int id)
{
    int indice = -1;

    if(censistas != NULL && len > 0)
    {
        for(int i = 0; i < len ; i++)
        {
            if(censistas[i].id == id && censistas[i].estado == C_LIBERADO)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}


int buscarCencistaId(eCensista censistas[], int len, int id)
{
    int indice = -1;

    if(censistas != NULL && len > 0)
    {
        for(int i = 0; i < len ; i++)
        {
            if(censistas[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int altaCensista(eCensista censistas[], int len, int* pId)
{
    int todoOk = 0;
    int indice;
    int validoFecha;
    eCensista auxCensista;

    if(censistas != NULL && len > 0)
    {
        printf("        **** ALTA CENSISTA ****\n");

        indice = buscarLibre(censistas, len);

        if(indice == -1 )
        {
            printf("No hay lugar\n");
        }
        else
        {
        	auxCensista.id = *pId;
            (*pId)++;

            utnGetCadenaSoloCaracteres(auxCensista.nombre,"Ingrese nombre: ","Error... Ingrese de 3 a 20 caracteres\n","Error... Ingrese solo letras\n", 20);
            miCorregirUnaCadena(auxCensista.nombre);

            utnGetCadenaSoloCaracteres(auxCensista.apellido,"Ingrese apellido: ","Error... Ingrese de 3 a 20 caracteres\n","Error... Ingrese solo letras\n", 20);
            miCorregirUnaCadena(auxCensista.apellido);


            utnGetNumero(&auxCensista.edad,"Ingrese edad: ","Error... Edad invalida(18 a 99)",18,99);

            utnGetNumero(&auxCensista.fechaNacimiento.dia,"Ingrese nuevo dia: ","Error... dia invalido(1 a 31)",1,31);

            utnGetNumero(&auxCensista.fechaNacimiento.mes,"Ingrese nuevo mes: ","Error... mes invalido(1 a 12)",1,12);

            utnGetNumero(&auxCensista.fechaNacimiento.anio,"Ingrese nuevo anio: ","Error... anio invalido(1940 a 2002)",1940,2002);

            validoFecha = validarFecha(auxCensista.fechaNacimiento.dia,auxCensista.fechaNacimiento.mes,auxCensista.fechaNacimiento.anio);

			while(validoFecha != 1) {
				printf("ERROR... Ingrese fecha de nacimiento con este formado dd/mm/aaaa y el anio menor a 2002\n");
				scanf("%d/%d/%d",&auxCensista.fechaNacimiento.dia,&auxCensista.fechaNacimiento.mes,&auxCensista.fechaNacimiento.anio);
				}
			}

            utnGetCadenaSoloCaracteres(auxCensista.direccion.calle,"Ingrese su calle: ","Error... Ingrese de 3 a 50 caracteres\n","Error... Ingrese solo letras\n", 50);
            miCorregirVariasCadenasEnUna(auxCensista.direccion.calle);

            utnGetNumero(&auxCensista.direccion.altura,"Ingrese altura: ","Error... altura invalida(1 a 9999)",1,9999);

            censistas[indice] = auxCensista;
            todoOk = 1;
        }

    return todoOk;
}

int modificarCensista(eCensista censistas[], int len)
{
    int todoOk = 1;
    int indice;
    int id;
    int confirma = 0;
    int opcionModFecha;
    eCensista auxCensista;

    if(censistas != NULL && len > 0)
    {
        printf("          **** MODIFICAR ASOCIADO ****\n\n");
        mostrarCensistas(censistas,len);
        printf("\nIngrese id: ");
        fflush(stdin);
        scanf("%d", &id);

        indice = buscarCencistaIdLiberado(censistas,len,id);

        if(indice == -1)
        {
            printf("El id: %d no esta en el sistema\n",id);
            todoOk = 0;
        }
        else
        {
        	mostrarCensista(censistas[indice]);

            printf("Confirma la modificacion a este cencista?, presione 1 para SI ");
            fflush(stdin);
            scanf("%d", &confirma);

            if(confirma != 1)
            {
                printf("Modificacion cancelada\n");
                todoOk = 0;
            }
            else
            {
                switch(menuModificacion()) {
                	case 1:
                		utnGetCadenaSoloCaracteres(auxCensista.nombre,"Ingrese nuevo nombre: ","Error... Ingrese de 3 a 20 caracteres\n","Error... Ingrese solo letras\n", 20);
                		miCorregirUnaCadena(auxCensista.nombre);
                		strcpy(censistas[indice].nombre,auxCensista.nombre);
                	break;
                	case 2:
                		utnGetCadenaSoloCaracteres(auxCensista.apellido,"Ingrese nuevo apellido: ","Error... Ingrese de 3 a 20 caracteres\n","Error... Ingrese solo letras\n", 20);
                		miCorregirUnaCadena(auxCensista.apellido);
                		strcpy(censistas[indice].apellido,auxCensista.apellido);
                		break;
                	case 3:
                		 utnGetNumero(&auxCensista.edad,"Ingrese nueva edad: ","Error... Edad invalida(18 a 99)",18,99);
                		break;
                	case 4:
                		opcionModFecha = menuModificacionFecha();
                		switch(opcionModFecha) {
                			case 1:
                				utnGetNumero(&auxCensista.fechaNacimiento.dia,"Ingrese nuevo dia: ","Error... dia invalido(1 a 31)",1,31);
                				break;
                			case 2:
                				utnGetNumero(&auxCensista.fechaNacimiento.mes,"Ingrese nuevo mes: ","Error... mes invalido(1 a 12)",1,12);
                				break;
                			case 3:
                				utnGetNumero(&auxCensista.fechaNacimiento.anio,"Ingrese nuevo anio: ","Error... anio invalido(1940 a 2002)",1940,2002);
                				break;
                			default:
                				printf("Opcion invalida, Modificacion cancelada\n");
                				todoOk = 0;
                		}
						while(validarFecha(auxCensista.fechaNacimiento.dia,auxCensista.fechaNacimiento.mes,auxCensista.fechaNacimiento.anio) != 1) {
							printf("ERROR... Ingrese fecha de nacimiento con este formado dd/mm/aaaa y el anio menor a 2002\n");
							scanf("%d/%d/%d",&auxCensista.fechaNacimiento.dia,&auxCensista.fechaNacimiento.mes,&auxCensista.fechaNacimiento.anio);
						}
                		break;
                	case 5:
                		utnGetCadenaSoloCaracteres(auxCensista.direccion.calle,"Ingrese su calle: ","Error... Ingrese de 3 a 50 caracteres\n","Error... Ingrese solo letras\n", 50);
						miCorregirVariasCadenasEnUna(auxCensista.direccion.calle);
						utnGetNumero(&auxCensista.direccion.altura,"Ingrese altura: ","Error... altura invalida(1 a 9999)",1,9999);
                		break;
					default:
						printf("OPCION INVALIDA\n Se cerrara el menu de modificacion\n");
						todoOk = 0;
						system("pause");
				}

            }
        }
    }
    return todoOk;
}

int bajaCensista(eCensista censistas[], int len) {

	int todoOk = 1;
	int indice;
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
		} else {
			if(censistas[indice].estado == C_LIBERADO) {
				mostrarCensista(censistas[indice]);
				printf("Confirma baja? Presione 1 para SI ");
				fflush(stdin);
				scanf("%d", &confirma);

				if(confirma == 1) {
					censistas[indice].estado = C_INACTIVO;
				} else {
					printf("Baja cancelada\n");
					todoOk = 0;
				}
			} else {
				printf("Para dar de baja el censista tiene que estar LIBERADO\n");
				todoOk = 0;
				system("pause");
			}
		}
	}
	return todoOk;
}

void mostrarCensista(eCensista unCensista)
{
	char estado[10];

	if(unCensista.estado == C_LIBERADO) {
		strcpy(estado,"LIBERADO");
	} else if(unCensista.estado == C_INACTIVO) {
		strcpy(estado,"INACTIVO");
	} else {
		strcpy(estado,"ACTIVO");
	}
    printf("%d  %-10s  %-10s  %d  %d/%d/%d  %-10s %d  %-10s\n",
    		unCensista.id,
			unCensista.nombre,
			unCensista.apellido,
			unCensista.edad,
			unCensista.fechaNacimiento.dia,
			unCensista.fechaNacimiento.mes,
			unCensista.fechaNacimiento.anio,
			unCensista.direccion.calle,
			unCensista.direccion.altura,
			estado
           );
}

int mostrarCensistasLiberados(eCensista censistas[], int tam)
{
    int todoOk = 0;
    int flag = 0;

    if(censistas != NULL  && tam > 0)
    {
        todoOk = 1;

        printf("            **** LISTA DE CENCISTAS ****\n");
        printf("-----------------------------------------------------------------\n");
        printf(" ID  NOMBRE  APELLIDO  EDAD  FECHA NACIMIENTO  DIRECCION  ESTADO \n");
        printf("-----------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(censistas[i].estado == C_LIBERADO)
            {
            	mostrarCensista(censistas[i]);
                flag = 1;
            }
        }
        if(!flag)
        {
            printf("No hay cencistas liberados para mostrar\n");
        }
    }
    return todoOk;
}

int mostrarCensistas(eCensista censistas[], int tam)
{
    int todoOk = 0;
    int flag = 0;

    if(censistas != NULL  && tam > 0)
    {
        todoOk = 1;

        printf("            **** LISTA DE CENCISTAS ****\n");
        printf("-----------------------------------------------------------------\n");
        printf(" ID  NOMBRE  APELLIDO  EDAD  FECHA NACIMIENTO  DIRECCION  ESTADO \n");
        printf("-----------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(censistas[i].estado != C_INACTIVO)
            {
            	mostrarCensista(censistas[i]);
                flag = 1;
            }
        }
        if(!flag)
        {
            printf("No hay cencistas para mostrar\n");
        }
    }
    return todoOk;
}

int cargarDescripcionCensistaNombre(eCensista censistas[],int tam,int id,char nombre[]) {

    int todoOk = 0;

    if(censistas != NULL && tam > 0 && nombre != NULL) {
        todoOk = -1;
        for(int i = 0; i < tam; i++) {
            if(censistas[i].id == id){
                strcpy(nombre, censistas[i].nombre);
                break;
                todoOk = 1;
            }
        }
    }
    return todoOk;
}

int cargarDescripcionCensistaApellido(eCensista censistas[],int tam,int id,char apellido[]) {

    int todoOk = 0;

    if(censistas != NULL && tam > 0 && apellido != NULL) {
        todoOk = -1;
        for(int i = 0; i < tam; i++) {
            if(censistas[i].id == id){
                strcpy(apellido, censistas[i].apellido);
                break;
                todoOk = 1;
            }
        }
    }
    return todoOk;
}
