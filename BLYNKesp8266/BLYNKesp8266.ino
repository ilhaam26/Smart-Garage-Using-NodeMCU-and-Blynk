
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "blynk_template_id"
#define BLYNK_DEVICE_NAME "blynk_device_name"
#define BLYNK_AUTH_TOKEN "auth_token"

#define BLYNK_WIFI_SSID "your_wifi_ssid"
#define BLYNK_WIFI_PASS "your_wifi_pass"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"
#include <Servo.h>

static const int servoPin1 = 16;
static const int irPin = 14;

Servo myservo1;                        

void setup()
{
  Serial.begin(115200);
  delay(100);
  pinMode(13, OUTPUT);
  myservo1.attach(servoPin1);
  pinMode(irPin, INPUT);
  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();

  int val = digitalRead(irPin);

  if (val == 0){
    Blynk.virtualWrite(V0, 0);
     Blynk.virtualWrite(V2, 1);
  } else if (val == 1){
    Blynk.virtualWrite(V0, 1);
     Blynk.virtualWrite(V2, 0);
  }
}

BLYNK_WRITE(V1){
  if (param.asInt() == HIGH) {
    digitalWrite(13, HIGH);
      myservo1.write(120);
    } else {
      digitalWrite(13, LOW);
        myservo1.write(0);
    }
  }
