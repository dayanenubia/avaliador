#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int pushbutton2 = 5; // declara o push button na porta 2
int pushbutton1= 6;
int pushbutton0 = 3;  
int led = 4; // declara led na porta 13
bool estadoled = 0; // variavel de controle
int contador1 = 0;
int contador2 = 0;
int contador0 = 0;

void setup()
{
  pinMode(pushbutton0, INPUT_PULLUP); // define o pino do botao como entrada
  pinMode(pushbutton1, INPUT_PULLUP);
  pinMode(pushbutton2, INPUT_PULLUP);
  pinMode(led, OUTPUT);// define LED como saida
  lcd.begin(16,2);
  lcd.init();
  Serial.begin(115200);
}

void loop()
{
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("AUTOMAÇÃO EM 5 MINUTOS");
  if (digitalRead(pushbutton0) == LOW) // Se o botão for pressionado
  {
    contador0++;
    Serial.print("Contador0: ");
    Serial.println(contador0);
    estadoled = !estadoled; // troca o estado do LED
    digitalWrite(led, estadoled);
    while (digitalRead(pushbutton0) == LOW);
    delay(50);
  } else if (digitalRead(pushbutton1) == LOW) // Se o botão for pressionado
  {
    contador1++;
    Serial.print("Contador1: ");
    Serial.println(contador1);
    estadoled = !estadoled; // troca o estado do LED
    digitalWrite(led, estadoled);
    while (digitalRead(pushbutton1) == LOW);
    delay(50);
  }else if (digitalRead(pushbutton2) == LOW) // Se o botão for pressionado
  {
    contador2++;
    Serial.print("Contador2: ");
    Serial.println(contador2);
    estadoled = !estadoled; // troca o estado do LED
    digitalWrite(led, estadoled);
    while (digitalRead(pushbutton2) == LOW);
    delay(50);
  }
}
