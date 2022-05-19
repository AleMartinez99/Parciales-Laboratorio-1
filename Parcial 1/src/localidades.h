#ifndef LOCALIDADES_H_
#define LOCALIDADES_H_

typedef struct {

    int id;
    char descripcion[20];

} eLocalidad;


#endif /* LOCALIDADES_H_ */

int mostrarLocalidades(eLocalidad localidades[], int tamL);
int validarIdLocalidad(int idAValidar ,eLocalidad localidades[], int tamL);
int cargarDescripcionLocalidad(eLocalidad localidades[],int tam,int idLocalidad,char descripcionLocalidad[]);
