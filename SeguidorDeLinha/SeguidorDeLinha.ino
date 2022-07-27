// Cor de acordo com iluminação
int DTBranco =  12;

// Motores
int MotorRodaDireitaNeg = 10;
int MotorRodaDireitaPos = 11;
int MotorRodaEsquerdaNeg = 12;
int MotorRodaEsquerdaPos = 13;

int PotenciaMotorDireita = A0;
int PotenciaMotorEsquerda = A1;

// Sensor cor 1
int S1pinS0 = 53;
int S1pinS1 = 51;
int S1pinS2 = 49;
int S1pinS3 = 47;
int S1pinOut = 45;

int S2pinS0 = 50;
int S2pinS1 = 52;
int S2pinS2 = 46;
int S2pinS3 = 48;
int S2pinOut = 44;

int S3pinS0 = 43;
int S3pinS1 = 42;
int S3pinS2 = 38;
int S3pinS3 = 40;
int S3pinOut = 36;

unsigned int S1Verm;
unsigned int S1Verd;
unsigned int S1Azul;
unsigned int S1Bran;
unsigned int S2Verm;
unsigned int S2Verd;
unsigned int S2Azul;
unsigned int S2Bran;
unsigned int S3Verm;
unsigned int S3Verd;
unsigned int S3Azul;
unsigned int S3Bran;

void AndarParaFrente()
{
  digitalWrite(MotorRodaDireitaNeg, LOW);
  digitalWrite(MotorRodaEsquerdaNeg, LOW);
  digitalWrite(MotorRodaDireitaPos, HIGH);
  digitalWrite(MotorRodaEsquerdaPos, HIGH);
}

void AndarParaTras()
{
  digitalWrite(MotorRodaDireitaNeg, HIGH);
  digitalWrite(MotorRodaEsquerdaNeg, HIGH);
  digitalWrite(MotorRodaDireitaPos, LOW);
  digitalWrite(MotorRodaEsquerdaPos, LOW);
}

void VirarEsquerda()
{
  digitalWrite(MotorRodaEsquerdaPos, LOW);
}

void VirarDireita()
{
  digitalWrite(MotorRodaDireitaNeg, HIGH);
  digitalWrite(MotorRodaEsquerdaNeg, LOW);
  digitalWrite(MotorRodaDireitaPos, LOW);
  digitalWrite(MotorRodaEsquerdaPos, LOW);
}

void Parar()
{
  digitalWrite(MotorRodaDireitaNeg, LOW);
  digitalWrite(MotorRodaEsquerdaNeg, LOW);
  digitalWrite(MotorRodaDireitaPos, LOW);
  digitalWrite(MotorRodaEsquerdaPos, LOW);
}

void detectarCor()
{
  // Sensor S1
  digitalWrite(S1pinS2, LOW);
  digitalWrite(S1pinS3, LOW);
  S1Verm = pulseIn(S1pinOut, digitalRead(S1pinOut) == HIGH ? LOW : HIGH);

  digitalWrite(S1pinS3, LOW);
  digitalWrite(S1pinS2, HIGH);
  S1Bran = pulseIn(S1pinOut, digitalRead(S1pinOut) == HIGH ? LOW : HIGH);

  digitalWrite(S1pinS2, LOW);
  digitalWrite(S1pinS3, HIGH);
  S1Azul = pulseIn(S1pinOut, digitalRead(S1pinOut) == HIGH ? LOW : HIGH);

  digitalWrite(S1pinS2, HIGH);
  digitalWrite(S1pinS3, HIGH);
  S1Verd = pulseIn(S1pinOut, digitalRead(S1pinOut) == HIGH ? LOW : HIGH);

  // Sensor S2
  digitalWrite(S2pinS2, LOW);
  digitalWrite(S2pinS3, LOW);
  S2Verm = pulseIn(S2pinOut, digitalRead(S2pinOut) == HIGH ? LOW : HIGH);

  digitalWrite(S2pinS3, LOW);
  digitalWrite(S2pinS2, HIGH);
  S2Bran = pulseIn(S2pinOut, digitalRead(S2pinOut) == HIGH ? LOW : HIGH);

  digitalWrite(S2pinS2, LOW);
  digitalWrite(S2pinS3, HIGH);
  S2Azul = pulseIn(S2pinOut, digitalRead(S2pinOut) == HIGH ? LOW : HIGH);

  digitalWrite(S2pinS2, HIGH);
  digitalWrite(S2pinS3, HIGH);
  S2Verd = pulseIn(S2pinOut, digitalRead(S2pinOut) == HIGH ? LOW : HIGH);

  // Sensor 3
  digitalWrite(S3pinS2, LOW);
  digitalWrite(S3pinS3, LOW);
  S3Verm = pulseIn(S3pinOut, digitalRead(S3pinOut) == HIGH ? LOW : HIGH);

  digitalWrite(S3pinS3, LOW);
  digitalWrite(S3pinS2, HIGH);
  S3Bran = pulseIn(S3pinOut, digitalRead(S3pinOut) == HIGH ? LOW : HIGH);

  digitalWrite(S3pinS2, LOW);
  digitalWrite(S3pinS3, HIGH);
  S3Azul = pulseIn(S3pinOut, digitalRead(S3pinOut) == HIGH ? LOW : HIGH);

  digitalWrite(S3pinS2, HIGH);
  digitalWrite(S3pinS3, HIGH);
  S3Verd = pulseIn(S3pinOut, digitalRead(S3pinOut) == HIGH ? LOW : HIGH);
}

