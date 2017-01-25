
#define RED 3
#define BLUE 5
#define GREEN 6
#define SENSOR A0
#define SOM 11

int valorSensor;
long tempoAnterior = 0;
long intervaloSom = 5000;
int musicaNotas[] = {660,660,660,510,660,770,380};
int musicaDuracoes[] = {100,100,100,100,100,100,100};
int musicaPausas[] = {150,300,300,100,300,550,575};

void setup(){

  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);  
  pinMode(GREEN, OUTPUT);
  pinMode(SENSOR, INPUT);
  pinMode(SOM, OUTPUT); 
  
}

void loop() {  
  
  unsigned long tempoAtual = millis();
  
  valorSensor = analogRead(SENSOR);
  
  if(valorSensor >= 0 && valorSensor < 400) {
    ligaLedVerde();
  }
  
  if(valorSensor >= 400 && valorSensor < 800) {
    ligaLedAmarelo();
  }
  
  if(valorSensor >= 800 && valorSensor < 1024) {
    ligaLedVermelho();
    
    if(tempoAtual - tempoAnterior > intervaloSom){
      tempoAnterior = tempoAtual;
      tocaMusica();
          
    }
  }   
    
  delay(1000);
}

void ligaLedVermelho(){  
  analogWrite(RED, 255);
  analogWrite(GREEN, 0);  
  analogWrite(BLUE, 0);  
}

void ligaLedAmarelo(){  
  analogWrite(RED, 250);
  analogWrite(GREEN, 150);    
  analogWrite(BLUE, 0);
}

void ligaLedVerde(){  
  analogWrite(RED, 0);
  analogWrite(GREEN, 255);    
  analogWrite(BLUE, 0);
}

void tocaMusica(){
  for (int nota = 0; nota < 7; nota++) {    
    int musicaDuracao = musicaDuracoes[nota];    
    tone(SOM, musicaNotas[nota], musicaDuracao);    
    delay(musicaPausas[nota]);  
  }
  
}

