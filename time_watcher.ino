#include "config.h"
#include "sensor_logic.h"
#include "display_logic.h"

// Variables de estado global
int contadorSegundos = 0;
unsigned long lastTick = 0;
unsigned long buttonTimer = 0;
bool actividadEnCurso = false;
bool bloqueadoPorReset = false;

void setup() {
    Serial.begin(115200);
    
    inicializarSensor();
    inicializarDisplay();
    pinMode(RESET_PIN, INPUT_PULLUP);

    Serial.println(F("--- SISTEMA MODULAR TIME WATCHER LISTO ---"));
}

void gestionarReset() {
    if (digitalRead(RESET_PIN) == LOW) {
        if (buttonTimer == 0) buttonTimer = millis();
        
        if (millis() - buttonTimer >= TIEMPO_RESE && !bloqueadoPorReset) {
            contadorSegundos = 0;
            mostrarTexto("RESE");
            Serial.println(F("[EVENTO] Contador reseteado manualmente."));
            bloqueadoPorReset = true;
        }
    } else {
        buttonTimer = 0;
        bloqueadoPorReset = false;
    }
}

void gestionarActividad() {
    int distancia = obtenerDistancia();

    // Si detecta presencia bajo el umbral
    if (distancia > 0 && distancia < DISTANCIA_UMBRAL) {
        if (!actividadEnCurso) {
            Serial.println(F("[LOG] Presencia detectada. Iniciando conteo..."));
            actividadEnCurso = true;
        }

        // Incremento de tiempo cada segundo
        if (millis() - lastTick >= 1000) {
            contadorSegundos++;
            lastTick = millis();
            if (!bloqueadoPorReset) mostrarNumero(contadorSegundos);
        }
    } 
    // Si la presencia desaparece
    else if (actividadEnCurso) {
        Serial.print(F("[LOG] Actividad finalizada. Duración total: "));
        Serial.print(contadorSegundos);
        Serial.println(F(" segundos."));
        
        actividadEnCurso = false;
        // NOTA: Aquí se integrará la función de envío a GCloud
    }
}

void loop() {
    gestionarReset();
    gestionarActividad();
    actualizarDisplay();
}
