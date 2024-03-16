int ledRojo = 13;
int sensorTemperatura = A0;
int motor = 12;

void setup()
{
  pinMode(ledRojo, OUTPUT);
  pinMode(sensorTemperatura, INPUT);
  pinMode(motor, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int temperatura = (-40 + 0.488155 * (analogRead(sensorTemperatura) - 20));

  if (temperatura <= 10) {
    digitalWrite(ledRojo, HIGH);
    digitalWrite(motor, LOW);
    delay(500);
    digitalWrite(ledRojo, LOW);
    delay(500);
  }
  else if (temperatura >= 11 && temperatura <= 25) {
    digitalWrite(ledRojo, LOW);
    digitalWrite(motor, LOW);
  }
  else if (temperatura >= 26) {
    digitalWrite(ledRojo, HIGH);
    digitalWrite(motor, HIGH);
  }

  Serial.println(temperatura);
  delay(1000); 
}
