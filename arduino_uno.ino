#include <OneWire.h>
#include <DallasTemperature.h>

const int pinoTemp = 2;        // Pino do sensor DS18B20
const int ventiladorPWM = 9;   // Pino PWM do ventilador para controlar a velocidade
int velocidade = 0;
int offsetSensor = 0;
float tensaoDC=12.000;         // Tensao do ventilador
float corrente;
float potencia;
float energia;
float sensibilidade=0.185;     // Sensibilidade do sensor de corrente de 5A

OneWire oneWire(pinoTemp);
DallasTemperature sensores(&oneWire);

DeviceAddress endereco_temp;          // Endereco do sensor

void setup() {
    Serial.begin(9600);     
    pinMode(ventiladorPWM, OUTPUT); // Saida e o pino PWM do ventilador

    offsetSensor = calibrarOffset();
    Serial.print("Offset lido: ");
    Serial.println(offsetSensor);

    sensores.begin();
}

int calibrarOffset() {
    long soma = 0;
    for (int i = 0; i < 1000; i++) {
        soma += analogRead(A0);
        delay(1);
    }
    return soma / 1000;
}

void loop() {
    sensores.requestTemperatures();    // Solicita a temperatura do sensor
    if (!sensores.getAddress(endereco_temp, 0)) {
        Serial.println("SENSOR NAO CONECTADO");
        analogWrite(ventiladorPWM, 0); // Caso o sensor nao esteja conectado, desliga o ventilador
        delay(15000);
    } else {
        float temperatura = sensores.getTempC(endereco_temp);  // Le a temperatura

        // Ajusta a velocidade do ventilador conforme a temperatura pelo sinal PWM, variando de 0 a 255
        if (temperatura <= 30) { 
            velocidade = map(temperatura, 0, 30, 50, 120);  
            velocidade = constrain(velocidade, 50, 120);  
        } else if (temperatura > 30) { 
            velocidade = map(temperatura, 30, 100, 200, 255);  
            velocidade = constrain(velocidade, 200, 255);  
        } else {
            velocidade = 0;
        } 

        analogWrite(ventiladorPWM, velocidade);

        corrente = calculaCorrente(filtroDaMedia());
        potencia = abs(corrente * tensaoDC);
        energia = (potencia * 3600.0); // E = Potencia x Tempo

        // Envia dados via Serial para o ESP8266
        String data = String(temperatura, 1) + "," + String(corrente, 2) + "," + String(potencia, 2) + "," + String(energia, 2);
        Serial.println(data);

        delay(15000); // O ThingSpeak atualiza de 15 em 15 segundos
    }
}

float calculaCorrente(int sinalSensor){
    return (float) (sinalSensor - offsetSensor) * (5.000) / (1023.000 * sensibilidade);
}

int filtroDaMedia(){ // Calcula a media de 1000 valores lidos de corrente
    long somaDasCorrentes = 0, mediaDasCorrentes;
    for (int i = 0; i < 1000; i++) {
        somaDasCorrentes += analogRead(A0);
        delay(1);
    }
    mediaDasCorrentes = somaDasCorrentes / 1000;
    return mediaDasCorrentes;
}
