#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// --- Pines del Sensor Ultrasónico HC-SR04 ---
const int TRIG_PIN = 12;
const int ECHO_PIN = 14;

// --- Pin del Botón de Reset ---
const int RESET_PIN = 13;

// --- Configuración del Display de 7 Segmentos ---
const byte NUM_DIGITS = 4;
const byte DIGIT_PINS[] = {25, 26, 32, 33};             // D1, D2, D3, D4
const byte SEGMENT_PINS[] = {15, 2, 4, 16, 17, 5, 18, 19}; // A, B, C, D, E, F, G, DP

// --- Parámetros de Operación ---
const int DISTANCIA_UMBRAL = 50; // Distancia en cm para activar el contador
const unsigned long TIEMPO_RESE = 2000; // Tiempo para reset (ms)

#endif
