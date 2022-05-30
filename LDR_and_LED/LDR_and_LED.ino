const int ledPin = 3;
const int ldrPin = A0;
int lastRead = 0;

void setup() {

  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  
  pinMode(ldrPin, INPUT);

}

void loop() {
  
  int ldrStatus = analogRead(ldrPin);
  
  int diff = ldrStatus - lastRead;

  if (!(dif > -5 && dif < 5)) {
    
    lastRead = ldrStatus;
    
    if (ldrStatus <= 20) {

      digitalWrite(ledPin, HIGH);

      Serial.print("Its DARK, Turn on the LED : ");

      Serial.println(ldrStatus);

    } else {

      digitalWrite(ledPin, LOW);

      Serial.print("Its BRIGHT, Turn off the LED : ");

      Serial.println(ldrStatus);

    }
  }
  delay(2000);


}
