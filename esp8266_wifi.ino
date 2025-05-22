#include <ESP8266WiFi.h>

const char* ssid = "";       // Coloque o nome do seu WiFi
const char* password = "";   // Colque a senha do seu WiFi
const char* server = "api.thingspeak.com";
const String apiKey = "";   // Coloque a api do seu canal do ThingSpeak

WiFiClient client;

void setup() {
    Serial.begin(9600);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Conectando ao WiFi...");
    }
    Serial.println("WiFi conectado");
}

void loop() {
    if (Serial.available()) {
        String data = Serial.readStringUntil('\n');
        data.trim();

        String temperatura = extractField(data, 0);
        String corrente = extractField(data, 1);
        String potencia = extractField(data, 2);
        String energia = extractField(data, 3);

        if (client.connect(server, 80)) {
            String url = "/update?api_key=" + apiKey +
                         "&field1=" + temperatura +
                         "&field2=" + corrente +
                         "&field3=" + potencia +
                         "&field4=" + energia;

            client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                         "Host: " + server + "\r\n" +
                         "Connection: close\r\n\r\n");
            client.stop();
            Serial.println("Dados enviados ao ThingSpeak:");
            Serial.println(url);
        } else {
            Serial.println("Falha na conexão com ThingSpeak");
        }

    }

    delay(15000);  // O ThingSpeak atualiza de 15 em 15 segundos
}

String extractField(String data, int field) {
    int startIndex = 0;
    int endIndex = -1;

    for (int i = 0; i <= field; i++) {
        startIndex = endIndex + 1;
        endIndex = data.indexOf(',', startIndex);

        if (endIndex == -1) {
            return data.substring(startIndex);
        }
    }
    return data.substring(startIndex, endIndex);
}
