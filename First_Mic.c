//For the first microcontroller which connect with the motors and the sensors (Ultrasonic, IR sensor,
//IRremote):
#include&lt;IRremote.h&gt;
// Ir sensor and remote decoding the number of the chamber for the robot..
IRrecv Receiver(3);
decode_results Receiver_Decode;
//The pins for both the second microcontroller &amp; the Raspberry pi.
// For the second microController which measure temperature and Servos.
#define Pin_SecondMicroController 5
#define Pin_Sec 2
// For the raspberry pi to enable the Camera.
#define Pin_Raspberry_Pi 1
// Stepper Motors defining pins......
#define STEPPIN 11 // Step fpr both motors
#define DIRPIN_RIGHT 9 // the direction of right motor.
#define ENAPIN_RIGHT 10 // Enable for right motor
#define DIRPIN_LEFT 13 // Direction of left Motor...
#define ENAPIN_LEFT 12 // Enable for left motor..
// a parameter for step in steper motors.
int i;
// Motors delay...
const int STEPTIME = 5;
const int STEPTIMEFORWARD = 2;
//Defining IRs Pins ....
#define IRR 6
#define IRC 8
#define IRL 7
// Defining Ultrasonics Pins .....
//Center ...
#define ECHO_PIN_Center A3
#define TRIGGER_PIN_Center A2
//Left ...
#define ECHO_PIN_Left A1
#define TRIGGER_PIN_Left A0
//Right ..
#define ECHO_PIN_Right A5
#define TRIGGER_PIN_Right A4
// The max distance for avoiding the obstacle.
#define Max_Distance_Center 20
// Reading the valut from Ultrasonic .Center
int Variable_Distance_Center;
float duration_Center ;
int distanceCm_Center;
// Reading the valut from Ultrasonic .Left
int Variable_Distance_Left;
float duration_Left ;
int distanceCm_Left;
// Reading the valut from Ultrasonic .Right
int Variable_Distance_Right;
float duration_Right ;
int distanceCm_Right ;
void setup() {
//Enable stepper motors pins ....
pinMode(STEPPIN,OUTPUT);
pinMode(DIRPIN_RIGHT,OUTPUT);
pinMode(ENAPIN_RIGHT,OUTPUT);
pinMode(ENAPIN_LEFT,OUTPUT);
pinMode(DIRPIN_LEFT,OUTPUT);
// Enable Ultra sonic pins ..
pinMode(TRIGGER_PIN_Center,OUTPUT);
pinMode(ECHO_PIN_Center,INPUT);
// Enable Infra red pins ...
pinMode(IRL,INPUT);
pinMode(IRC,INPUT);
pinMode(IRR,INPUT);
//Putting the pins for Mic&amp;Ras as OUTPUT.
pinMode(Pin_SecondMicroController,OUTPUT);
pinMode(Pin_Sec,OUTPUT);
pinMode(Pin_Raspberry_Pi,OUTPUT);
// And making them at first LOW for avoiding any problem at first running.
digitalWrite(Pin_SecondMicroController,HIGH);
digitalWrite(Pin_Sec,HIGH);
digitalWrite(Pin_Raspberry_Pi,LOW);
Serial.begin(9600);
Receiver.enableIRIn();
Variable_Distance_Center = Obstacle();
delay(200);
Variable_Distance_Center = Obstacle() ;}
//the fonction of the ultrasonic the center one .
float Obstacle(){
digitalWrite(TRIGGER_PIN_Center,LOW);
delayMicroseconds(2);
digitalWrite(TRIGGER_PIN_Center,HIGH);
delayMicroseconds(10);
//digitalWrite(TRIGGER_PIN_Center,LOW);
duration_Center = pulseIn(ECHO_PIN_Center, HIGH);
distanceCm_Center=int( duration_Center/29/2);
return distanceCm_Center;}
// Obstacle for the left one
float ObstacleLeft(){
digitalWrite(TRIGGER_PIN_Left,LOW);
delayMicroseconds(2);
digitalWrite(TRIGGER_PIN_Left,HIGH);
delayMicroseconds(10);
// digitalWrite(TRIGGER_PIN_Center,LOW);
duration_Left = pulseIn(ECHO_PIN_Left, HIGH);
distanceCm_Left=int( duration_Left/29/2);
return distanceCm_Left;}
//obstacle for the right Ultrasonic
float ObstacleRight(){
digitalWrite(TRIGGER_PIN_Right,LOW);
delayMicroseconds(2);
digitalWrite(TRIGGER_PIN_Right,HIGH);
delayMicroseconds(10);
// digitalWrite(TRIGGER_PIN_Center,LOW);
duration_Right = pulseIn(ECHO_PIN_Right, HIGH);
distanceCm_Right=int( duration_Right/29/2);
return distanceCm_Right;}
// Function for walking forward
void Forward() {
digitalWrite(ENAPIN_RIGHT,HIGH);
digitalWrite(DIRPIN_RIGHT,HIGH);
digitalWrite(ENAPIN_LEFT,HIGH);
digitalWrite(DIRPIN_LEFT,HIGH);
for(i=0;i&lt;100;i++){
digitalWrite(STEPPIN,HIGH);
delay(STEPTIMEFORWARD);
digitalWrite(STEPPIN,LOW);
delay(STEPTIMEFORWARD);}
// digitalWrite(ENAPIN_RIGHT,LOW);
//digitalWrite(ENAPIN_LEFT,LOW);
digitalWrite(Pin_SecondMicroController,HIGH);
digitalWrite(Pin_Sec,HIGH);
digitalWrite(Pin_Raspberry_Pi,LOW);}
// the forward for the obstacle
void ForwardObs() {
digitalWrite(ENAPIN_RIGHT,HIGH);
digitalWrite(DIRPIN_RIGHT,HIGH);
digitalWrite(ENAPIN_LEFT,HIGH);
digitalWrite(DIRPIN_LEFT,HIGH);
for(i=0;i&lt;800;i++){
digitalWrite(STEPPIN,HIGH);
delay(STEPTIMEFORWARD);
digitalWrite(STEPPIN,LOW);
delay(STEPTIMEFORWARD);}
// digitalWrite(ENAPIN_RIGHT,LOW);
//digitalWrite(ENAPIN_LEFT,LOW);
digitalWrite(Pin_SecondMicroController,LOW);
digitalWrite(Pin_Sec,HIGH);
digitalWrite(Pin_Raspberry_Pi,LOW);}
// Second function for turning Left.
void Left () {
digitalWrite(ENAPIN_RIGHT,HIGH);
digitalWrite(DIRPIN_RIGHT,HIGH);
digitalWrite(ENAPIN_LEFT,LOW);
for(i=0;i&lt;50;i++){
digitalWrite(STEPPIN,HIGH);
delay(STEPTIME);
digitalWrite(STEPPIN,LOW);
delay(STEPTIME);}
//digitalWrite(ENAPIN_RIGHT,LOW);
//digitalWrite(ENAPIN_LEFT,LOW);
digitalWrite(Pin_SecondMicroController,LOW);
digitalWrite(Pin_Sec,HIGH);
digitalWrite(Pin_Raspberry_Pi,LOW);}
//the left for the obstacle..
void LeftObs () {
digitalWrite(ENAPIN_RIGHT,HIGH);
digitalWrite(DIRPIN_RIGHT,HIGH);
digitalWrite(ENAPIN_LEFT,LOW);
for(i=0;i&lt;800;i++){
digitalWrite(STEPPIN,HIGH);
delay(STEPTIME);
digitalWrite(STEPPIN,LOW);
delay(STEPTIME);}
//digitalWrite(ENAPIN_RIGHT,LOW);
//digitalWrite(ENAPIN_LEFT,LOW);
digitalWrite(Pin_SecondMicroController,LOW);
digitalWrite(Pin_Sec,HIGH);
digitalWrite(Pin_Raspberry_Pi,LOW);}
//Third function for turning Right.
void Right(){
digitalWrite(ENAPIN_RIGHT,LOW);
digitalWrite(ENAPIN_LEFT,HIGH);
digitalWrite(DIRPIN_LEFT,HIGH);//SET DIRECTION
for(i=0;i&lt;50;i++){
digitalWrite(STEPPIN,HIGH);
delay(STEPTIME);
digitalWrite(STEPPIN,LOW);
delay(STEPTIME);}
//digitalWrite(ENAPIN_RIGHT,LOW);//DISABLE STEPPER
//digitalWrite(ENAPIN_LEFT,LOW);
digitalWrite(Pin_SecondMicroController,LOW);
digitalWrite(Pin_Sec,HIGH);
digitalWrite(Pin_Raspberry_Pi,LOW);}
// the right for the obstalce...
void RightObs(){
digitalWrite(ENAPIN_RIGHT,LOW);
digitalWrite(ENAPIN_LEFT,HIGH);
digitalWrite(DIRPIN_LEFT,HIGH);//SET DIRECTION
for(i=0;i&lt;800;i++){
digitalWrite(STEPPIN,HIGH);
delay(STEPTIME);
digitalWrite(STEPPIN,LOW);
delay(STEPTIME);}
//digitalWrite(ENAPIN_RIGHT,LOW);//DISABLE STEPPER
//digitalWrite(ENAPIN_LEFT,LOW);
digitalWrite(Pin_SecondMicroController,LOW);
digitalWrite(Pin_Sec,HIGH);
digitalWrite(Pin_Raspberry_Pi,LOW);}
//Fourth function for stoping when its all black or white.
Void Stop() {
digitalWrite(ENAPIN_RIGHT,LOW);
digitalWrite(ENAPIN_LEFT,LOW);
// When the motor Stops in black it allows the pins for the raspberry pi to talk and disable the Servos
Movement
digitalWrite(Pin_SecondMicroController,HIGH);
digitalWrite(Pin_Raspberry_Pi,HIGH);}
// The main code which will be running all the time.
void loop() {
Variable_Distance_Center = Obstacle();
Variable_Distance_Right = ObstacleRight();
Variable_Distance_Left = ObstacleLeft();
Serial.println(Variable_Distance_Center);
if ( Receiver .decode( &amp; Receiver_Decode )) {
if(Receiver_Decode.value == 0xFF30CF){
Variable_Distance_Center = Obstacle();
Come_Here:
if (Variable_Distance_Center &gt; Max_Distance_Center){
Variable_Distance_Center = Obstacle();
if (digitalRead (IRR) == LOW &amp;&amp; digitalRead(IRC) == HIGH &amp;&amp; digitalRead(IRL) == LOW ) { Forward(); }
if (digitalRead (IRR) == LOW &amp;&amp; digitalRead(IRC) == HIGH &amp;&amp; digitalRead(IRL) == HIGH) { Right();}
if (digitalRead (IRR) == HIGH &amp;&amp; digitalRead(IRC) == HIGH &amp;&amp; digitalRead(IRL) == LOW ) {Left();}
if (digitalRead (IRR) == HIGH &amp;&amp; digitalRead(IRC) == LOW&amp;&amp; digitalRead(IRL) == LOW) { Left(); }
if (digitalRead (IRR) == LOW &amp;&amp; digitalRead(IRC) == LOW &amp;&amp; digitalRead(IRL) == HIGH ) { Right(); }
if (digitalRead (IRR) == HIGH &amp;&amp; digitalRead(IRC) == HIGH &amp;&amp; digitalRead(IRL) == HIGH) {
digitalWrite(Pin_Sec,LOW);
Stop();
delay(50000);
digitalWrite(ENAPIN_RIGHT,HIGH);
digitalWrite(ENAPIN_LEFT,HIGH);
digitalWrite(DIRPIN_LEFT,LOW);
digitalWrite(DIRPIN_RIGHT,HIGH);//SET DIRECTION
for(i=0;i&lt;1500;i++){
digitalWrite(STEPPIN,HIGH);
delay(STEPTIME);
digitalWrite(STEPPIN,LOW);
delay(STEPTIME);}}
if (digitalRead (IRR) == LOW &amp;&amp; digitalRead(IRC) == LOW &amp;&amp; digitalRead(IRL) == LOW ) { Stop();
digitalWrite(Pin_Sec,HIGH);
digitalWrite(ENAPIN_RIGHT,HIGH);
digitalWrite(ENAPIN_LEFT,HIGH);
digitalWrite(DIRPIN_LEFT,LOW);
digitalWrite(DIRPIN_RIGHT,HIGH);//SET DIRECTION
for(i=0;i&lt;750;i++){
digitalWrite(STEPPIN,HIGH);
delay(STEPTIME);
digitalWrite(STEPPIN,LOW);
delay(STEPTIME);}
digitalWrite(ENAPIN_RIGHT,HIGH);
digitalWrite(ENAPIN_LEFT,HIGH);
digitalWrite(DIRPIN_LEFT,HIGH);
digitalWrite(DIRPIN_RIGHT,HIGH);//SET DIRECTION
for(i=0;i&lt;2000;i++){
digitalWrite(STEPPIN,HIGH);
delay(STEPTIME);
digitalWrite(STEPPIN,LOW);
delay(STEPTIME);}
digitalWrite(ENAPIN_RIGHT,HIGH);
digitalWrite(ENAPIN_LEFT,HIGH);
digitalWrite(DIRPIN_LEFT,LOW);
digitalWrite(DIRPIN_RIGHT,HIGH);//SET DIRECTION
for(i=0;i&lt;1500;i++){
digitalWrite(STEPPIN,HIGH);
delay(STEPTIME);
digitalWrite(STEPPIN,LOW);
delay(STEPTIME);}
while (true){ Stop();}}
else if(Variable_Distance_Center &lt;= Max_Distance_Center){
Variable_Distance_Right = ObstacleRight();
Variable_Distance_Left = ObstacleLeft();
Variable_Distance_Center = Obstacle();
if (Variable_Distance_Right &lt; Variable_Distance_Left){
LeftObs();
ForwardObs();
RightObs();
ForwardObs();
RightObs();
ForwardObs();
if (digitalRead (IRR) == HIGH || digitalRead(IRC) == HIGH || digitalRead(IRL) == HIGH){
goto Come_Here;}}
if (Variable_Distance_Right &gt; Variable_Distance_Left){
RightObs();
ForwardObs();
LeftObs();
Annexe I
ForwardObs();
LeftObs();
ForwardObs();
if (digitalRead (IRR) == LOW || digitalRead(IRC) == HIGH || digitalRead(IRL) == HIGH){
goto Come_Here; }} }
else if (Receiver_Decode.value == 0xFF6897){
digitalWrite(ENAPIN_RIGHT,LOW);
digitalWrite(ENAPIN_LEFT,LOW); }}}}
	

