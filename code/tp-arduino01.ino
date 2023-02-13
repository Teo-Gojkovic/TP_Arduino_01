/*
    Name:           tp-arduino01.ino
    Created:	      13/02/2023
    last update:    13/02/2023
    @Author:        Teo GOJKOVIC
*/
//Library pour le projet
#include <DHT.h>
#include <LiquidCrystal.h>

//Pins de l'écran LCD 2*16
#define rs A0
#define en A1
#define d4 6
#define d5 5
#define d6 4
#define d7 3
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#define data 2
DHT dht(2, DHT11);


void setup() {
   dht.begin();           // Initialisation du capteur
   Serial.begin(9600);    // Initialisation du port série et son port
}


//Création de la boucle
void loop() {
   float h = dht.readHumidity();      //création d'une variable flottante qui stocke la valeur de l'humidité
   float t = dht.readTemperature();   //création d'une variable flottante qui stocke la valeur de la température


  //Affichage sur le port série
   Serial.print("Humidity: ");
   Serial.println(h);
   Serial.print("Temperature: ");
   Serial.println(t);


  //Affichage sur l'écran LCD
   lcd.begin(16, 2);                        //Initialisation de l'écran
   lcd.setCursor(0, 0);                     //Position du curseur (colonne 0, ligne 0)
   lcd.print("temp : | hum :");
   lcd.setCursor(0, 1);                     //Position du curseur (colonne 0, ligne 1)
   lcd.print(t); lcd.print("*C| ");
   lcd.print(h); lcd.print("%");
 
  delay(1000);                              //Attendre 1000 ms soit 1 seconde avant de refaire la boucle
}
