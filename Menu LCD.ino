//Programa para criação de um menu no lcd com um botão
#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);
int porta = 12;
int i = 0; // Contador
int anterior;
int timerButton;
int timerLCD;
string vetor_menu[3]={'bat.p','bat.aux','corrente'}; //supus 3 dados
float vetor_valores[3]={}; //os dados teriam que ser alocados aqui

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

void loop() {
  // inicia o lcd
  lcd.clear();
  lcd.printf(vetor_menu[i]);
  int sinal= digitalRead(porta);
// Contador muda apertando o botão
  if (sinal == HIGH && millis() - timerButton  > 1000 && millis() - timerButton  < 3000){
    Serial.println("a");
    timerButton = millis();
    anterior = sinal;
    i=i+1;
 // Dado aparece ao se pressionar o botão por 3 segundos
  if (sinal == HIGH && millis() - timerButton  > 3000){
    lcd.setCursor(0,1);
    lcd.printf(vetor_valores[i]);
    }
