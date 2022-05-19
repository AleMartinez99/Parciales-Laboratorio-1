#ifndef LOCALIDADES_H_
#define LOCALIDADES_H_

typedef struct {

    int id;
    char descripcion[20];

} eLocalidad;


#endif /* LOCALIDADES_H_ */

/// @brief muestra las localidades
///
/// @pre
/// @post
/// @param localidades
/// @param tamL
/// @return 1 para ok, 0 no pudo
int mostrarLocalidades(eLocalidad localidades[], int tamL);
/// @brief valida mediante el id, si la localidad existe
///
/// @pre
/// @post
/// @param idAValidar
/// @param localidades
/// @param tamL
/// @return 1 si existe 0 sino
int validarIdLocalidad(int idAValidar ,eLocalidad localidades[], int tamL);
/// @brief permite con el id, buscar la localidad y cargar su descripcion en una cadena
///
/// @pre
/// @post
/// @param localidades
/// @param tam
/// @param idLocalidad
/// @param descripcionLocalidad
/// @return 1 para ok, 0 sino
int cargarDescripcionLocalidad(eLocalidad localidades[],int tam,int idLocalidad,char descripcionLocalidad[]);
