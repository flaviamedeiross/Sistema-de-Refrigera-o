# Sistema-de-Refrigeracao

### Descrição do Projeto
- O projeto consiste no desenvolvimento de um sistema que controla a velocidade dos ventiladores de torres de resfriamento industrial, a partir da temperatura, para a gestão do consumo de energia.
- No desenvolvimento do sistema elétrico do protótipo foram utilizados os seguintes materiais:
* Placa Arduino Uno WiFi ATMEGA328P + ESP8266;
* Sensor de Temperatura;
* Sensor de Corrente,
* Ventilador DC 12V.
- Para coletar as informações e exibi-las, criou-se um dashboard na plataforma ThingSpeak.

## Para Instalar o ESP8266 no Arduino IDE:
Instale o Arduino IDE  
Instale as bibliotecas necessárias para a utilização do código:
```sh
OneWire.h
DallasTemperature.h
```
Entre em File > Preferences e coloque o link:
```sh
https://arduino.esp8266.com/stable/package_esp8266com_index.json
```
Vá em em Tools > Board > Boards Manager e pesquise por:
```sh
ESP8266
```
Instale:
```sh
esp8266 by ESP8266 Community
```
## Comandos Para Rodar o Projeto:
Para rodar esse projeto, como essa placa possui dois processadores, é necessário carregar o código do ESP8266 e do Arduino Uno, separadamente.  
Primeiro, para carregar o do ESP8266:  
Entre em Tools > Board e selecione:
```sh
Generic ESP8266 Module
```
Ainda em Tools, vá em Port e selecione a porta correspondente de sua placa, por exemplo:
```sh
COM 4
```
Após isso, siga os passos abaixo:
```sh
1 - Ative os DIP switches (interruptores) 5, 6 e 7 na placa;
2 - Clique no Reset do Arduino;
3 - Clique em Verify para verificar o código e em seguida em Upload para carregá-lo;
4 - Desative o DIP switch 7,
5 - Clique no Reset do Arduino, novamente. 
```
Abra o Serial Monitor para verificar se o WiFi foi conectado com sucesso:
```sh
Ctrl + Shift + M
```
Observação: Lembre-se de colocar o nome e a senha do seu WiFi e a API do seu canal do ThingSpeak  
  
Em seguida, para carregar o código do Arduino Uno:    
Desative os DIP switches 5 e 6 e ative os DIP switches 3 e 4    
Entre em Tools > Board e selecione:  
```sh
Arduino Uno
```
Ainda em Tools, vá em Port e selecione a porta correspondente de sua placa, por exemplo:
```sh
COM 3
```
Observação: Lembre-se de alterar a porta e ativar os DIP switches corretos
```sh
Clique em Verify para verificar o código e em seguida em Upload para carregá-lo
```
Para monitorar os dados, crie um canal na plataforma ThingSpeak:  
```sh
1 - Crie uma conta no ThingSpeak;
2 - Clique em Novo Canal;
3 - Coloque o nome e a descrição do projeto;
4 - Adicione 4 campos: temperatura, corrente, potência e energia,
5 - Salve o Canal. 
```
Por fim, para conectar o Arduino com o ESP8266:  
Desative os DIP switches 3 e 4 e ative os DIP switches 1 e 2  
Abra seu canal no ThingSpeak e observe os dados enviados para os gráficos

### Pessoas Desenvolvedoras: 
- Daniela Akemi Hayashi
- Flávia Cristina Medeiros
- Giovana Salazar Alarcon

