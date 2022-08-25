#define MOTOR 5
#define LED_INDICADOR_LIGADO 10
#define LED_INDICADOR_DESLIGADO 7
#define LED_INDICADOR_BOTAO_PRESSIONADO 8
#define INTERRUPTOR 2

bool estado_botao_pressionado = false;
bool estado_botao_liberado = false;
bool ligar = false;

void setup() {
  pinMode(MOTOR, OUTPUT);
  pinMode(LED_INDICADOR_LIGADO, OUTPUT);
  pinMode(LED_INDICADOR_DESLIGADO, OUTPUT);
  pinMode(LED_INDICADOR_BOTAO_PRESSIONADO, OUTPUT);
}

void loop() { 
  if (digitalRead(INTERRUPTOR) == HIGH) {
    estado_botao_pressionado = true;
    estado_botao_liberado = false;

    digitalWrite(LED_INDICADOR_DESLIGADO, LOW);
    digitalWrite(LED_INDICADOR_BOTAO_PRESSIONADO, HIGH);
    
  } else {
    estado_botao_liberado = true;

    digitalWrite(LED_INDICADOR_DESLIGADO, HIGH);
    digitalWrite(LED_INDICADOR_BOTAO_PRESSIONADO, LOW);
  }

  if (estado_botao_pressionado and estado_botao_liberado) {
    estado_botao_pressionado = false;
    estado_botao_liberado = false;
    
    ligar = !ligar;
  }

  if (ligar) {
    digitalWrite(LED_INDICADOR_DESLIGADO, LOW);
    digitalWrite(MOTOR, HIGH);
    
    piscar_led(0.1);
    
  } else
    digitalWrite(LED_INDICADOR_LIGADO, LOW);
    digitalWrite(MOTOR, LOW);
}

void piscar_led(float intervalo) {
  digitalWrite(LED_INDICADOR_LIGADO, HIGH);
  delay(intervalo * 1000);
  
  digitalWrite(LED_INDICADOR_LIGADO, LOW);
  delay(intervalo * 1000);
}
