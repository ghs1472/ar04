/*
 예제 9.1
 피에조 부저를 이용한 소리 출력
*/

int buzzerPin = 9;
int songLength = 16;
const int Pin1 = 2;
const int Pin2 = 3;
const int Pin3 = 4;
int count = 0;
void setup() 
{
  // 부저핀을 출력으로 설정한다
  pinMode(buzzerPin, OUTPUT);
  pinMode(Pin1, INPUT_PULLUP);
  pinMode(Pin2, INPUT_PULLUP);
  pinMode(Pin3, INPUT_PULLUP);
}


void loop() 
{
  // 부저 출력 시간에 사용할 변수 설정
  int duration;
  int put1 = digitalRead(Pin1);
  int put2 = digitalRead(Pin2);
  int put3 = digitalRead(Pin3); 
  
  if(put1 == LOW)
  {
    tone(buzzerPin, 262, duration);
     delay(duration);
     }
     else if(put1 == HIGH)
     {
      pinMode(buzzerPin, INPUT);
     }
     if(put2 == LOW)
     {
     tone(buzzerPin, 294, duration);
     delay(duration);
     }
     else if(put2 == HIGH)
     {
      pinMode(buzzerPin, INPUT);
     }
     if(put3 == LOW)
     {
     tone(buzzerPin, 330, duration);
     delay(duration);
     }
     else if(put3 == HIGH)
     {
      pinMode(buzzerPin, INPUT);
     }
      
  
}
