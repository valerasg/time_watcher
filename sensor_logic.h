#ifndef SENSOR_LOGIC_H
#define SENSOR_LOGIC_H

#include "config.h"

// Inicializa los pines del sensor
void inicializarSensor() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

// Mide la distancia actual en centímetros
int obtenerDistancia() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duracion = pulseIn(ECHO_PIN, HIGH, 10000); // Timeout de 10ms (aprox 1.7m)
    if (duracion == 0) return 999; // Sin lectura
    
    return duracion * 0.034 / 2;
}

#endif
