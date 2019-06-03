#define red 9
#define green 7
#define yellow 4
#define blue 3
#define orange 2
int arrayLed[] = {red, green, yellow, blue, orange};
int tamanhoArray = sizeof(arrayLed) / sizeof(arrayLed[0]);
char entrada;
void trocarEstadoLed(char estado)
{
  switch (estado)
  {
    case '0':
      apaga();
      break;
    case '1':
      acende();
      break;
    case '2':
      sequencial();
      break;
  }
}
void apaga()
{
  for (int i =0; i<tamanhoArray; i++)
  {
    digitalWrite(arrayLed[i], LOW);
  }
}
void acende()
{
  for (int i =0; i<tamanhoArray; i++)
  {
    digitalWrite(arrayLed[i], HIGH);
  }
}
void sequencial()
{
  for (int i=0; i < tamanhoArray; i++)
  {
    digitalWrite(arrayLed[i], HIGH);
    delay (150);
    digitalWrite(arrayLed[i], LOW);
    delay (150);
  }
}

void setup()
{
  Serial.begin(9600);
  
  for (int i =0; i<tamanhoArray; i++)
  {
    pinMode(arrayLed[i], OUTPUT);
  }
}

void loop()
{
  
  if (Serial.available() > 0)
  {
    // Lê byte da serial
    entrada = Serial.read();
    Serial.println(entrada);
  }
    trocarEstadoLed(entrada);
}
