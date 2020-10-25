// Ejercicio 1 Práctica 2 TC - Alejandro Fernández Trigo

// Variables globales
int estado = 0;
int estadoAnterior = 0;
int pulsos = 0;

// Función de inicialización
void setup() {

  // Inicializo los puertos 3, 4 y 5 como salida y el 2 como entrada
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

}

// Función de ejecución
void loop() {

  // Leo el estado del pulsador
  estado = digitalRead(2);

  // Si se ha pulsado, aumento el valor de pulsos
  if (estado == HIGH && estadoAnterior == LOW) {

    pulsos = pulsos + 1;
    delay(20);
    
  }

  // Guardo el valor en estadoAnterior ANTES del bucle de iluminación
  estadoAnterior = estado;
  
  // Bucle de iluminación:
  if (pulsos == 1) {
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(3, LOW);
  }

  if (pulsos == 2) {
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);   
  }

  if (pulsos == 3) {
    digitalWrite(5, HIGH);    
  } else {
    digitalWrite(5, LOW);    
  }

  if (pulsos > 3) {
    pulsos = 1;    
  }

}
