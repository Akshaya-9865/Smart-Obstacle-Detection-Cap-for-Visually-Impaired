#include <NewPing.h>

#define TRIG_PIN_FRONT 23   // Trigger pin for the front ultrasonic sensor
#define ECHO_PIN_FRONT 19   // Echo pin for the front ultrasonic sensor
#define TRIG_PIN_RIGHT 22    // Trigger pin for the right ultrasonic sensor
#define ECHO_PIN_RIGHT 21    // Echo pin for the right ultrasonic sensor
#define TRIG_PIN_LEFT 18     // Trigger pin for the left ultrasonic sensor
#define ECHO_PIN_LEFT 17     // Echo pin for the left ultrasonic sensor
#define BUZZER_PIN 25        // Pin for the buzzer
#define VIBRATION_LEFT_PIN 26 // Pin for left vibration motor
#define VIBRATION_RIGHT_PIN 27 // Pin for right vibration motor

// Create NewPing instances for each sensor
NewPing sonarFront(TRIG_PIN_FRONT, ECHO_PIN_FRONT, 200); // Max distance 200 cm for front sensor
NewPing sonarRight(TRIG_PIN_RIGHT, ECHO_PIN_RIGHT, 200); // Max distance 200 cm for right sensor
NewPing sonarLeft(TRIG_PIN_LEFT, ECHO_PIN_LEFT, 200); // Max distance 200 cm for left sensor

void setup() {
  Serial.begin(115200); // Start the Serial communication at 115200 baud rate
  pinMode(BUZZER_PIN, OUTPUT); // Set the buzzer pin as output
  pinMode(VIBRATION_LEFT_PIN, OUTPUT); // Set left vibration motor pin as output
  pinMode(VIBRATION_RIGHT_PIN, OUTPUT); // Set right vibration motor pin as output
}

void loop() {
  delay(50); // Short delay to avoid flooding the serial monitor

  // Get distance from the ultrasonic sensors
  int distanceFront = sonarFront.ping_cm();
  int distanceRight = sonarRight.ping_cm();
  int distanceLeft = sonarLeft.ping_cm();

  // Print distances to Serial Monitor
  Serial.print("Front Distance: ");
  Serial.print(distanceFront);
  Serial.print(" cm, Right Distance: ");
  Serial.print(distanceRight);
  Serial.print(" cm, Left Distance: ");
  Serial.print(distanceLeft);
  Serial.println(" cm");

  // Control beeping and vibration based on distances
  controlBeepAndVibration(distanceFront, distanceRight, distanceLeft);

  delay(100); // Adjust delay as needed
}

void controlBeepAndVibration(int distanceFront, int distanceRight, int distanceLeft) {
  // Stop all vibrations and buzzer initially
  noTone(BUZZER_PIN);
  digitalWrite(VIBRATION_LEFT_PIN, LOW);
  digitalWrite(VIBRATION_RIGHT_PIN, LOW);

  // Check for front obstacle
  if (distanceFront > 0 && distanceFront <= 50) {
    // Map distance to frequency for front sensor
    int frequencyFront = map(distanceFront, 5, 50, 1000, 200); // 1000 Hz at 5 cm, 200 Hz at 50 cm
    tone(BUZZER_PIN, frequencyFront); // Start beeping for front sensor

    // Control beep duration based on front distance
    int durationFront = map(distanceFront, 5, 50, 100, 1000); // Shorter duration for closer distance
    delay(durationFront); // Wait for the duration
    noTone(BUZZER_PIN); // Stop the tone
  }

  // Check for right-side obstacle
  if (distanceRight > 0 && distanceRight <= 50) {
    // Activate right vibration motor
    digitalWrite(VIBRATION_RIGHT_PIN, HIGH);
    delay(200); // Vibration duration for right indication
    digitalWrite(VIBRATION_RIGHT_PIN, LOW); // Stop vibration
  }

  // Check for left-side obstacle
  if (distanceLeft > 0 && distanceLeft <= 50) {
    // Activate left vibration motor
    digitalWrite(VIBRATION_LEFT_PIN, HIGH);
    delay(200); // Vibration duration for left indication
    digitalWrite(VIBRATION_LEFT_PIN, LOW); // Stop vibration
  }
}