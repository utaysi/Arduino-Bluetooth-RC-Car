//L298N Connection 
  const int motorA1  = 5;  // L298N IN3 Input
  const int motorA2  = 6;  // L298N IN1 Input
  const int motorB1  = 10; // L298N IN2 Input
  const int motorB2  = 9;  // L298N IN4 Input
  const int buzzer  = 7;  // L298N IN4 Input
  #define LED_PIN1 11
  #define LED_PIN2 13
  #define LED_PIN3 12
  #define LED_PIN4 8
  

  #define POTENTIOMETER_PIN A1

  int i=0; 
  int j=0; 
  int state; // Bluetooth State
  int vSpeed=255; // Standard speed, set between 0-255

void setup() {
    // Set pins
    pinMode(LED_PIN1, OUTPUT); // back left
    pinMode(LED_PIN2, OUTPUT); // back right
    pinMode(LED_PIN3, OUTPUT); // front left?
    pinMode(LED_PIN4, OUTPUT); // front right?
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT); 
    pinMode(buzzer, OUTPUT);   
    // Open serial port in 9600 baud speed
    Serial.begin(9600);
}
 
void loop() {
  //Save incoming data to state variable. 
    if(Serial.available() > 0){     
      state = Serial.read();   
    }
  
  // 4 speed levels from the app. Must be set between 0-255.
    if (state == '0'){
      vSpeed=0;}
    else if (state == '1'){
      vSpeed=100;}
    else if (state == '2'){
      vSpeed=180;}
    else if (state == '3'){
      vSpeed=200;}
    else if (state == '4'){
      vSpeed=255;}
     
  /***********************Forward****************************/
    if (state == 'F') {
      analogWrite(motorA1, vSpeed); 
      analogWrite(motorA2, vSpeed);
      analogWrite(motorB1, 0);      
      analogWrite(motorB2, 0); 
    }
  /**********************Forward Left************************/
    else if (state == 'G') {
      analogWrite(motorA1,vSpeed ); 
      analogWrite(motorA2, 100);  
      analogWrite(motorB1, 0);    
      analogWrite(motorB2, 0); 
    }
    /**********************Forward Right************************/
    else if (state == 'I') {
        analogWrite(motorA1, 100); 
        analogWrite(motorA2, vSpeed); 
        analogWrite(motorB1, 0);      
        analogWrite(motorB2, 0); 
    }
  
  /***********************Backward****************************/
    else if (state == 'B') {
      analogWrite(motorA1, 0);   
      analogWrite(motorA2, 0); 
      analogWrite(motorB1, vSpeed);   
      analogWrite(motorB2, vSpeed); 
    }
  /**********************Backward Left************************/
    else if (state == 'H') {
      analogWrite(motorA1, 0);   
      analogWrite(motorA2, 0); 
      analogWrite(motorB1, 100); 
      analogWrite(motorB2, vSpeed); 
    }
  /**********************Backward Right************************/
    else if (state == 'J') {
      analogWrite(motorA1, 0);   
      analogWrite(motorA2, 0); 
      analogWrite(motorB1, vSpeed);   
      analogWrite(motorB2, 100); 
    }
  
  /***************************Left*****************************/
    else if (state == 'L') {
      analogWrite(motorA1, vSpeed);   
      analogWrite(motorA2, 0); 
      analogWrite(motorB1, vSpeed); 
      analogWrite(motorB2, 0); 
    }
  /***************************Right*****************************/
    else if (state == 'R') {
      analogWrite(motorA1, 0);   
      analogWrite(motorA2, vSpeed); 
      analogWrite(motorB1, 0);   
      analogWrite(motorB2, vSpeed);     
    }
  
  /************************Stop*****************************/
    else if (state == 'S'){
        analogWrite(motorA1, 0);  
        analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);  
        analogWrite(motorB2, 0);
    }  
    /************************Front Lights On*****************************/
    else if (state == 'W'){
        digitalWrite(LED_PIN3, HIGH);
        digitalWrite(LED_PIN4, HIGH);
    }  
    /************************Back Lights On*****************************/
    else if (state == 'U'){
        digitalWrite(LED_PIN1, HIGH);
        digitalWrite(LED_PIN2, HIGH);
    }  
    /************************Front Lights Off*****************************/
    else if (state == 'w'){
        digitalWrite(LED_PIN3, LOW);
        digitalWrite(LED_PIN4, LOW);
    }  
    /************************Back Lights Off*****************************/
    else if (state == 'u'){
        digitalWrite(LED_PIN1, LOW);
        digitalWrite(LED_PIN2, LOW);
    }  
    /************************Horn On*****************************/
    else if (state == 'V'){
      int counter = 0;
        while(counter <50){
        digitalWrite(buzzer, HIGH);
        delay(10);
        digitalWrite(buzzer, LOW);
        delay(10);
        counter += 1;
      }
    } 
    
    /************************Horn Off*****************************/
    else if (state == 'v'){
        digitalWrite(buzzer, LOW);
    }
    /************************Stress Signal On*****************************/
    else if (state == 'X'){
      int counter = 0;
        while (counter < 10){
        digitalWrite(LED_PIN1, HIGH);
        delay(50);
        digitalWrite(buzzer, HIGH);
        digitalWrite(LED_PIN2, HIGH);
        delay(50);
        digitalWrite(buzzer, LOW);
        digitalWrite(LED_PIN3, HIGH);
        delay(50);
        digitalWrite(buzzer, HIGH);
        digitalWrite(LED_PIN4, HIGH);
        delay(50);
        digitalWrite(buzzer, LOW);
        digitalWrite(LED_PIN1, LOW);
        delay(50);
        digitalWrite(buzzer, HIGH);
        digitalWrite(LED_PIN2, LOW);
        delay(50);
        digitalWrite(buzzer, LOW);
        digitalWrite(LED_PIN3, LOW);
        delay(50);
        digitalWrite(buzzer, HIGH);
        digitalWrite(LED_PIN4, LOW);
        delay(50);
        digitalWrite(buzzer, LOW);
        counter += 1;
        }
    }
    /************************Stress Signal Off*****************************/
    else if (state == 'x'){

      digitalWrite(LED_PIN1, LOW);
      digitalWrite(LED_PIN2, LOW);
      digitalWrite(LED_PIN3, LOW);
      digitalWrite(LED_PIN4, LOW);
      digitalWrite(buzzer, LOW);  
    }
}
