# Sistema-de-Refrigeracao

### Descrição do Projeto
- O projeto consiste no desenvolvimento de um sistema que controla a velocidade dos ventiladores de torres de resfriamento industrial a partir da temperatura para a gestao do consumo de energia.
- No desenvolvimento do prototipo foram utilizados os seguintes materiais:
- Placa Arduino Uno ATMEGA328 + ESP8266;
- Sensor de Temperatura;
- Sensor de Corrente,
- Ventilador DC 12V.

## Para instalar o ESP8266 no Arduino iDE:
Instale o Arduino IDE  
Instale as bibliotecas necessarios para a utilizacao do codigo:
```sh
OneWire.h
DallasTemperature.h
```
Entre em File > Preferences e coloque o link:
```sh
https://arduino.esp8266.com/stable/package_esp8266com_index.json
```
Va em em Tools > Board > Boards Manager e pesquise por:
```sh
ESP8266
```
instale:
```sh
esp8266 by ESP8266 Community
```
## Comandos Para Rodar o Projeto:
Para rodar esse projeto e necessario carregar o codigo do ESP8266 e do Arduino Uno, separadamente.
Primeiro, para carregar no ESP8266:
Entre em Tools > Board e selecione:
```sh
Generic ESP8266 Module
```
Ainda em Tools, va em Port e selecione a porta correspondente de sua placa, por exemplo:
```sh
COM 4
```
Apos isso siga os passos abaixo:
```sh
1 - Ative os pinos 5, 6 e 7 na placa;
2 - Clique no Reset do Arduino;
3 - Clique em Verify para verificar o codigo e em seguida em Upload para carrega-lo;
4 - Desative o pino 7,
5 - Clique no Reset do Arduino novamente. 
```
Abra o Serial Monitor para verificar se o WiFi foi conectado com sucesso, para abrir de:
```sh
Ctrl + Shift + M
```
Em seguida, para carregar no Arduino Uno:
Desative os pinos 5 e 6 e ative os pinos 3 e 4
Entre em Tools > Board e selecione:
```sh
Arduino Uno
```
Ainda em Tools, va em Port e selecione a porta correspondente de sua placa, por exemplo:
```sh
COM 3
```
Observacao: Lembre-se de alterar a porta e ativar os pinos corretos
```sh
Clique em Verify para verificar o codigo e em seguida em Upload para carrega-lo;
```
Por fim, para conectar os dois:
Desative os pinos 3 e 4 e ative os pinos 1 e 2
Abra seu canal no ThingSpeak e observe os dados enviados pelos graficos

### Pessoas Desenvolvedoras: 
- Daniela Akemi Hayashi
- Flávia Cristina Medeiros
- Giovana Salazar Alarcon

