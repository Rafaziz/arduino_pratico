#include <LiquidCrystal.h>

LiquidCrystal lcd (12, 11, 5, 4, 3, 2);

String lerSerial ()
{
  String conteudo1 = "";
  char entrada1;

  // Se receber algo pela serial
  while (Serial.available() > 0) {
    //Segue fazendo a leitora de cada byte enviado
    entrada1 = Serial.read();

    //Ignora sinal/caractere de ENTER
    if (entrada1 != '\n') {
      conteudo1.concat(entrada1);
    }
    // Aguarda buffer serial ler próximo caractere
    delay(10);
  }
  //Quando não houver mais bytes a ler...
  if (Serial.available() <= 0) {
    return conteudo1;
  }
}


void setup() {
  Serial.begin(9600);
  //Inicia o LCD com suas dimensões
  lcd.begin(16, 2);
  //Imprime uma mensagem no LCD
  lcd.print("Hello World!");
}

void loop() {
  //Coloca o cursor na linha x=0 e coluna y=1.
  lcd.setCursor(0, 1);

  //Imprime o tempo de operação
  //lcd.print(millis()/1000);

  if (Serial.available() > 0)
  {
    String val = lerSerial();
    Serial.println(val);
    lcd.print(val);
  }
}
