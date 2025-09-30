char t;

// Motoare
int IN1 = 4;  // stânga față
int IN2 = 5;
int IN3 = 6;  // stânga spate
int IN4 = 7;
int IN5 = 8;  // dreapta față
int IN6 = 9;
int IN7 = 10; // dreapta spate
int IN8 = 11;

unsigned long lastCommandTime = 0;
const unsigned long timeout = 300; 

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);

  Serial.begin(9600); 
}

void loop() {
  if (Serial.available()) {
    t = Serial.read();
    lastCommandTime = millis();   
    Serial.println(t);            
  }

if (t == 'F') {   // înainte
  // stânga
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  // dreapta
  digitalWrite(IN5, HIGH); digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH); digitalWrite(IN8, LOW);
}
else if (t == 'B') {   // înapoi
  // stânga
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  // dreapta
  digitalWrite(IN5, LOW); digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW); digitalWrite(IN8, HIGH);
}
  else if (t == 'L') {   // stânga
    // stânga înapoi
    digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
    // dreapta înainte
    digitalWrite(IN5, HIGH); digitalWrite(IN6, LOW);
    digitalWrite(IN7, HIGH); digitalWrite(IN8, LOW);
  }
  else if (t == 'R') {   
    // stânga înainte
    digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
    // dreapta înapoi
    digitalWrite(IN5, LOW); digitalWrite(IN6, HIGH);
    digitalWrite(IN7, LOW); digitalWrite(IN8, HIGH);
  }
  else if (t == 'Z') {   
    stopMotors();
  }

  if (millis() - lastCommandTime > timeout) {
    stopMotors();
    t = 'Z'; 
  }
}

void stopMotors() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW); digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW); digitalWrite(IN8, LOW);
}