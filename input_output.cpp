#include <stdlib.h>
#include <string>
#include <iostream>
#include <wiringPi.h>

#define OUTPUT_PIN 4 // GPIO.4, pin 16
#define LED_PIN 30 // status LED
#define INPUT_PIN 1 // GPIO.1, pin 12
#define DOT_LENGTH 100 // 100 ms

using namespace std;

char decodeMorse(string s) {
  const string morse("EISHVUF*ARL*WPJTNDBXKCYMGZQO");
  int p = -1;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '-') p += 1 << (4 - i);
    else p++;
  }
  return morse[p];
}

void switchChanged() {
  static string buffer;
  static unsigned int previousTime = 0, currentTime, timePassed;
  currentTime = millis();
  if (previousTime == 0) { // first pulse
    previousTime = currentTime;
    return;
  }
  timePassed = currentTime - previousTime;
  previousTime = currentTime;
  if (digitalRead(INPUT_PIN) == LOW) { // end of pulse
    if (timePassed > 2 * DOT_LENGTH) { // long pulse, dash received

      // TO DO

    }
    else { // short pulse, dot received
      
      // TO DO

    }
  } else { // start of pulse
    if (timePassed > 2 * DOT_LENGTH) { // short pause, letter done

      // TO DO

    }
    if (timePassed > 6 * DOT_LENGTH) { // long pause, word done

      // TO DO

    }
  }
}

void wait(int n) {
  delay(n * DOT_LENGTH);
}

void pulse(int dots) {
  digitalWrite(OUTPUT_PIN, HIGH);

      // TO DO

  wait(1); // wait one dot after every pulse
}

void dot() {
  pulse(1);
}

void dash() {
  pulse(3);
}

void sendMorse(char character) {
  switch (character) {
    case 'A':
      dot();
      dash();
      break;
    case 'B':
      dash();
      dot();
      dot();
      dot();
      break;
    case 'C':
      dash();
      dot();
      dash();
      dot();
      break;
    case 'D':
      dash();
      dot();
      dot();
      break;
    case 'E':
      dot();
      break;
    case 'F':
      dot();
      dot();
      dash();
      dot();
      break;
    case 'G':
      dash();
      dash();
      dot();
      break;
    case 'H':
      dot();
      dot();
      dot();
      dot();
      break;
    case 'I':
      dot();
      dot();
      break;
    case 'J':
      dot();
      dash();
      dash();
      dash();
      break;
    case 'K':
      dash();
      dot();
      dash();
      break;
    case 'L':
      dot();
      dash();
      dot();
      dot();
      break;
    case 'M':
      dash();
      dash();
      break;
    case 'N':
      dash();
      dot();
      break;
    case 'O':
      dash();
      dash();
      dash();
      break;
    case 'P':
      dot();
      dash();
      dash();
      dot();
      break;
    case 'Q':
      dash();
      dash();
      dot();
      dash();
      break;
    case 'R':
      dot();
      dash();
      dot();
      break;
    case 'S':
      dot();
      dot();
      dot();
      break;
    case 'T':
      dash();
      break;
    case 'U':
      dot();
      dot();
      dash();
      break;
    case 'V':
      dot();
      dot();
      dot();
      dash();
      break;
    case 'W':
      dot();
      dash();
      dash();
      break;
    case 'X':
      dash();
      dot();
      dot();
      dash();
      break;
    case 'Y':
      dash();
      dot();
      dash();
      dash();
      break;
    case 'Z':
      dash();
      dash();
      dot();
      dot();
      break;
    default:
      break;      
  }
  wait(2); // wait 1 + 2 = 3 dots in total after every letter
}

int main() {
  wiringPiSetup();
  pinMode(OUTPUT_PIN, OUTPUT);
  pinMode(INPUT_PIN, INPUT);
  pullUpDnControl(INPUT_PIN, PUD_OFF);
  wiringPiISR(INPUT_PIN, INT_EDGE_BOTH, &switchChanged);
  int character;
  while (true) {
    character = getchar();
    if (character == ' ') {

      // TO DO: wait 1 + 2 + 4 = 7 dots in total after every word

    }
    else {

      // TO DO
      
    }
  }
}
