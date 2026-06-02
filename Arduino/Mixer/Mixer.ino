// ============================================================
//  Librerías
// ============================================================
#include <Servo.h>
#include <NewPing.h>

// ============================================================
//  Pines — Servomotores (PWM disponible en Uno: 3,5,6,9,10,11)

// ============================================================
const int PIN_SERVO_1 = 8;
const int PIN_SERVO_2 = 9;
const int PIN_SERVO_3 = 10;
const int PIN_SERVO_4 = 11;

// ============================================================
//  Pines — HC-SR04

// ============================================================
//                    TRIGGER       ECHO
const int TRIG_1 = A0; const int ECHO_1 = A1;   
const int TRIG_2 = A2; const int ECHO_2 = A3;   
const int TRIG_3 =  5; const int ECHO_3 =  6;   
const int TRIG_4 =  2; const int ECHO_4 =  3;   

#define MAX_DISTANCE 200

// ============================================================
//  Pines — Motor DC (L298N)

// ============================================================
const int MOTOR_IN1 = 12;   
const int MOTOR_IN2 =  7;

// ============================================================
//  Objetos
// ============================================================
Servo servo1, servo2, servo3, servo4;

NewPing sonar1(TRIG_1, ECHO_1, MAX_DISTANCE);
NewPing sonar2(TRIG_2, ECHO_2, MAX_DISTANCE);
NewPing sonar3(TRIG_3, ECHO_3, MAX_DISTANCE);
NewPing sonar4(TRIG_4, ECHO_4, MAX_DISTANCE);

// ============================================================
//  SETUP
// ============================================================
void setup() {
  Serial.begin(9600);

  // Servomotores
  servo1.attach(PIN_SERVO_1);
  servo2.attach(PIN_SERVO_2);
  servo3.attach(PIN_SERVO_3);
  servo4.attach(PIN_SERVO_4);
  moverServos(90, 90, 90, 90);   // posición inicial: centro

  // Motor DC
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  detenerMotor();

  Serial.println("Sistema listo.");
}

// ============================================================
//  LOOP — prueba básica de todos los componentes
// ============================================================
void loop() {
  // Leer y mostrar distancias
  int d1 = leerDistancia(1);
  int d2 = leerDistancia(2);
  int d3 = leerDistancia(3);
  int d4 = leerDistancia(4);

  Serial.print("D1:"); Serial.print(d1);
  Serial.print("  D2:"); Serial.print(d2);
  Serial.print("  D3:"); Serial.print(d3);
  Serial.print("  D4:"); Serial.println(d4);

  // Mover servos a posición de prueba y volver al centro
  moverServos(180, 180, 180, 180);
  delay(1000);
  moverServos(0, 0, 0, 0);
  delay(500);

  // Prueba motor
  avanzarMotor();
  delay(1000);
  retrocederMotor();
  delay(1000);
  detenerMotor();

  delay(500);





  
}

// ============================================================
//  FUNCIONES — Servomotores
// ============================================================
void moverServo(int numero, int angulo) {
  angulo = constrain(angulo, 0, 180);
  switch (numero) {
    case 1: servo1.write(angulo); break;
    case 2: servo2.write(angulo); break;
    case 3: servo3.write(angulo); break;
    case 4: servo4.write(angulo); break;
    default: Serial.println("Servo invalido."); break;
  }
}

void moverServos(int a1, int a2, int a3, int a4) {
  moverServo(1, a1);
  moverServo(2, a2);
  moverServo(3, a3);
  moverServo(4, a4);
}

// ============================================================
//  FUNCIONES — Sensores de distancia
// ============================================================
int leerDistancia(int numero) {
  unsigned int d = 0;
  switch (numero) {
    case 1: d = sonar1.ping_cm(); break;
    case 2: d = sonar2.ping_cm(); break;
    case 3: d = sonar3.ping_cm(); break;
    case 4: d = sonar4.ping_cm(); break;
    default: return -1;
  }
  return (d == 0) ? -1 : (int)d;
}

void leerTodasDistancias(int destino[]) {
  for (int i = 0; i < 4; i++) {
    destino[i] = leerDistancia(i + 1);
  }
}

// ============================================================
//  FUNCIONES — Motor DC
// ============================================================
void avanzarMotor() {
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);
}

void retrocederMotor() {
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, HIGH);
}

void detenerMotor() {
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);
}

