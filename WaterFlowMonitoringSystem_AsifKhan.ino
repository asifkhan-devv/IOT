/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  =>
  =>          USB HOWTO: http://tiny.cc/BlynkUSB
  =>

  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT DebugSerial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"

#define BLYNK_TEMPLATE_ID "TMPLy5JxiXd0"
#define BLYNK_DEVICE_NAME "Tap Monitoring System IOT"
#define BLYNK_AUTH_TOKEN "5iC4Ia8EmXwzMtpo8YayusTmYEHIff0p"

// You could use a spare Hardware Serial on boards that have it (like Mega)
#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(2, 3); // RX, TX

#include <BlynkSimpleStream.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;
char message1[]="Water Tap ON!";
char message2[]="Water Tap OFF!";
int var;
int sensorpin = 3;
int dummy;

WidgetLED led1(V1);
BlynkTimer timer; 

BLYNK_WRITE(V0)
{

  var = param.asInt();
  digitalWrite(11,var);
  
 }

void sensor1() 
{
 
 int value = digitalRead(sensorpin);

 if(value == HIGH)
    {
    led1.on();
    Blynk.virtualWrite(V2, message2);
    }
    else if(value == LOW)
    {
      led1.off();
      Blynk.virtualWrite(V2, message1);
      }
      else
      {
        dummy=0;
        }
}

 
 
void setup()
{
  // Debug console
  
  DebugSerial.begin(9600);
  pinMode(sensorpin,INPUT);
  // Blynk will work through Serial
  // Do not read or write this serial manually in your sketch
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
  timer.setInterval(100L, sensor1);

}

void loop()
{

  
  Blynk.run();
  timer.run();



}
