/*
 예제 3.2
 I2C를 이용한 LCD 출력
*/

const int ledPin = 13;

int blinkNumber = 0;
// I2C 통신 라이브러리 설정
#include <Wire.h>
// I2C LCD 라리브러리 설정
#include <LiquidCrystal_I2C.h>

// LCD I2C address 설정 PCF8574:0x27, PCF8574A:0x3F
LiquidCrystal_I2C lcd(0x27,16,2);  // LCD address:0x27, 16X2 LCD, 0x3F

void setup()
{
  // 9600 bps로 시리얼 통신 설정
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  
  lcd.init(); // LCD 설정
  lcd.clear();      // LCD를 모두 지운다.
  lcd.backlight();  // 백라이트를 켠다.  
  // Arduino LCD, Welcome 표시  
}

void loop()
{
  // 시리얼 통신 수신 값이 있을 때
  if (Serial.available()) {	
    delay(100);
    // 모두 삭제
    lcd.clear();
     // 커서를 좌측 상단으로
    lcd.setCursor(0,0);
    // "Message from PC" 출력
   lcd.print("Enter your number: ");
    // 커서를 두 번째 줄로
    lcd.setCursor(0,1);

    // LCD에 PC에서 전송된 데이터를 출력
  }

  if(Serial.available()){
    char val = Serial.read();

    if(isDigit(val)){
      blinkNumber = (val - '0');
    }
  }
  if (blinkNumber != 0) {
    lcd.setCursor(0,1);
    lcd.print(blinkNumber);
  }
  for(int i = 0; i < blinkNumber; i++) {

    lcd.noBacklight();
    delay(250);
    lcd.backlight();
    delay(250);
  }

  blinkNumber = 0;
}
