#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows
Servo angles;
Servo pousse;

const byte ROWS = 4; //nombre de lignes
const byte COLS = 4; //nombre de colonnes
char kp4x4keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '.', 'D'}
};
byte rowKp4x4Pins[ROWS] = {5, 4, 3, 2}; //entrées numériques où sont branchées les lignes
byte colKp4x4Pins[COLS] = {9, 8, 7, 6}; //entrées numériques où sont branchées les colonnes
Keypad keypad = Keypad( makeKeymap(kp4x4keys), rowKp4x4Pins, colKp4x4Pins, ROWS, COLS );

int ligne = 0;
int colonne = 0;
String prix;
int list[50] = {};
int types[8] = {200, 100, 50, 20, 10, 5, 2, 1}; 
int piece = 0;
int comp = 0;
int vale = 0;
int i = 0;
int argent = 0;

void setup() {
  Serial.begin(57600);
  angles.attach(10);
  pousse.attach(11);
  lcd.init(); // initialize the lcd
  lcd.backlight();
}

void loop() {
  char key = keypad.getKey();
  if (key != NO_KEY) {
    if (key == '*') { //on efface le dernier chiffre
      prix = prix.substring(0, prix.length() - 1);
      if (colonne > 0) {
        colonne = colonne - 1;
      }
    }
      lcd.setCursor(colonne, ligne);
      lcd.print(' ');
    }
    else { // alors on a tapé un chiffre
      lcd.setCursor(colonne, ligne);
      if (key != 'D') {
        lcd.print(key);
        if (key != '.') {
          prix += key;
        }
        colonne = colonne + 1;
      }

      if (colonne > 15) {
        if (ligne == 0) { // alors on saute à  la ligne suivante
          colonne = 0;
          ligne = 1;
        }
        else { // alors on retourne au début
          colonne = 0;
          ligne = 0;
        }
      }
      else if (key == 'D') {
        Serial.println(prix);
        argent = prix.toInt();
        Serial.print("argent :");
        Serial.println(argent);
        monnaie_rendue();
        delay(10);
        p_rendue();
        Serial.println("Pieces delivrees");
        lcd.clear();
        lcd.print("Pieces delivrees");
        lcd.setCursor(0,1);
        lcd.print(" Bonne journee! ");
        prix=" ";
        delay(3000);
        lcd.clear();
        colonne = 0;
      }
    }
  }
}
