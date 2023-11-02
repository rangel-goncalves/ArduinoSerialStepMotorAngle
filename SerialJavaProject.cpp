#include <AccelStepperWithDistanceAndAngle.h>
#include <Servo.h>

Servo servoVerti;

AccelStepperWithDistanceAndAngle stepper = AccelStepperWithDistanceAndAngle(1, 2, 3);
float valor = 0.0;
float valor1 = 0.0;
int  i = 0 ;
float aux;
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  stepper.setStepsPerRotation(200);
  stepper.setMicroStep(4);
  stepper.setAnglePerRotation(360);
  stepper.setDistancePerRotation(100);
  stepper.setMaxSpeed(10000);
  stepper.setSpeed(200);
  stepper.setCurrentPosition(0.0);
  stepper.setAcceleration(1000);
  Serial.print(stepper.getCurrentVmms());
  servoVerti.attach(9); 
}
 
void loop() {
  if( i == 0 ){
    if (Serial.available() > 0) {
      String data = Serial.readStringUntil('\n'); // Lê a linha da porta serial até o caractere '\n'
      int commaIndex = data.indexOf(','); // Encontra o índice da primeira vírgula
      digitalWrite(LED_BUILTIN, HIGH);
      if (commaIndex != -1) {
        String valorStr = data.substring(0, 7); // Extrai a primeira parte até a vírgula
        String valor1Str = data.substring(commaIndex + 1); // Extrai a segunda parte após a vírgula
        valor = valorStr.toFloat(); // Converte a primeira parte em float
        valor1 = valor1Str.toFloat(); // Converte a segunda parte em float
        i = 1;
      }
    }
  }else{
    stepper.setSpeed(200);
    stepper.moveToDistance(valor);
    if(valor1 = 1.148)
      //servoVerti.write(valor1);
      digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    if(stepper.getCurrentPositionAngle() == valor)
      i=0;
  } 

}
