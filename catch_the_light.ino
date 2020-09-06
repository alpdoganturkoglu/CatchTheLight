const int lowestPin = 2;
const int highestPin = 13;
const int buttonPin = 21;
bool succes;
int temppin;
bool failure;
int thisPin = lowestPin;
int randomnumber=0;
int counter =3;
int gamedelay=1000;

void setup() {
  Serial.begin(9600);
  for (thisPin; thisPin <= highestPin; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonCheck, RISING);
  randomSeed(analogRead(0));
  randomnumber = random(2,14);
}

void loop() {

  if(counter == 0){
   gamedelay =10000;
  }
    if(gamedelay == 200){
      while (true){
         for (int tempPin = lowestPin; tempPin <= highestPin; tempPin++) {
           analogWrite(tempPin, 255);
           delay(100);
           analogWrite(tempPin,LOW);
      }
      }
    }// game over 
    else{
      for (thisPin; thisPin <= highestPin; thisPin++) {
        analogWrite(randomnumber,255);
         if(succes == true){
          for(int x = 0 ; x<5 ; x++){
            for ( int tempPin = lowestPin; tempPin <= highestPin; tempPin++){
              analogWrite(tempPin,255);
              delay(50);
              analogWrite(tempPin,LOW);
              }
            }
        succes = false;
        }
       
        analogWrite(thisPin, 255);
        delay(gamedelay);
         if(failure == true){
          delay(1500);
          failure = false;
        }    
        if(thisPin == randomnumber){
          NULL;
        }// if it is random led 
        else{
          analogWrite(thisPin,LOW);
        } // if it is not random led 
      }
      thisPin = lowestPin;
    } //Game is on
 }

 void buttonCheck (){
    if(thisPin == randomnumber){
      succes = true;
      gamedelay = gamedelay-200;
      setup();
      analogWrite(randomnumber,255);
     }
     else{
      failure = true;
      counter--;
     }
 }
 
 
