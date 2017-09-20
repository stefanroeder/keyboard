#include <FlexiTimer2.h>
#include "types.h"

//linear velocity
const int linVelocityValue[128] =
{ 127, 126, 125, 124, 123, 122, 121, 120, 119, 118,

  117, 116, 115, 114, 113, 112, 111, 110, 109, 108,
  107, 106, 105, 104, 103, 102, 101, 100, 99, 98,

  97, 96, 95, 94, 93, 92, 91, 90, 89, 88,
  87, 86, 85, 84, 83, 82, 81, 80, 79, 78,

  77, 76, 75, 74, 73, 72, 71, 70, 69, 68,
  67, 66, 65, 64, 63, 62, 61, 60, 59, 58,

  57, 56, 55, 54, 53, 52, 51, 50, 49, 48,
  47, 46, 45, 44, 43, 42, 41, 40, 39, 38,

  37, 36, 35, 34, 33, 32, 31, 30, 29, 28,
  27, 26, 25, 24, 23, 22, 21, 20, 19, 18,

  17, 16, 15, 14, 13, 12, 11, 10, 9, 8,
  7, 6, 5, 4, 3, 2, 1, 1
};
//logarithmic velocity
const int lVelocityValue[128] =
{ 127, 126, 126, 125, 125, 124, 124, 123, 123, 122,
  122, 121, 121, 120, 120, 119, 119, 118, 118, 117,

  117, 116, 116, 115, 115, 114, 114, 113, 113, 112,
  112, 111, 111, 110, 110, 109, 109, 108, 108, 107,

  107, 106, 106, 105, 105, 104, 104, 103, 103, 102,
  102, 101, 101, 100, 100, 99, 99, 98, 97, 97, 96,

  95, 95, 94, 93, 92, 91, 90, 89, 87, 86, 84, 83,
  81, 80, 78, 77, 75, 74, 72, 71, 69, 68, 66, 65,

  63, 62, 60, 59, 57, 56, 54, 53, 51, 50, 48, 47,
  45, 44, 42, 41, 39, 38, 36, 35, 33, 32, 30, 29,

  27, 26, 24, 23, 21, 20, 18, 17, 15, 14, 12, 11,
  9, 8, 6, 5, 3, 2, 1
};
//exponential velocity
const int expVelocityValue[128] =
{ 127, 125, 124, 122, 121, 119, 118, 116, 115, 113,
  112, 110, 109, 107, 106, 104, 103, 101, 100, 98,

  97, 95, 94, 92, 91, 89, 88, 86, 85, 83,
  82, 80, 79, 77, 76, 74, 73, 71, 70, 68,

  67, 65, 64, 62, 61, 59, 58, 56, 55, 53,
  52, 50, 49, 47, 46, 44, 43, 41, 40, 38,

  37, 36, 35, 34, 33, 32, 32, 31, 30, 30,
  29, 28, 28, 27, 27, 26, 26, 25, 25, 24,

  24, 23, 23, 22, 22, 21, 21, 20, 20, 19,
  19, 18, 18, 17, 17, 16, 16, 15, 15, 14,

  14, 13, 13, 12, 12, 11, 11, 10, 10, 9,
  9, 8, 8, 7, 7, 6, 6, 5, 5, 4,
  4, 3, 3, 2, 2, 1, 1, 1
};
//s-type velocity
const int sVelocityValue[128] =
{ 127, 127, 127, 126, 126, 126, 126, 126, 125, 125,
  125, 125, 125, 124, 124, 124, 124, 124, 123, 123,

  123, 123, 123, 122, 122, 122, 122, 122, 121, 121,
  121, 121, 121, 120, 120, 119, 119, 118, 118, 117,

  116, 115, 113, 111, 109, 106, 104, 102, 100, 97,
  95, 93, 90, 88, 86, 83, 81, 79, 77, 74,

  72, 70, 67, 65, 63, 60, 58, 56, 54, 51,
  49, 47, 44, 42, 40, 37, 35, 33, 31, 28,

  26, 24, 21, 19, 17, 14, 13, 11, 10, 9,
  9, 8, 8, 7, 7, 6, 6, 6, 6, 6,

  5, 5, 5, 5, 5, 4, 4, 4, 4, 4,
  3, 3, 3, 3, 3, 2, 2, 2, 2,

  1, 1, 1, 1, 1, 1, 1, 1, 1
};
//n-type velocity
const int nVelocityValue[128] =
{ 127, 126, 125, 123, 122, 121, 119, 118, 116, 115,
  113, 111, 110, 108, 107, 105, 104, 102, 101, 99,

  97, 95, 93, 92, 90, 87, 85, 83, 81, 80,
  78, 76, 74, 73, 71, 70, 69, 68, 67, 67,

  67, 66, 66, 65, 65, 64, 64, 64, 63, 63,
  63, 63, 62, 62, 62, 62, 61, 60, 60, 60,

  60, 59, 59, 59, 58, 58, 57, 57, 57, 57,
  56, 56, 56, 55, 55, 55, 54, 54, 54, 53,

  53, 53, 52, 52, 51, 51, 51, 50, 50, 49,
  49, 48, 48, 47, 46, 46, 45, 44, 43, 43,

  42, 41, 40, 39, 38, 37, 36, 35, 34, 33,
  31, 30, 29, 28, 27, 26, 24, 23, 21, 20,

  18, 17, 15, 14, 12, 11, 10, 9
};

