#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h> 
#include <Adafruit_NeoPixel.h>

ESP8266WiFiMulti wifiMulti;

int state = 1;

#define PIN D2
#define NUM_PINS 24

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PINS, PIN, NEO_GRB + NEO_KHZ800);
 
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  Serial.println("Ligando os leds");

  //seta cor para ciano e brilho ao iniciar
  strip.setBrightness(10);
  colorWipe(strip.Color(0, 139, 139), 30); //cor, tempo de duracao

  wifiMulti.addAP("ssid", "password");
  wifiMulti.addAP("ssid", "password");
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
 
  Serial.print("Connecting");
  int i = 0;
  while (wifiMulti.run() != WL_CONNECTED) {
    delay(1000);
    Serial.print('.');
  }
  
  Serial.println('\n');
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP()); 
 
  // Start the server
  server.begin();
  Serial.println("Server started");; 

  //seta cor para laranja depois de conectado
  colorWipe(strip.Color(255, 165, 0), 30); //cor, tempo de duracao
 
}
 
void loop() {
  
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while( ! client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
  if (request.indexOf("/alternar") != -1)  {
    Serial.println("Alternando estado");
    //caso estado for ligado, desliga
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println("Access-Control-Allow-Origin: *");
    client.println("");
    
   if(state == 1) {
      Serial.println("Desligando...");
      strip.setBrightness(0);
      colorWipe(strip.Color(0, 0, 0), 30); //cor, tempo de duracao
      state = 0;
      client.print("{\"status\": {\"led_is\": \"off\"}}");
    }
    //caso estado for desligado, liga
    else {
      Serial.println("Ligando...");
      strip.setBrightness(10);
      colorWipe(strip.Color(255, 255, 255), 30); //cor, tempo de duracao
      state = 1;
      client.print("{\"status\": {\"led_is\": \"on\"}}");
    }
  }
  else if (request.indexOf("/laranja") != -1)  {
    Serial.println("Cor laranja selecionada");
    strip.setBrightness(10);
    colorWipe(strip.Color(255, 165, 0), 30); //cor, tempo de duracao
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println("Access-Control-Allow-Origin: *");
    client.println("");
    client.print("{\"status\": {\"led_is\": \"on\", \"color_is\": \"laranja\"}}");
    state = 1;
  }
  else if (request.indexOf("/azul") != -1)  {
    Serial.println("Cor azul selecionada");
    strip.setBrightness(10);
    colorWipe(strip.Color(0, 0, 128), 30); //cor, tempo de duracao
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println("Access-Control-Allow-Origin: *");
    client.println("");
    client.print("{\"status\": {\"led_is\": \"on\", \"color_is\": \"azul\"}}");
    state = 1;
  }
  else if (request.indexOf("/violeta") != -1)  {
    Serial.println("Cor violeta selecionada");
    strip.setBrightness(10);
    colorWipe(strip.Color(138, 43, 226), 30); //cor, tempo de duracao;
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println("Access-Control-Allow-Origin: *");
    client.println("");
    client.print("{\"status\": {\"led_is\": \"on\", \"color_is\": \"violeta\"}}");
    state = 1;
  }
  else if (request.indexOf("/amarelo") != -1)  {
    Serial.println("Cor amarelo selecionada");
    strip.setBrightness(10);
    colorWipe(strip.Color(255, 255, 0), 30); //cor, tempo de duracao
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println("Access-Control-Allow-Origin: *");
    client.println("");
    client.print("{\"status\": {\"led_is\": \"on\", \"color_is\": \"amarelo\"}}");
    state = 1;
  }
  else if (request.indexOf("/rosa") != -1)  {
    Serial.println("Cor rosa selecionada");
    strip.setBrightness(10);
    colorWipe(strip.Color(255, 192, 203), 30); //cor, tempo de duracao
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println("Access-Control-Allow-Origin: *");
    client.println("");
    client.print("{\"status\": {\"led_is\": \"on\", \"color_is\": \"rosa\"}}");
    state = 1;
  }
  else if (request.indexOf("/roxo") != -1)  {
    Serial.println("Cor roxo selecionada");
    strip.setBrightness(10);
    colorWipe(strip.Color(75, 0, 130), 30); //cor, tempo de duracao
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println("Access-Control-Allow-Origin: *");
    client.println("");
    client.print("{\"status\": {\"led_is\": \"on\", \"color_is\": \"roxo\"}}");
    state = 1;
  }
  else if (request.indexOf("/ciano") != -1)  {
    Serial.println("Cor ciano selecionada");
    strip.setBrightness(10);
    colorWipe(strip.Color(0, 139, 139), 30); //cor, tempo de duracao
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println("Access-Control-Allow-Origin: *");
    client.println("");
    client.print("{\"status\": {\"led_is\": \"on\", \"color_is\": \"ciano\"}}");
    state = 1;
  }
  else if (request.indexOf("/azul_meianoite") != -1)  {
    Serial.println("Cor azul12 selecionada");
    strip.setBrightness(10);
    colorWipe(strip.Color(25, 25, 112), 30); //cor, tempo de duracao
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println("Access-Control-Allow-Origin: *");
    client.println("");
    client.print("{\"status\": {\"led_is\": \"on\", \"color_is\": \"azul_meianoite\"}}");
    state = 1;
  }
  else if (request.indexOf("/cereja") != -1)  {
    Serial.println("Cor cereja selecionada");
    strip.setBrightness(10);
    colorWipe(strip.Color(222, 49, 99), 30); //cor, tempo de duracao
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println("Access-Control-Allow-Origin: *");
    client.println("");
    client.print("{\"status\": {\"led_is\": \"on\", \"color_is\": \"cereja\"}}");
    state = 1;
  }

  else if (request.indexOf("/checar") != -1)  {
    // Return the response
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println("Access-Control-Allow-Origin: *");
    client.println("");
    if(state == 1) {
      client.print("{\"status\": {\"led_is\": \"on\"}}");
    } else {
      client.print("{\"status\": {\"led_is\": \"off\"}}");
    }
  }
  
  else {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<h1 style=\"text-weight: bold\"><center>Luminer</center></h1>");
    client.println("<p><center>This is a server for control a Adafruit Neopixel with NodeMCU.</center></p>");
    client.println("</html>");
    delay(1);
    Serial.println("Client disconnected");
    Serial.println("");
  }
 
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbow(uint8_t velocity) {
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(velocity);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

