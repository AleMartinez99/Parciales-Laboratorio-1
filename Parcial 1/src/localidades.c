#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "localidades.h"

int mostrarLocalidades(eLocalidad localidades[], int tam) {
     int todoOk = 0;

     if(localidades != NULL && tam > 0) {
        printf("  **** Localidades ****\n");
        printf(" Descripcion    ID\n");
        for(int i = 0; i < tam;i++){
            printf(" %-10s    %d\n", localidades[i].descripcion, localidades[i].id);
        }

        todoOk = 1;
    }
    return todoOk;
}

int validarIdLocalidad(int idAValidar ,eLocalidad localidades[], int tamL) {

     int todoOk = 0;

     if(localidades != NULL && tamL > 0) {

        for(int i = 0; i < tamL;i++) {
            if(idAValidar == localidades[i].id) {
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int cargarDescripcionLocalidad(eLocalidad localidades[],int tam,int idLocalidad,char descripcionLocalidad[]) {

    int todoOk = 0;

    if(localidades != NULL && tam > 0 && descripcionLocalidad != NULL) {
        todoOk = -1;
        for(int i = 0; i < tam; i++) {
            if(localidades[i].id == idLocalidad){
                strcpy(descripcionLocalidad, localidades[i].descripcion);
                break;
                todoOk = 1;
            }
        }
    }
    return todoOk;
}
