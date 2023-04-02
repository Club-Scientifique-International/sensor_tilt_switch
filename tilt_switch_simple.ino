//Parameters
const int tiltPin = 8;
const int ledPin = 11;
//Variables
bool tiltStatus = false;
bool oldTiltStatus = false;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
//Init Serial USB
Serial.begin(9600);
Serial.println(F("Initialize System"));
//Init digital input
pinMode(tiltPin, INPUT);
//Init digital output
pinMode(ledPin, OUTPUT);
}

void loop() {
debounceTilt();
if (tiltStatus == true) {
digitalWrite(ledPin, HIGH);
} else {
digitalWrite(ledPin, LOW);
}
}

void debounceTilt() {
//debounce TiltSwitch
int reading = digitalRead(tiltPin);
if (reading != oldTiltStatus) {
lastDebounceTime = millis();
}
if ((millis() - lastDebounceTime) > debounceDelay) {
if (reading != tiltStatus) {
tiltStatus = reading;
Serial.print(F("Sensor state : ")); Serial.println(tiltStatus);
}
}
oldTiltStatus = reading;
}