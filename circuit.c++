int sinal=3;
float distancia;
void leitura();

int vermelho=13;
int azul=11;
int verde=10;

void vermelhoFuncao(){
  digitalWrite(azul,LOW);
  digitalWrite(verde,LOW);
  digitalWrite(vermelho,HIGH);
}
void amareloFuncao(){
  digitalWrite(azul,0);
  digitalWrite(verde,5);
  digitalWrite(vermelho,255);
}
void verdeFuncao(){
  digitalWrite(azul,LOW);
  digitalWrite(verde,HIGH);
  digitalWrite(vermelho,LOW);
}
void setup()
{
  Serial.begin(9600);
  pinMode(sinal,OUTPUT);
  digitalWrite(sinal,LOW);
  pinMode(verde, OUTPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(azul, OUTPUT);
}
void loop()
{
  leitura();
  distancia = distancia/2;  
  distancia=distancia*0.034029;
  Serial.println("Distancia:");
  Serial.println(distancia);
  delay(250);
  
  if (distancia>=3 && distancia<75)
    verdeFuncao();
  else if (distancia>=75 && distancia<150)
    amareloFuncao();
  else
    vermelhoFuncao();
    
    float sinaltemp=analogRead(A4)*5;
  	float TempC=((sinaltemp/1023)-0.5)*100;
  	Serial.println("Temperatura:");
  	Serial.println(TempC);
  	delay(250);
    int sinalgas=analogRead(A5);
  	sinalgas=map(sinalgas,300,750,0,100);
  	Serial.println("Gas:");
  	Serial.println(sinalgas);
  	delay(250);
}
void leitura()
{
  pinMode(sinal,OUTPUT);
  digitalWrite(sinal,HIGH);
  delayMicroseconds(5);
  digitalWrite(sinal,LOW);
  pinMode(sinal,INPUT);
  distancia=pulseIn(sinal,HIGH);
}
  
