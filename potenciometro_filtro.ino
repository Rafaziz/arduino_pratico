#define N_INTERACAO 700
int filtroLinear(int porta)
{
  unsigned long sinalFiltrado = 0;

  for (int i = 0; i < N_INTERACAO; i++)
  {
    sinalFiltrado += analogRead(porta);
  }
  return sinalFiltrado / N_INTERACAO;
}
void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop()
{
  int val = 0;
  //val = analogRead (A0);
  Serial.println(filtroLinear(A0));
  //Serial.println(val);
  delay(100);
}
