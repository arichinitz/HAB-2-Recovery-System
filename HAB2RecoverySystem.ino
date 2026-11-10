int buzzer = D4;
int button = D6;
int minsBeforeLaunch = 10;
int flightMins = 135;
int totMins = minsBeforeLaunch+flightMins;
//notes on flight timing
//oren wants 135 mins from when balloon takes off until it starts buzzing
//QUESTION: how much time from pressing button until launch???

bool buzzerState = LOW;

void setup() {
Serial.begin(9600);
pinMode(buzzer, OUTPUT);
pinMode(button, INPUT_PULLUP);
Serial.println("Serial Monitor works");
}


void loop() {

if(digitalRead(button) == 0){
Serial.println("Button Pressed");
buzzerState = HIGH;
digitalWrite(buzzer, HIGH);   // module switches the buzzer on
delay(100);
digitalWrite(buzzer, LOW);   // module switches the buzzer on
delay(100);
digitalWrite(buzzer, HIGH);   // module switches the buzzer on
delay(100);
digitalWrite(buzzer, LOW);   // module switches the buzzer on
delay(100);
digitalWrite(buzzer, HIGH);   // module switches the buzzer on
delay(100);
digitalWrite(buzzer, LOW);   // module switches the buzzer on
delay(100);
digitalWrite(buzzer, HIGH);   // module switches the buzzer on
delay(100);
digitalWrite(buzzer, LOW);   // module switches the buzzer on
delay(100);

delay(60000 * totMins);
}

if(buzzerState){
digitalWrite(buzzer, HIGH);   // module switches the buzzer on
Serial.println("Buzzer on");
delay(500);
digitalWrite(buzzer, LOW);   // module switches the buzzer on
delay(500);
Serial.println("Buzzer off");
}


}