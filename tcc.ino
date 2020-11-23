/*ACELERÔMETRO E GIROSCÓPIO*/
#define pinAcelX A0
#define pinAcelY A1
#define pinAcelZ A2
int queda;
/*ACELERÔMETRO E GIROSCÓPIO*/

/*BATIMENTO CARDÍACO*/
int fadePino = 5; /*led efeito "fade"*/
int fadeEfeito = 0; /*efeito fade*/
int pulsePino = 0; /*dados do sensor*/
int ledPino = 13; //led

  /*variáveis de interrupção*/
  volatile int BPM;
  volatile int Sinal; /*dados do sensor*/
  volatile int IBI = 950; /*intervalo de batidas*/
  volatile boolean Pulse = false; /*sim para pulsação --> true*/
  volatile boolean QS = false /*sim para alguma pulsação --> true;*/

  static int outputType = SERIAL_PLOTTER;
/*BATIMENTO CARDÍACO*/

void setup() 
{
  Serial.begin(9600);

  /*batimento cardíaco*/
  pinMode(ledPino,OUTPUT);
  pinMode(fadePino,OUTPUT);
  Serial.begin(115200); /*pode fazer isso? declarar serial.begin duas vezes? */
  interruptSetup(); /*ativa leitura de 2ms*/
  /*batimento cardíaco*/
}

void loop() 
{

  /*ACELEROMETRO E GIROSCÓPIO*/
  
  /*leiturados valores de X, Y e Z*/
  int valX = analogRead(pinAcelX);
  int valY = analogRead(pinAcelY);
  int valZ = analogRead(pinAcelZ);

  /*X*/
  Serial.print("\nX: ");
  Serial.print(valX); 

  /*Y*/
  Serial.print("\nY: ");
  Serial.print(valY); 

  /*Z*/
  Serial.print("\nZ: ");
  Serial.print(valZ); 

  /*detectar queda*/
  if (valZ<300)
    {
      Serial.print("Queda detectada");
      queda++;
    }

    /*tomba pra esquerda*/
    else if ((valZ<xxxxxx) && (valY<xxxxx))
      {
        Serial.print("Queda detectada");
        queda++;
      }

    /*tomba pra direita*/  
    else if ((valZ<xxxxxx) && (valY>xxxxx))
      {
        Serial.print("Queda detectada");
        queda++;
      }

    /*tomba pra frente*/  
    else if ((valZ<xxxxxx) && (valX<xxxxx))
      {
        Serial.print("Queda detectada");
        queda++;
      }

    /*tomba pra trás*/  
    else if ((valZ<xxxxxx) && (valX>xxxxx))
      {
        Serial.print("Queda detectada");
        queda++;
      }
      
   else 
    {
      Serial.print("Nenhuma queda detectada");
    }

    /*comunicação*/
    if (queda>=1)
      {
        /*MÓDULO WI-FI*/
      }

   /*ACELERÔMETRO E GIROSCÓPIO*/
   
  /*_________________________________________________________________________________________________________________________________________________________________________*/

   /*BATIMENTO CARDÍACO*/

  serialOutput();

  if(QS == true) /*encontra pulsação*/
  {
    fadeEfeito = 255; /*efeito "fade"*/
    serialOutputWhenBeatHappens();
    QS = false;
  }

  ledFadeToBeat(); /*efeito "fade"*/
  delay(95);
  
   /*BATIMENTO CARDÍACO*/
}

void ledFadeToBeat()
{
  fadeEfeito -= 30;
  fadeEfeito = constrain(fadeEfeito,0,255);
  analogWrite(fadePino,fadeEfeito);  
}
