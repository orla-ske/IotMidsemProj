//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#include <Ultrasonic.h>
#include <HTTPClient.h> 
#include <WiFiClient.h>
#include <WebServer.h> 
#include <ESPmDNS.h>
#include "html.h"

#define USE_SERIAL Serial
#define LEDRED (4)
#define RelayPin (13)
#define uS_TO_S_FACTOR 1000000ULL  /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP  5        /* Time ESP32 will go to sleep (in seconds) */
RTC_DATA_ATTR int bootCount = 0;
WiFiMulti wifiMulti;
LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
Ultrasonic ultrasonic(14,27); // (Trig PIN,Echo PIN)
WebServer server(80);
char ssid[] = "Gerald";
char password[] = "Face12345"; 
IPAddress local_ip(192,168,2,1); 
IPAddress gateway(192,168,2,1); 
IPAddress subnet(255,255,255,0); 
int value = 1; 
bool motorState = true; 



void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Testing...");
  pinMode(LEDRED, OUTPUT);
  pinMode(RelayPin, OUTPUT);
  digitalWrite(LEDRED, HIGH);

  USE_SERIAL.begin(115200);
  WiFi.mode(WIFI_STA);
  delay(1000);
 
  WiFi.begin(ssid, password);
  server.on("/", base);
  server.on("/Manurl",manSwitchFunct);
  server.on("/Autourl",autoSwitchFunct);
  server.on("/starturl",motorStart);
  server.on("/stopurl",motorStop);
  server.onNotFound(handleNotFound);

  USE_SERIAL.println();
  USE_SERIAL.println();
  USE_SERIAL.println();

  for(uint8_t t = 4; t > 0; t--) {

    USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
    USE_SERIAL.flush();
    delay(1000);

  }

  wifiMulti.addAP("DUFIE-HOSTEL", "Duf1e@9723");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

}

void loop()
{
  int waterLev = 100 - ultrasonic.Ranging(CM);
  lcd.clear();
  lcd.setCursor(0,0);   //Set cursor to character 2 on line 0
  lcd.print("Water Level(cm)");
  lcd.setCursor(5, 1);
  lcd.print(waterLev); // CM or INC
  delay(10);

if(value == 0){
  if(motorState = true){
    digitalWrite(RelayPin, HIGH);

  }else{
    digitalWrite(RelayPin, LOW);    
  }

}else if(value == 1){
  if(ultrasonic.Ranging(CM) <= 98){

    digitalWrite(LEDRED, HIGH);
    digitalWrite(RelayPin, HIGH);

  }else{
      digitalWrite(LEDRED, LOW);
      digitalWrite(RelayPin, LOW);
  }
}
  

   if((wifiMulti.run() == WL_CONNECTED)) {

        HTTPClient http;

        USE_SERIAL.print("[HTTP] begin...\n");
        // configure traged server and url
        //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS
        http.begin("http://192.168.100.169/IOT/retrieve.php?waterLevel="+String(waterLev)+"&tankID=1"); //HTTP

        USE_SERIAL.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        // httpCode will be negative on error
        if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled
            USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);

            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                String payload = http.getString();
                USE_SERIAL.println(payload);
            }
        } else {
            USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
    }

    delay(5000);
    server.handleClient();
}

void base(){
  server.send(200, "text/html",page);
}

void manSwitchFunct(){
  value = 0; 
}

void autoSwitchFunct(){
  value = 1; 
}

void motorStart(){
  motorState = true; 
}

void motorStop(){
  motorState = true; 
}

void handleNotFound() {

  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}
