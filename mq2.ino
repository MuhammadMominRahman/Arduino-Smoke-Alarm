#define MQ2pin 0
#define REDLED 12
#define GREENLED 13
#define BUZZER 5
#define THRES 100 


float sensor_value;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(REDLED, OUTPUT);
  pinMode(GREENLED,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  pinMode(MQ2pin, INPUT);
  Serial.begin(9600);
  Serial.println("MQ2 Warming Up!");
  delay(2000);

}

void loop() {
  // put your main code here, to run repeatedly:
  sensor_value = analogRead(MQ2pin);
  Serial.print("Sensor value: ");
  Serial.println(sensor_value);

  if(sensor_value > THRES)
  {
     digitalWrite(REDLED,HIGH);
     digitalWrite(GREENLED,LOW);
     tone(BUZZER, 1000, 200);
  }
  else
  {
    digitalWrite(REDLED,LOW);
    digitalWrite(GREENLED,HIGH);
    noTone(BUZZER);;  
  }

  delay(100);
}
