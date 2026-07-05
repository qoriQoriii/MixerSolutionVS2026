// 1. Declarar la variable global
const int pinBomba = 7; 

void setup() {
  // Inicializar la comunicación serial a 9600 baudios
  Serial.begin(9600);
  
  // Configurar el pin como salida
  pinMode(pinBomba, OUTPUT);
  
  // Un mensaje de bienvenida para saber que todo está en orden
  Serial.println("Control de Bomba Listo. Envia '1' para encender y '0' para apagar.");
}

void loop() {
  // ¿Hay datos esperando en el puerto serial?
  if (Serial.available() > 0) {
    
    // Leer el carácter entrante
    char lectura = Serial.read();
    
    // Si envías un '1', se enciende la bomba
    if (lectura == '1') {
      digitalWrite(pinBomba, HIGH); // HIGH es lo mismo que 1
      Serial.println("Bomba: ENCENDIDA");
    } 
    // Si envías un '0', se apaga la bomba
    else if (lectura == '0') {
      digitalWrite(pinBomba, LOW);  // LOW es lo mismo que 0
      Serial.println("Bomba: APAGADA");
    }
  }
}