void setup()
{
  // Motores
  pinMode(MotorRodaDireitaNeg, OUTPUT);
  pinMode(MotorRodaDireitaPos, OUTPUT);
  pinMode(MotorRodaEsquerdaNeg, OUTPUT);
  pinMode(MotorRodaEsquerdaPos, OUTPUT);
  // Sensor S1
  pinMode(S1pinS0, OUTPUT);
  pinMode(S1pinS1, OUTPUT);
  pinMode(S1pinS2, OUTPUT);
  pinMode(S1pinS3, OUTPUT);
  pinMode(S1pinOut, INPUT);
  // Sensor S2
  pinMode(S2pinS0, OUTPUT);
  pinMode(S2pinS1, OUTPUT);
  pinMode(S2pinS2, OUTPUT);
  pinMode(S2pinS3, OUTPUT);
  pinMode(S2pinOut, INPUT);
  // Sensor S3
  pinMode(S3pinS0, OUTPUT);
  pinMode(S3pinS1, OUTPUT);
  pinMode(S3pinS2, OUTPUT);
  pinMode(S3pinS3, OUTPUT);
  pinMode(S3pinOut, INPUT);

  Serial.begin(9600);
  digitalWrite(S1pinS0, HIGH);
  digitalWrite(S1pinS1, LOW);
  digitalWrite(S2pinS0, HIGH);
  digitalWrite(S2pinS1, LOW);
  digitalWrite(S3pinS0, HIGH);
  digitalWrite(S3pinS1, LOW);
  analogWrite(PotenciaMotorEsquerda, 130);
  analogWrite(PotenciaMotorDireita, 130);
}

bool pretoDireita = false;
bool pretoEsquerda = false;
bool verdeDireita = false;
bool verdeEsquerda = false;
int perdidoAvante = 0;
int perdidoRetorno = 0;

