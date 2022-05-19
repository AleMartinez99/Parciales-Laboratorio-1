#ifndef FECHA_H_
#define FECHA_H_

typedef struct {

	int dia;
	int mes;
	int anio;

}eFecha;

#endif /* FECHA_H_ */

/// @brief permite validar una fecha
///
/// @pre
/// @post
/// @param dia
/// @param mes
/// @param anio
/// @return 1 si esta ok, 0 para no
int validarFecha(int dia,int mes,int anio);