//exponential2 velocity
const int exp2VelocityValue[128] =
{ 127, 124, 121, 118, 115, 112, 109, 106,
  103, 100, 97, 94, 91, 88, 85, 82,

  79, 76, 73, 70, 67, 64, 61, 58,
  55, 54, 53, 52, 51, 50, 49, 49,

  48, 48, 47, 47, 46, 46, 45, 45,
  44, 44, 43, 43, 42, 42, 41, 41,

  40, 40, 39, 39, 38, 38, 37, 37,

  36, 36, 35, 35, 34, 34, 33, 33,
  32, 32, 31, 31, 30, 30, 29, 29,

  28, 28, 27, 27, 26, 26, 25, 25,
  24, 24, 23, 23, 22, 22, 21, 21,

  20, 20, 19, 19, 18, 18, 17, 17,
  16, 16, 15, 15, 14, 14, 13, 13,

  12, 12, 11, 11, 10, 10, 9, 9,
  8, 8, 7, 7, 6, 6, 5, 5,

  4, 4, 3, 3, 2, 2, 1, 1
};

//exponential3 velocity
const int exp3VelocityValue[128] =
{ 127, 124, 121, 118, 115, 112, 109, 106,
  103, 100, 97, 94, 91, 88, 85, 82,

  79, 76, 73, 70, 67, 64, 61, 58,
  55, 52, 49, 46, 43, 40, 37, 35,

  34, 33, 32, 32, 31, 31, 30, 30,
  30, 29, 29, 29, 28, 28, 28, 27,

  27, 27, 26, 26, 26, 25, 25, 25,
  24, 24, 24, 23, 23, 23, 22, 22,

  22, 21, 21, 21, 20, 20, 20, 19,
  19, 19, 18, 18, 18, 17, 17, 17,

  16, 16, 16, 15, 15, 15, 14, 14,
  14, 13, 13, 13, 12, 12, 12, 11,

  11, 11, 10, 10, 10, 9, 9, 9,
  8, 8, 8, 7, 7, 7, 6, 6,

  6, 5, 5, 5, 4, 4, 4, 3,
  3, 3, 2, 2, 2, 1, 1, 1
};

//exponential4 velocity
const int exp4VelocityValue[128] =
{ 127, 123, 119, 115, 111, 107, 103, 99,
  95, 91, 87, 83, 79, 75, 71, 67,

  63, 59, 55, 51, 47, 43, 39, 37,
  36, 35, 34, 33, 33, 33, 32, 32,

  32, 31, 31, 31, 31, 31, 30, 30,
  30, 29, 29, 29, 28, 28, 28, 27,

  27, 27, 26, 26, 26, 25, 25, 25,
  24, 24, 24, 23, 23, 23, 22, 22,

  22, 21, 21, 21, 20, 20, 20, 19,
  19, 19, 18, 18, 18, 17, 17, 17,

  16, 16, 16, 15, 15, 15, 14, 14,
  14, 13, 13, 13, 12, 12, 12, 11,

  11, 11, 10, 10, 10, 9, 9, 9,
  8, 8, 8, 7, 7, 7, 6, 6,

  6, 5, 5, 5, 4, 4, 4, 3,
  3, 3, 2, 2, 2, 1, 1, 1
};

#define MIDIChannel 1
#define VelocityFactor 6
#define KeyBounceThreshold 10
#define NUM_BANKS 11
const int ledPin = LED_BUILTIN; //Teensy++ 2.0 has the LED on pin 6
const byte LEDmask = B10111111;
const byte D0mask = B11111110;
const byte D1mask = B11111101;
const byte D2mask = B11111011;
const byte D3mask = B11110111;
const byte D4mask = B11101111;

key_t keys[88];

// For scanning banks
bank_t banks[NUM_BANKS];
bank_t prev_banks[NUM_BANKS];

