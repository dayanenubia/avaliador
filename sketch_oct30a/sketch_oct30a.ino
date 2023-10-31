#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int pushbutton2 = 4; // declara o push button na porta 2
int pushbutton1= 8;
int pushbutton0 = 7;

int led = 12; // declara led na porta 13
bool estadoled = 0;

int contador1 = 0;
int contador2 = 0;
int contador0 = 0;

void setup() {
  lcd.init();
  lcd.setBacklight(HIGH); 
  pinMode(pushbutton0, INPUT_PULLUP); // define o pino do botao como entrada
  pinMode(pushbutton1, INPUT_PULLUP);
  pinMode(pushbutton2, INPUT_PULLUP);
  pinMode(led, OUTPUT);// define LED como saida
  pinMode(LED_BUILTIN, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Bom");
  lcd.setCursor(4,0);
  lcd.print("Regular");
  lcd.setCursor(12,0);
  lcd.print("Ruim");

  if (digitalRead(pushbutton0) == LOW){
    contador0++;
    Serial.print("Contador0: ");
    Serial.println(contador0);
    lcd.setCursor(1,1);
    lcd.print(contador0);
    estadoled = !estadoled; // troca o estado do LED
    digitalWrite(led, estadoled);
    while (digitalRead(pushbutton0) == LOW);
    delay(50);
  } else if (digitalRead(pushbutton1) == LOW){
    contador1++;
    Serial.print("Contador1: ");
    Serial.println(contador1);
    lcd.setCursor(7,1);
    lcd.print(contador1);
    estadoled = !estadoled; // troca o estado do LED
    digitalWrite(led, estadoled);
    while (digitalRead(pushbutton1) == LOW);
    delay(50);
  } else if (digitalRead(pushbutton2) == LOW){
    contador2++;
    Serial.print("Contador2: ");
    Serial.println(contador2);
    lcd.setCursor(14,1);
    lcd.print(contador2);
    estadoled = !estadoled; // troca o estado do LED
    digitalWrite(led, estadoled);
    while (digitalRead(pushbutton2) == LOW);
    delay(50);
  }

}