void loop() {
  detectarCor();
  Serial.print("S1Vermelho: ");
  Serial.print(S1Verm);
  Serial.print(" S1Verde: ");
  Serial.print(S1Verd);
  Serial.print(" S1Azul: ");
  Serial.print(S1Azul);
  Serial.print(" S1Branco: ");
  Serial.print(S1Bran);
  Serial.print("; S2Vermelho: ");
  Serial.print(S2Verm);
  Serial.print(" S2Verde: ");
  Serial.print(S2Verd);
  Serial.print(" S2Azul: ");
  Serial.print(S2Azul);
  Serial.print(" S2Branco: ");
  Serial.print(S2Bran);
  Serial.print("; S3Vermelho: ");
  Serial.print(S3Verm);
  Serial.print(" S3Verde: ");
  Serial.print(S3Verd);
  Serial.print(" S3Azul: ");
  Serial.print(S3Azul);
  Serial.print(" S3Branco: ");
  Serial.print(S3Bran);
  Serial.println();
  if(S2Bran >= DTBranco && S1Bran < DTBranco && S3Bran < DTBranco){
     AndarParaFrente();
     pretoDireita = false;
     pretoEsquerda = false;
     verdeDireita = false;
     verdeEsquerda = false;
  } 
  else if(S2Bran >= DTBranco && S1Bran >= DTBranco && S3Bran >= DTBranco){
    if(S1Verm > S1Verd){
      verdeEsquerda = true;
    }
    if(S3Verm > S3Verd){
      verdeDireita = true;
    }
    if(verdeEsquerda && verdeDireita){
      Parar(); //Temporário, tem que fazer voltar
    } else if(verdeDireita){
      AndarParaFrente();
        delay(500);
        VirarDireita();
        delay(1000);
         do{
          detectarCor();
          VirarDireita();
        }while(S2Bran < DTBranco);
        pretoEsquerda = false;
    } else if(verdeEsquerda){
      AndarParaFrente();
        delay(500);
        VirarEsquerda();
        delay(1000);
         do{
          detectarCor();
          VirarEsquerda();
        }while(S2Bran < DTBranco);
        pretoDireita = false;
    }
  }
  else if(S2Bran >= DTBranco && S1Bran >= DTBranco && S3Bran < DTBranco){
    verdeDireita = false;
    pretoDireita = false;
    if(S1Verm > S1Verd){
        AndarParaFrente();
        delay(500);
        VirarEsquerda();
        delay(1000);
         do{
          detectarCor();
          VirarEsquerda();
        }while(S2Bran < DTBranco);
        pretoEsquerda = false;
        pretoDireita = false;
    }
    else{
        AndarParaFrente();
        pretoEsquerda = true;
    }
  } 
  else if(S2Bran >= DTBranco && S1Bran < DTBranco && S3Bran >= DTBranco){
    verdeEsquerda = false;
    pretoEsquerda = false;
    if(S3Verm > S3Verd){
        AndarParaFrente();
        delay(500);
        VirarDireita();
        delay(1000);
         do{
          detectarCor();
          VirarDireita();
        }while(S2Bran < DTBranco);
        pretoEsquerda = false;
        pretoDireita = false;
    }
    else{
      pretoDireita = true;
      AndarParaFrente();
    }
  }
  else if(S2Bran < DTBranco && S1Bran < DTBranco && S3Bran < DTBranco){
    verdeEsquerda = false;
    verdeDireita = false;
    if(pretoDireita){
      do{
        detectarCor();
        VirarDireita();
      }while(S2Bran < DTBranco);
      pretoEsquerda = false;
      pretoDireita = false;
    }
    else if(pretoEsquerda){
      do{
        detectarCor();
        VirarEsquerda();
      }while(S2Bran < DTBranco);
      pretoEsquerda = false;
      pretoDireita = false;
    }
    else {
      AndarParaFrente();
      delay(3000);
      detectarCor();
      if(S2Bran < DTBranco && S1Bran < DTBranco && S3Bran < DTBranco){
        AndarParaTras();
        delay(3000);
        VirarDireita();
        delay(500);
        AndarParaFrente();
        delay(3000);
        detectarCor();
        if(S2Bran < DTBranco && S1Bran < DTBranco && S3Bran < DTBranco){
          VirarEsquerda();
          delay(500);
          AndarParaTras();
          delay(3000);
          VirarEsquerda();
          delay(500);
          AndarParaFrente();
          delay(3000);
          detectarCor();
          if(S2Bran < DTBranco && S1Bran < DTBranco && S3Bran < DTBranco){
            VirarDireita();
            delay(500);
            AndarParaTras();
            delay(3000);
            do{
              AndarParaFrente();
              detectarCor();
            }while(S2Bran < DTBranco);
          }
        }
      }
    }
  }
  else if(S2Bran < DTBranco && S1Bran < DTBranco && S3Bran >= DTBranco){
      do{
        detectarCor();
        VirarDireita();
      }while(S2Bran < DTBranco);
      pretoDireita = false;
      pretoEsquerda = false;
  }
  if(S2Bran < DTBranco && S1Bran >= DTBranco && S3Bran < DTBranco){
    do{
        detectarCor();
        VirarEsquerda();
      }while(S2Bran < DTBranco);
      pretoEsquerda = false;
      pretoDireita = false;
  }
}
