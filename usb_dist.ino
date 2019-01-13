#include "IRremote.h"
#include "HID-Project.h"

//Declaration
const char DIN_RECEPTEUR_INFRAROUGE = 2;

IRrecv ir_receiver (DIN_RECEPTEUR_INFRAROUGE);
decode_results  message;
//void principaux
void setup()
{
  Keyboard.begin();
  Consumer.begin();
  Serial.begin(9600);
  ir_receiver.enableIRIn();
  ir_receiver.blink13(true);
}

void loop() {

  if (ir_receiver.decode(&message))
  {
    Serial.println(message.value, HEX);
    delay(100);
  }

  delay(1);

  if (message.value == 0x20DF718E) {
    Consumer.write(MEDIA_NEXT);
  }

  if (message.value == 0x20DFF10E) {
    Consumer.write(MEDIA_PREVIOUS);
  }

  if (message.value == 0x20DF8D72) {
    Consumer.write(MEDIA_STOP);
  }

  if (message.value == 0x20DF0DF2) {
    Consumer.write(MEDIA_PLAY_PAUSE);
  }

  if (message.value == 0x20DF906F) {
    Consumer.write(MEDIA_VOLUME_MUTE);
  }

  if (message.value == 0x20DF40BF) {
    Consumer.write(MEDIA_VOLUME_UP);
  }

  if (message.value == 0x20DFC03F) {
    Consumer.write(MEDIA_VOLUME_DOWN);
  }

  ir_receiver.resume();
}
