const int ledEntrada = 8;
const int ledBar = 9;
const int ledEscadaria = 10;
const int ledSalaControle = 11;
const int ledRelogio = 12;
const int ledRestaurante = 7;


 char acao = '0'; // [ON,OFF] // [a,b] Entrada; [c,d] Bar; [e,f] Escadaria; [g,h] Sala de Controle; [i,j] Relogio; [k,l] Restaurante; [t,r] Tudo;  [w,p] Modo Festa;

void setup() {
  pinMode(ledEntrada, OUTPUT);
  pinMode(ledBar, OUTPUT);
  pinMode(ledEscadaria, OUTPUT);
  pinMode(ledSalaControle, OUTPUT);
  pinMode(ledRelogio, OUTPUT);
  pinMode(ledRestaurante, OUTPUT);
  Serial.begin(9600);  
}

void loop(){
    if (Serial.available() >0) {
        acao = Serial.read();
        Serial.println(acao);
        
        //LIGA LUZ ENTRADA
        if(acao == 'a'){
          digitalWrite(ledEntrada, HIGH);
        }
        //DESLIGA LUZ ENTRADA
        if(acao == 'b'){
          digitalWrite(ledEntrada, LOW);
        }
        //LIGA LUZ BAR
        if(acao == 'c'){
          digitalWrite(ledBar, HIGH);
        }
        //DESLIGA LUZ BAR
        if(acao == 'd'){
          digitalWrite(ledBar, LOW);
        }
        //LIGA LUZ ESCADARIA
        if(acao == 'e'){
          digitalWrite(ledEscadaria, HIGH);
        }
        //DESLIGA LUZ ESCADARIA
        if(acao == 'f'){
          digitalWrite(ledEscadaria, LOW);
        }
        //LIGA LUZ SALA DE CONTROLE
        if(acao == 'g'){
          digitalWrite(ledSalaControle, HIGH);
        }
        //DESLIGA LUZ SALA DE CONTROLE
        if(acao == 'h'){
          digitalWrite(ledSalaControle, LOW);
        }
        //LIGA LUZ RELOGIO
        if(acao == 'i'){
          digitalWrite(ledRelogio, HIGH);
        }
        //DESLIGA LUZ RELOGIO
        if(acao == 'j'){
          digitalWrite(ledRelogio, LOW);
        }
        //LIGA LUZ RESTAURANTE
        if(acao == 'k'){
          digitalWrite(ledRestaurante, HIGH);
        }
        //DESLIGA LUZ RESTAURANTE
        if(acao == 'l'){
          digitalWrite(ledRestaurante, LOW);
        }
        
        //LIGA TUDO
        if(acao == 't'){
          digitalWrite(ledEntrada, HIGH);
          digitalWrite(ledBar, HIGH);
          digitalWrite(ledEscadaria, HIGH);
          digitalWrite(ledSalaControle, HIGH);
          digitalWrite(ledRelogio, HIGH);
          digitalWrite(ledRestaurante, HIGH);
        }
        //DESLIGA TUDO
        if(acao == 'r'){
          digitalWrite(ledEntrada, LOW);
          digitalWrite(ledBar, LOW);
          digitalWrite(ledEscadaria, LOW);
          digitalWrite(ledSalaControle, LOW);
          digitalWrite(ledRelogio, LOW);
          digitalWrite(ledRestaurante, LOW);
        }
        
        //MODO FESTA
        if(acao == 'w'){
          int i = 0;
          while(acao != 'p'){
            if(i != 0){
              acao = Serial.read();
            }
            delay(100);
            digitalWrite(ledRestaurante, HIGH);
            delay(100);
            digitalWrite(ledRestaurante, LOW);
            i++;
          }
        }
        
    }
    
    Serial.flush();
    
    //digitalWrite(ledBar, LOW);
          //digitalWrite(ledEscadaria, LOW);
          //digitalWrite(ledSalaControle, LOW);
          //digitalWrite(ledRelogio, LOW);
          //digitalWrite(ledRestaurante, HIGH);
}
