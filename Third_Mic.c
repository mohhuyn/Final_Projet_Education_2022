For the third microcontroller which connect to the SD card and the loud speacker:

#include &lt;SD.h&gt; // need to include the SD library
#define SD_ChipSelectPin 4
#include &lt;TMRpcm.h&gt; // also need to include this library...
#include &lt;SPI.h&gt;
TMRpcm tmrpcm; // create an object for use in this sketch
unsigned long time = 0;
void setup(){
pinMode(2,INPUT_PULLUP);
while (digitalRead(2) == 1){}
tmrpcm.speakerPin = 9//Complimentary Output or Dual Speakers:
Serial.begin(9600);
if (!SD.begin(SD_ChipSelectPin)) { // see if the card is present and can be initialized:
Serial.println(&quot;SD fail&quot;);
return; } // don&#39;t do anything more if not
else{
Serial.println(&quot;SD ok&quot;); }
delay(2000);
tmrpcm.setVolume(5);
tmrpcm.play(&quot;Hello.wav&quot;); //the sound file &quot;Hello&quot; will play each time the arduino powers up, or is
reset
delay(1000);
tmrpcm.play(&quot;Mynameis.wav&quot;);
delay(4000);
tmrpcm.play(&quot;Medical.wav&quot;);
delay(4000);
tmrpcm.play(&quot;Iamhere.wav&quot;);
delay(4000);
tmrpcm.play(&quot;Please.wav&quot;);
delay(10000);
tmrpcm.play(&quot;Keephold.wav&quot;);
delay(10000);
tmrpcm.play(&quot;Remove.wav&quot;);
delay(4000);
tmrpcm.play(&quot;Thnx.wav&quot;) ;}
void loop() {}

