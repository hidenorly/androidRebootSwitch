/* 
 Copyright (C) 2017 hidenorly

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#include <DigiKeyboard.h>

#define KEY_DELETE 76

#define GPO_LED_A 0
#define GPO_LED_B 1
#define GPI_BUTTON  2
#define POLLING_PERIOD 5
#define DEBOUNCED_COUNT (100/POLLING_PERIOD) // Detect push if button is pushed for 100msec continuously

void setup() {                
  // initialize the digital pin as an output.
  pinMode(GPO_LED_A, OUTPUT);
  pinMode(GPO_LED_B, OUTPUT);
  pinMode(GPI_BUTTON, INPUT_PULLUP);
}

void setLedStatus(int ledStatus) {
  digitalWrite(GPO_LED_A, ledStatus);
  digitalWrite(GPO_LED_B, ledStatus);
}

void loop() {
  static int prevStatus = true;
  static int count = 0;
  static bool flagSendKey = false;
  
  int curStatus = digitalRead(GPI_BUTTON);
  if( curStatus==prevStatus ) {
    if( curStatus==LOW ){
      count++;
      if( count>DEBOUNCED_COUNT ){
        count = DEBOUNCED_COUNT;
        if( !flagSendKey ){
          flagSendKey = true;
          setLedStatus(HIGH);
        }
      }
    }
  } else {
    prevStatus = curStatus;
    count = 0;
    if( (curStatus==HIGH) && flagSendKey ){
      DigiKeyboard.update();
      DigiKeyboard.sendKeyStroke(KEY_DELETE, MOD_ALT_LEFT | MOD_CONTROL_LEFT);
      flagSendKey = false;
      setLedStatus(LOW);
    }
  }
  delay(POLLING_PERIOD);
}
