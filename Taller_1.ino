int amarillo = 13;
int rojo = 12;
int verde = 11;

void setup() {
  pinMode(amarillo, OUTPUT);
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) { 
    int opcion = Serial.parseInt(); 

  
    switch (opcion) {
      case 1:
        controlarLuz(verde, true);
        break;
      case 2:
        controlarLuz(verde, false);
        break;
      case 3:
        controlarLuz(rojo, true); 
        break;
      case 4:
        controlarLuz(rojo, false); 
        break;
      case 5:
        controlarLuz(amarillo, true); 
        break;
      case 6:
        controlarLuz(amarillo, false); 
        break;
      case 7:
        encenderTodasLasLuces();
        break;
      case 8:
        apagarTodasLasLuces();
        break;
      case 9:
        modoIntermitente();
        break;
      default:
        Serial.println("Opción no válida");
        break;
    }
  }
}


void controlarLuz(int pin, bool encender) {
  digitalWrite(pin, encender ? HIGH : LOW);
}

void encenderTodasLasLuces() {
  digitalWrite(verde, HIGH);
  digitalWrite(rojo, HIGH);
  digitalWrite(amarillo, HIGH);
}

void apagarTodasLasLuces() {
  digitalWrite(verde, LOW);
  digitalWrite(rojo, LOW);
  digitalWrite(amarillo, LOW);
}


void modoIntermitente() {
  for (int i = 0; i < 5; i++) {
    encenderTodasLasLuces();
    delay(500);
    apagarTodasLasLuces();
    delay(500);
  }
}
