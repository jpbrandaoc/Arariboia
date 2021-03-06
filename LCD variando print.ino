//Programa de arduíno para o LCD mudar o que se printa a partir de botão
#include <LiquidCrystal.h>


LiquidCrystal lcd(2,3,4,5,6,7);
int porta = 12;
float Bat_P = 48; //inventei valores de tensão e corrente aqui
float I= 55.5 ;
float Bat_Aux = 24;
int i = 0; // Contador
int anterior;
int timerButton;
int timerLCD;

void setup() {
  Serial.begin(9600);
  timerButton = millis();
  timerLCD = millis();
  lcd.begin(16, 2);
  pinMode(porta, INPUT_PULLUP);
  anterior = digitalRead(porta);
  lcd.clear();
  lcd.print("Starting");
}

void lcd0() {
  lcd.clear();
  lcd.print("I: ");
  lcd.print(I);
  lcd.print(" A");
  lcd.setCursor(0,1);
  lcd.print("Bat_P: ");
  lcd.print(Bat_P);
  lcd.print(" V");
}

void lcd1(){
  lcd.clear();
  lcd.print("Bat_Aux: ");
  lcd.print(Bat_Aux);
  lcd.print(" V");
}

void loop() {
  // inicia o lcd
  
  int sinal= digitalRead(porta);
  // Contador muda apertando o botão
  if (sinal == HIGH && millis() - timerButton  > 1000){
    Serial.println("a");
    timerButton = millis();
    anterior = sinal;
    if (i == 0) {
      i = 1;
      lcd1();
    }
      
    else {
      i = 0;
      lcd0();
    }
      
  }
  if (millis() - timerLCD > 1000) {
    timerLCD = millis();
    if (i==0) lcd0();
    
    else if (i==1) lcd1();
  }
}