static byte VOLUME;
static unsigned int TimeOutCounter = 0;
static boolean ANY_KEY_PRESSED = false;
static boolean ANY_PEDAL_PRESSED = false;

void setup() {
  //  long startmicros;
  //  long endmicros;
  //  startmicros = micros();
  //  scan();
  //  increment();
  //  footpedal();
  //  timeout();
  //  endmicros = micros();

  //  Serial.begin(115200);
  //  Serial.print ("Runtime scan(), increment(), footpedal() in micros: ");
  //  Serial.println (endmicros-startmicros);
  DDRD = 0b01011111; // Set D0-D4, D6 as outputs, D5, D7 as input
  PORTD = 0b10100000; // Enable pull up resistors
  DDRC = 0b00000000; // Set C0-C7 as inputs
  PORTC = 0b11111111; // Enable pull up resistors

  DDRF = DDRF | 0b00111111;
  PORTF = PORTF | 0b11000000;

  // Init array
  memset(banks, 0xff, sizeof(prev_banks));
  VOLUME = 16;
  // Init keys
  for ( int key = 0; key < 88; key++) {
    keys[key].midi_note = 21 + key;
    keys[key].t = 0;
    keys[key].state = KEY_IS_UP;
    keys[key].bounce_bottom = false;
    keys[key].bounce_top = false;
  }
  FlexiTimer2::set(16, 100, timeout); // 16->4096µs=0.4096ms period
  FlexiTimer2::start();
}

void timeout() {
  scan();
  increment();
  if (TimeOutCounter % 16 == 0) {
    footpedal();
  }
  if (ANY_KEY_PRESSED == false && ANY_PEDAL_PRESSED == false && TimeOutCounter % 1024 == 0) {
    usbMIDI.sendControlChange(123, 0, MIDIChannel); // send all notes off
  }
  TimeOutCounter++;
}

void LEDOn() {
  PORTD = (PORTD & LEDmask) | (B01000000);
}

void LEDOff() {
  PORTD = (PORTD & LEDmask) | (B00000000);
}

void trigger(key_t *key, event_t event) {
  byte velocity;
  if (event == KEY_PRESSED) {
    key->state = KEY_IS_GOING_DOWN;
  } else if (event == KEY_DOWN) {
    if (key->state == KEY_IS_GOING_UP) { //KEY_IS_GOING_UP prior to KEY_DWON event means key bounces or repeated key press
      key->bounce_bottom = true;
    }
    if (key->bounce_bottom == true) { // in this case we can't measure key travel time, so use a constant value
      key->t = 96 / VelocityFactor; 
    }
    key->state = KEY_IS_DOWN;
    if (key->t * VelocityFactor > 127) {
      key->t = 127;
    }
    else {
      key->t = key->t * VelocityFactor;
    }
    if (key->t <= 127 && key->t >= 0) {
      velocity = exp4VelocityValue[key->t]; //choose your own velocity curve here
    }
    else {
      velocity = 4;
    }
    if (velocity < 0) {
      velocity = 0;
    }
    if (velocity > 127) {
      velocity = 63;
    }
    usbMIDI.sendControlChange(88, key->t & B01111111, MIDIChannel); //thats only for debugging purposes
    usbMIDI.sendNoteOn(key->midi_note, velocity, MIDIChannel);
    LEDOn();
    key->t = 0;
    key->bounce_bottom = false;
  } else if (event == KEY_RELEASED) {
    key->t = 0;
    key->state = KEY_IS_GOING_UP;
  } else if (event == KEY_UP) {
    if (key->state == KEY_IS_GOING_DOWN) { //KEY_IS_GOING_UP prior to KEY_DWON event means key bounces or repeated key press
      if (key->t >= KeyBounceThreshold) {
        key->bounce_top = false;
        key->state = KEY_IS_UP;
      }
      else {
        key->bounce_top = true;
      }
    }
    else {
      key->bounce_bottom = false;
      key->bounce_top = false;
      key->state = KEY_IS_UP;
    }
    if (key->bounce_top == false) { //Velocity für NoteOff
      velocity = exp4VelocityValue[key->t]; //choose your own velocity curve here
      if (velocity < 0) {
        velocity = 0;
      }
      if (velocity > 127) {
        velocity = 63;
      }
      usbMIDI.sendControlChange(88, key->t & B01111111, MIDIChannel); //thats only for debugging purposes
      usbMIDI.sendNoteOff(key->midi_note, velocity, MIDIChannel);
      LEDOff();
      key->t = 0;
    }
  }
}

