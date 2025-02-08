#include <Servo.h>

Servo servo_0, servo_1, servo_2, servo_3, servo_4, servo_5, servo_6;
int pos[7] = {90, 90, 90, 90, 90, 90, 90};  // Başlangıç pozisyonları

void setup() {
  servo_0.attach(2);
  servo_1.attach(3);
  servo_2.attach(4);
  servo_3.attach(5);
  servo_4.attach(6);
  servo_5.attach(7);
  servo_6.attach(8);

  Serial.begin(9600);

  // Tüm servo motorları başlangıç pozisyonuna getir
  for (int i = 0; i < 7; i++) {
    moveServo(i);
  }
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();

    switch (command) {
      case 'Q': if (pos[0] < 180) pos[0] += 5; break;
      case 'A': if (pos[0] > 0) pos[0] -= 5; break;

      case 'W': if (pos[1] < 180) pos[1] += 5; break;
      case 'S': if (pos[1] > 0) pos[1] -= 5; break;

      case 'E': if (pos[2] < 180) pos[2] += 5; break;
      case 'D': if (pos[2] > 0) pos[2] -= 5; break;

      case 'R': if (pos[3] < 180) pos[3] += 5; break;
      case 'F': if (pos[3] > 0) pos[3] -= 5; break;

      case 'T': if (pos[4] < 180) pos[4] += 5; break;
      case 'G': if (pos[4] > 0) pos[4] -= 5; break;

      case 'Y': if (pos[5] < 180) pos[5] += 5; break;
      case 'H': if (pos[5] > 0) pos[5] -= 5; break;

      case 'U': if (pos[6] < 180) pos[6] += 5; break;
      case 'J': if (pos[6] > 0) pos[6] -= 5; break;
    }

    for (int i = 0; i < 7; i++) {
      moveServo(i);
    }
  }
}

void moveServo(int index) {
  switch (index) {
    case 0: servo_0.write(pos[0]); break;
    case 1: servo_1.write(pos[1]); break;
    case 2: servo_2.write(pos[2]); break;
    case 3: servo_3.write(pos[3]); break;
    case 4: servo_4.write(pos[4]); break;
    case 5: servo_5.write(pos[5]); break;
    case 6: servo_6.write(pos[6]); break;
  }
}
