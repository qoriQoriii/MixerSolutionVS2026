#include <Arduino.h>
#include <NewPing.h>
#include "Config.h"
#include "Sensores.h"

// Variables privadas del módulo
static NewPing sonar1(TRIG_1, ECHO_1, MAX_DISTANCE);
static NewPing sonar2(TRIG_2, ECHO_2, MAX_DISTANCE);
static NewPing sonar3(TRIG_3, ECHO_3, MAX_DISTANCE);
static NewPing sonar4(TRIG_4, ECHO_4, MAX_DISTANCE);

void inicializarSensores() {
    // NewPing no requiere pinMode explícito, se inicializa solo
}

int leerDistancia(int numero) {
    int d = 0;
    switch (numero) {
        case 1: d = sonar1.ping_cm(); break;
        case 2: d = sonar2.ping_cm(); break;
        case 3: d = sonar3.ping_cm(); break;
        case 4: d = sonar4.ping_cm(); break;
        default: return -1;


    }
    return (d == 0) ? -1 : d;



    
}

void leerTodasDistancias(int destino[]) {
    for (int i = 0; i < 4; i++) {
        destino[i] = leerDistancia(i + 1);
    }
}

int [] GenerarReporteTanques() {

    int lecturas[numeroTanques] = {}; 
    leerTodasDistancias(lecturas);

    for (int i = 0; i < numeroTanques ;i++){


        if(lecturas[i] != -1 && lecturas[i] >= LecturaMinimaTanqueDistancia && lecturas[i] <= LecturaMaxTanqueDistancia){

            float range = 1 - ((lecturas[i] - LecturaMinimaTanqueDistancia)/(LecturaMaxTanqueDistancia- LecturaMinimaTanqueDistancia));


            if(0.8 <= range < 1) reporteTanque[i] = "Tanque" + String(i + 1) + " 80-100 %";
            else if(0.5 <= range < 0.8 ) reporteTanque[i] = "Tanque" + String(i + 1) + " 50-80 %";
            else if(0.2 <= range < 0.5 ) reporteTanque[i] = "Tanque" + String(i + 1) + " 20-50 %";
            else if(0.0 <= range < 0.2 ) reporteTanque[i] = "Tanque" + String(i + 1) + " 0-20 %";



        }else reporteTanque[i] = "ERROR LECTURA/RANGO"; //No se realizo la lectura correctamente


    }

    return reporteTanque; //Retorna el arreglo de Strings con el reporte de cada tanque
    


}

