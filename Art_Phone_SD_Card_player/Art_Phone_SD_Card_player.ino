#include <SD.h>                      // need to include the SD library
#define SD_ChipSelectPin 4  //using digital pin 4 on arduino nano 328
#include <TMRpcm.h>           //  also need to include this library...
 
TMRpcm tmrpcm;   // create an object for use in this sketch
 int SW1; 
 int SW2;
 int SW3;
 int SW4;
 int playedfile;
 
void setup(){
 Serial.begin(9600);
 pinMode(14,INPUT);  //Define A0 as digital input.
 pinMode(15,INPUT);  //Define A1 as digital input. 
 pinMode(16,INPUT);  //Define A2 as digital input.
 pinMode(17,INPUT);  //Define A3 as digital input.
 
  tmrpcm.speakerPin = 9; //11 on Mega, 9 on Uno, Nano, etc
 
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.write ("Unable to initiaise the SD card");
  return;   // don't do anything more if not
  }

 playedfile =1;
 tmrpcm.volume(1);
 tmrpcm.play("7.wav"); //the sound file "1" will play each time the arduino powers up, or is reset
}
 
void loop(){  
 SW1=digitalRead(14); 

     if (SW1 == LOW) {
      Serial.println("Playedfile before case switch = " + String(playedfile));
      
      switch (playedfile) {


         case 2:
            tmrpcm.play("2.wav");
            Serial.println("Playing 2.wav");
          break;

          case 3:
            tmrpcm.play("3.wav");
            Serial.println("Playing 3.wav");
          break;

          case 4:
            tmrpcm.play("4.wav");
            Serial.println("Playing 4.wav");
          break;

          case 5:
            tmrpcm.play("5.wav");
            Serial.println("Playing 5.wav");
          break;

        case 6:
            tmrpcm.play("6.wav");
            Serial.println("Playing 6.wav");
          break;

        case 1:
            tmrpcm.play("1.wav");
            Serial.println("Playing 1.wav");
          break;
          
        default:
          playedfile = 1;
        break;
      }
      ++playedfile;
      if (playedfile == 7){
        playedfile = 1;
      }
      Serial.println("After Case Statement update = " + String(playedfile));
      delay (1000); //This delay allows the button to bounce and prevents the code from running too fast.
    } 
    
}
