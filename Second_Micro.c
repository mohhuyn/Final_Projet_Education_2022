For the second Microcontroller which connected with the servos and the temperature sensor and the
Screen:
#include&lt;Servo.h&gt;
#include&lt;OneWire.h&gt;
#include&lt;DallasTemperature.h&gt;
// Defining the wires for temperature ..
#define One_Wire_Bus 2
OneWire oneWire(One_Wire_Bus);
DallasTemperature sensors(&amp;oneWire);
//creating objects for servos (Head &amp; Arms ( Left/Right)
Servo ServoArm_Right;
Servo ServoArm_Left;
Servo Servo_Head;
//The signal which brings the information from the first microcontroller
#define Signal A5
int Temperature_Final;
// For the servos The initial position.
int posR = 0;
int posH;
int posL;
int Read;
int Read_2;
void setup() {
Serial.begin(9600);
// enbale the temperature ..
sensors.begin();
// Attaching the servos into Pins A1 / 13 / A3
ServoArm_Right.attach(A1);
ServoArm_Left.attach(13);
Servo_Head.attach(A3);
pinMode(Signal,INPUT_PULLUP);}
void loop() {
Read=digitalRead(Signal);
if (Read == 0){
Read=digitalRead(Signal);
for (posR = 120; posR &gt;=50 ; posR -= 1){
posH= int (posR/2);
posL=posR+20;
ServoArm_Right.write(posR);
ServoArm_Left.write(posL);
Servo_Head.write(posH);
delay(15); } // waits 15ms for the servo to reach the position
for (posR = 50; posR &lt;=120;posR += 1) { // goes from 0 degrees to 180 degrees
// in steps of 1 degree
posH= int (posR/2);
posL=posR+20;
ServoArm_Right.write(posR);
ServoArm_Left.write(posL);
Servo_Head.write(posH);
delay(15); } } // waits 15ms for the servo to reach the position
else {
Read=digitalRead(Signal);
ServoArm_Right.write(70);
ServoArm_Left.write(130);
Servo_Head.write(40);
Temperature_Final=mesureTemp();
Serial.print(Temperature_Final);}}
int mesureTemp(){
for (int q=0 ; q&lt;50 ; q++ ){
int a;
sensors.requestTemperatures();
delay(100);
return a;}}