void increment() {
  // Advance timers
  byte key;
  ANY_KEY_PRESSED = false;
  for (key = 0; key < 88; key++) {
    state_t state = keys[key].state;
    if (state == KEY_IS_GOING_UP || state == KEY_IS_GOING_DOWN) {
      if (keys[key].t <=  127) {
        keys[key].t++;
      }
      if (keys[key].bounce_top == true) {
        if (keys[key].t >= KeyBounceThreshold) {
          keys[key].bounce_top = false;
          state = KEY_IS_UP;
        }
      }
    }
    else if (state == KEY_IS_DOWN) {
      ANY_KEY_PRESSED = true;
      keys[key].t = 0;
    }
    else if (state == KEY_IS_UP) {
      keys[key].t = 0;
    }
  }
}

void footpedal() {
  static int prev_val_volume = 64;
  int val_volume;

  static int prev_val_sustain = 0;
  int val_sustain;
  static int prev_val_soft = 0;
  int val_soft;
  static int prev_val_sostenuto = 0;
  int val_sostenuto;
  int send_val;
  ANY_PEDAL_PRESSED = false;
  val_volume = VOLUME;
  val_volume = analogRead(A6) / 8; //volume as analog input
  if ((val_volume != prev_val_volume) || (TimeOutCounter % 1024 == 0)) {
    usbMIDI.sendControlChange(7, (val_volume) * 4, MIDIChannel);
    prev_val_volume = val_volume;
  }
  val_sustain = analogRead(A7) / 8; //right pedal as analog input
  if (val_sustain > 10) {
    ANY_PEDAL_PRESSED = true;
  }
  if (val_sustain != prev_val_sustain) {
    usbMIDI.sendControlChange(64, (val_sustain) * 4, MIDIChannel);
    prev_val_sustain = val_sustain;
    if (val_sustain * 4 > 64) {
      LEDOn();
      ANY_PEDAL_PRESSED = true;
    }
    else {
      LEDOff();
    }
  }
  val_sostenuto = PIND & 0b00100000; //middle pedal
  if (val_sostenuto == 0) {
    ANY_PEDAL_PRESSED = true;
  }
  if (val_sostenuto != prev_val_sostenuto) {
    if (val_sostenuto == 0) {
      send_val = 127;
    }
    else {
      send_val = 0;
    }
    usbMIDI.sendControlChange(66, send_val, MIDIChannel);
    prev_val_sostenuto = val_sostenuto;
    if (send_val > 64) {
      LEDOn();
      ANY_PEDAL_PRESSED = true;
    }
    else {
      LEDOff();
    }
  }
  val_soft = PIND & 0b10000000; //left pedal
  if (val_soft == 0) {
    ANY_PEDAL_PRESSED = true;
  }
  if (val_soft != prev_val_soft) {
    if (val_soft == 0) {
      send_val = 127;
    }
    else {
      send_val = 0;
    }
    usbMIDI.sendControlChange(67, send_val, MIDIChannel);
    prev_val_soft = val_soft;
    if (send_val > 64) {
      LEDOn();
      ANY_PEDAL_PRESSED = true;
    }
    else {
      LEDOff();
    }
  }
}

void scan() {
  const byte KeyMatrixMask = B11100000;
  byte diff;
  byte bank;
  byte key;
  // Scan and store
  for (bank = 0; bank < NUM_BANKS; bank++) {
    prev_banks[bank] = banks[bank]; // Store previous state so we can look for changes
    PORTD = (PORTD & KeyMatrixMask) | (bank * 2); // Selects bottom row
    delayMicroseconds(10); // time for TTL to switch
    banks[bank].bottom = PINC;
    PORTD = (PORTD & KeyMatrixMask) | (bank * 2 + 1); // Selects top row
    delayMicroseconds(10); // time for TTL to switch
    banks[bank].top = PINC;
  }

  for (bank = 0; bank < NUM_BANKS; bank++) {
    // Check top switches and fire events
    diff = banks[bank].top ^ prev_banks[bank].top;
    if (diff) {
      for (key = 0; key < 8; key++) {
        if (bitRead(diff, key)) {
          event_t event = bitRead(banks[bank].top, key) ? KEY_UP : KEY_PRESSED;
          trigger(&keys[bank * 8 + key], event);
        }
      }
    }
    // Check bottom switches and fire events
    diff = banks[bank].bottom ^ prev_banks[bank].bottom;
    if (diff) {
      for (key = 0; key < 8; key++) {
        if (bitRead(diff, key)) {
          event_t event = bitRead(banks[bank].bottom, key) ? KEY_RELEASED : KEY_DOWN;
          trigger(&keys[bank * 8 + key], event);
        }
      }
    }
  }
}

void loop() {
} // Idle

