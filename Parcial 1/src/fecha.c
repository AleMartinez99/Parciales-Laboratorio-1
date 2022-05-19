#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"
#include "censista.h"

int validarFecha(int dia,int mes,int anio) {

	int fechaCorrecta = 0;

    if (dia <= 31 && dia >= 1 && mes >= 1 && mes <= 12) {

    	switch (mes) {
            case  1:
            case  3:
            case  5:
            case  7:
            case  8:
            case 10:
            case 12:
            	if (dia >= 1 && dia <= 31){
            		fechaCorrecta = 1;
            	}
                break;
            case  4:
            case  6:
            case  9:
            case 11:
            	if (dia >= 1 && dia <= 30) {
            		fechaCorrecta = 1;
            	}
            	break;

            case  2:
            	if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0) {
            		if(dia >= 1 && dia <= 29) {
            			fechaCorrecta = 1;
            		}
            	} else {
            		if(dia >= 1 && dia <= 28){
            			fechaCorrecta = 1;
            		}
            	}
            	break;
        }
    }
    return fechaCorrecta;
}


