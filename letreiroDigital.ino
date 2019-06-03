

void setup() {
  Serial.begin(9600);
}
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
void loop() {
  //Se há entrada de dados...
  if (Serial.available() > 0)
  {
    String val = lerSerial();
    Serial.println(val);
  }
}
