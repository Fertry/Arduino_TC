// Ejercicio 2 Práctica 2 TC - Alejandro Fernández Trigo

// Variables globales
int pot = A0;
int potadc = 0;

// Función de inicialización
void setup() {

  // Inicializo los puertos 2, 3 y 4 como salida para los leds
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

}

// Función de ejecución
void loop() {

  // Leo el valor del potenciómetro y lo muestro en pantalla
  // Lo convierto sobre 100 y aplico un retraso de 200ms
  potadc = analogRead(pot) / 10.0;
  Serial.print("Valor: ");
  Serial.println(potadc);
  delay(200);

  // Bucle de iluminación
  // Si la potencia es menor a 10, enciendo el led rojo y viceversa
  if (potadc < 10) {
    
    digitalWrite(4, HIGH);
    
  } else {

    digitalWrite(4, LOW);
    
  }

  // Si la potencia está entre 10 y 30, enciendo el led azul y viceversa
  if (potadc >= 10 && potadc < 30) {

    digitalWrite(3, HIGH);
    
  } else {

    digitalWrite(3, LOW);
    
  }

  // Si la potencia es mayor a 30, enciendo el led verde y viceversa
  if (potadc >= 30) {

    digitalWrite(2, HIGH);

  } else {

    digitalWrite(2, LOW);
    
  }

}
