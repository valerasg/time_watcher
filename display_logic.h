#ifndef DISPLAY_LOGIC_H
#define DISPLAY_LOGIC_H

#include "SevSeg.h"
#include "config.h"

SevSeg sevseg;

// Configuración inicial del display
void inicializarDisplay() {
    bool resistorsOnSegments = true; 
    byte hardwareConfig = COMMON_CATHODE; 
    bool updateWithDelays = false; 
    bool leadingZeros = true;      
    bool disableDecPoint = true;  

    sevseg.begin(hardwareConfig, NUM_DIGITS, (byte*)DIGIT_PINS, (byte*)SEGMENT_PINS, 
                 resistorsOnSegments, updateWithDelays, leadingZeros, disableDecPoint);
    sevseg.setBrightness(90);
}

// Muestra un número entero
void mostrarNumero(int num) {
    sevseg.setNumber(num);
}

// Muestra una palabra corta (máx 4 letras)
void mostrarTexto(const char* texto) {
    sevseg.setChars(texto);
}

// Refresca los LEDs (debe llamarse en el loop)
void actualizarDisplay() {
    sevseg.refreshDisplay();
}

#endif
