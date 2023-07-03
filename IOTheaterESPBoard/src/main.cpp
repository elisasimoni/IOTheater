#include <Arduino.h>
#include "config.h"
#include "model/ESPBoard.h"
#include "task/ActorPresenceTask.h"
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <TaskManagerIO.h>

// Configurazione della rete WiFi
const char* ssid = "WifiElisa";
const char* password = "pmkn1956";

// Configurazione del broker MQTT
const char* mqttServer = "broker.emqx.io";
const int mqttPort = 1883;
const char* mqttTopic = "esp/dati";

// Oggetto per la connessione WiFi
WiFiClient wifiClient;
// Oggetto per la connessione MQTT
PubSubClient mqttClient(wifiClient);

// Oggetto per la gestione della task
ActorPresenceTask* actorPresenceTask;

ESPBoard* espBoard;
	

void startWiFi() {
  // Connessione alla rete WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connessione alla rete WiFi...");
  }
  Serial.println("Connesso alla rete WiFi!");
}

void connection() {
  // Connessione al broker MQTT
  mqttClient.setServer(mqttServer, mqttPort);
  while (!mqttClient.connected()) {
    Serial.println("Connessione al broker MQTT...");
    if (mqttClient.connect("ESP8266Client")) {
      Serial.println("Connesso al broker MQTT!");
    } else {
      Serial.println("Connessione al broker MQTT fallita, codice di errore: ");
      Serial.println(mqttClient.state());
      delay(5000);
    }
  }
}



void sendMsg(bool presence) {
  // Invio del codice al server MQTT 
  String payload = presence ? "true" : "false";
  boolean success = mqttClient.publish(mqttTopic, payload.c_str());
  if (success) {
    Serial.println("Messaggio MQTT inviato con successo");
  } else {
    int mqttState = mqttClient.state();
    Serial.print("Errore durante l'invio del messaggio MQTT. Stato: ");
    Serial.println(mqttState);
  }
  if(presence){
    mqttClient.publish("esp/presence", payload.c_str());
  }else{
    mqttClient.publish("esp/nopresence", payload.c_str());
  }
  
  Serial.println("Messaggio inviato");
}

void setup() {
  Serial.begin(115200);
  espBoard = new ESPBoard(PIR_PIN, LED_PIN);
  startWiFi();
  connection();
  
}

void loop() {

    if (espBoard->isActorSpotlight()) {
        espBoard->lightSwitchOn();
        connection();
        sendMsg(true);
    } else{
       espBoard->lightSwitchOff();
     connection();
       sendMsg(false);
    }
    delay(1000);

  mqttClient.loop();
}
