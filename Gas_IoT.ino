const int PIN_AOUT = 34;
const int PIN_DOUT = 35;

const int LED_VERMELHO = 25;
const int LED_AMARELO  = 26;
const int LED_VERDE    = 27;

const int LIMITE_AMARELO = 2050;
const int LIMITE_VERMELHO = 2300;

void setup() {
  Serial.begin(115200);

  pinMode(PIN_DOUT, INPUT);

  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);

  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERDE, HIGH);

  analogSetPinAttenuation(PIN_AOUT, ADC_11db);

  Serial.println();
  Serial.println("FC-22 iniciado.");
  Serial.println("Aguarde o aquecimento do sensor antes de considerar as leituras.");
}

void loop() {
  int valorAnalogico = analogRead(PIN_AOUT);
  int valorDigital = digitalRead(PIN_DOUT);

  Serial.print("AOUT: ");
  Serial.print(valorAnalogico);
  Serial.print(" | DOUT: ");
  Serial.println(valorDigital);


  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERMELHO, LOW);

  if (valorAnalogico >= LIMITE_VERMELHO) {
    digitalWrite(LED_VERMELHO, HIGH);
  }
  else if (valorAnalogico >= LIMITE_AMARELO) {
    digitalWrite(LED_AMARELO, HIGH);
  }
  else {
    digitalWrite(LED_VERDE, HIGH);
  }

  if (valorDigital == LOW) {
    Serial.println("DOUT: LIMIAR DIGITAL ATINGIDO");
  }

  delay(500);
}