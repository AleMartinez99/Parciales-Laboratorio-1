#include "censista.h"
#include "zona.h"

#ifndef DATAWAREHOUSE_H_
#define DATAWAREHOUSE_H_



#endif /* DATAWAREHOUSE_H_ */

/// @brief permite el hardcodeo de hasta 10 censista
///
/// @pre
/// @post
/// @param censistas
/// @param len
/// @param cantidad
/// @param pId
/// @return 1 si pudo, 0 sino
int hardcodearCensistas(eCensista censistas[], int len, int cantidad, int* pId);
/// @brief permite el hardcodeo de hasta 10 zonas
///
/// @pre
/// @post
/// @param zonas
/// @param len
/// @param cantidad
/// @param pId
/// @return 1 si pudo, 0 sino
int hardcodearZonas(eZona zonas[], int len, int cantidad, int* pId);
