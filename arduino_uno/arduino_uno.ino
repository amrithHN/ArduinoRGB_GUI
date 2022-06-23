/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

#define R 3
#define G 5
#define B 6
String color;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
 

    Serial.begin(9600);
}

String colors[3];

// the loop function runs over and over again forever
void loop() {

while(Serial.available())
{
  color=Serial.readStringUntil('\n');
  //Serial.print(color);
  int temp=0;
  int color_index=0;
  
  for(int i=0;i<color.length();i++)
  if(color[i]==','){
  colors[color_index]=color.substring(temp,i);
  //Serial.print(colors[color_index]);
  temp=i+1; 
  color_index++;
    }
    
  colors[color_index]=color.substring(temp,color.length());
  //Serial.print(colors[color_index]);
    

}

  analogWrite(3,colors[0].toInt());  //r
  analogWrite(5,colors[1].toInt());  //g
  analogWrite(6,colors[2].toInt());  //b
  
}

   
