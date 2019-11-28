/*
 예제 7.2
 서보모터 구동
*/
 
// 서보모터 라이브러리 불러오기
#include <Servo.h> 

// 서보모터 이름 설정
Servo motor1; 

// 서보 모터 신호핀 설정
int servoMotorPin = 9;

// 포텐쇼미터 핀 설정
int potentioMeterPin = 0;

// 모터 각도 변수 설정
int motorAngle;
int motorAngleOld;

int cw_sw = 2;
int ccw_sw = 3;

boolean cwsw = false;
boolean ccwsw = false;

void setup() {
  
  // 서보모터 설정. 0.6ms 부터 2.4ms 범위로 설정
  motor1.attach(servoMotorPin,600,2400);

  pinMode(cw_sw, INPUT_PULLUP);
  pinMode(ccw_sw, INPUT_PULLUP);

  motor1.write(90);
  // 시리얼 통신 설정  
  Serial.begin(9600);
}

void loop(){
  // 포텐쇼미터 값을 읽어옴
  int potentioMeter = analogRead(potentioMeterPin);

  // 포텐쇼미터 값을 모터 각도로 변환한다
  motorAngle = map(potentioMeter,0,1023,0,180);

  // 모터에 각도값을 전달한다
  motor1.write(motorAngle);

  // 이전각도와 현재 각도가 같지 않으면 시리얼 모니터에 각도를 출력한다.  
  if(motorAngle != motorAngleOld){
    Serial.print("Servo Motor Angle is: ");
    Serial.println(motorAngle);
  }

  // 현재의 모터 각도를 저장한다.
  motorAngleOld = motorAngle;
  
  delay(20);

  if(digitalRead(cw_sw)==LOW) {
    cwsw = true;
    ccwsw = false;
  }
  else if(digitalRead(ccw_sw)==LOW) {
    cwsw = false;
    ccwsw = true;
  }

  if(cwsw == true) {
    Serial.print("CW Motor");
    motor1.write(180);
  }
  else if(ccwsw == true) {
    Serial.print("CCW Motor");
    motor1.write(0);
  }
}
