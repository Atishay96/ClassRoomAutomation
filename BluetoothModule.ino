String voice;
int
led1 = 9, //Connect LED 1 To Pin #9
led2 = 10, //Connect LED 2 To Pin #10
led3 = 11; //Connect LED 3 To Pin #11

//--------------------------Call A Function-------------------------------// 
void allon(){
     digitalWrite(led1, HIGH);//Will turn on LED 1
     digitalWrite(led2, HIGH);//Will turn on LED 2
     digitalWrite(led3, HIGH);//Will turn on LED 3
     
}
void alloff(){
     digitalWrite(led1, LOW);//Will turn off LED 1
     digitalWrite(led2, LOW);//Will turn off LED 2
     digitalWrite(led3, LOW);//Will turn off LED 3
     
}
//-----------------------------------------------------------------------// 
void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);//will show the output
  pinMode(led2, OUTPUT);//will show the output
  pinMode(led3, OUTPUT);//will show the output
  
}
//-----------------------------------------------------------------------// 
void loop() {
  while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  } 
  if (voice.length() > 0) {
    Serial.println(voice);
//-----------------------------------------------------------------------//   
  //----------Control Multiple Pins/ LEDs----------// 
       if(voice == "*all on") {allon();}  //Turn Off All Pins (Call Function)
  else if(voice == "*all of"){alloff();} //Turn On  All Pins (Call Function)
  else if(voice == "*all off"){alloff();} //Turn On  All Pins (Call Function)
 
  //----------Turn On One-By-One----------//
  else if(voice == "*light one on") {digitalWrite(led1, HIGH);}
  else if(voice == "*light two on") {digitalWrite(led2, HIGH);}
  else if(voice == "*light to on") {digitalWrite(led2, HIGH);}
  else if(voice == "*light three on") {digitalWrite(led3, HIGH);}
  else if(voice == "*light tree on") {digitalWrite(led3, HIGH);}
  else if(voice == "*light 3 on") {digitalWrite(led3, HIGH);}
 
  //----------Turn Off One-By-One----------//
  else if(voice == "*light one of") {digitalWrite(led1, LOW);}
  else if(voice == "*light one off") {digitalWrite(led1, LOW);}
  else if(voice == "*light two of") {digitalWrite(led2, LOW);}
  else if(voice == "*light to of") {digitalWrite(led2, LOW);}
  else if(voice == "*light two off") {digitalWrite(led2, LOW);}
  else if(voice == "*light to off") {digitalWrite(led2, LOW);}
  else if(voice == "*light three of") {digitalWrite(led3, LOW);}
  else if(voice == "*light three off") {digitalWrite(led3, LOW);}
  else if(voice == "*light 3 of") {digitalWrite(led3, LOW);}
  else if(voice == "*light 3 off") {digitalWrite(led3, LOW);}
  else if(voice == "*light tree of") {digitalWrite(led3, LOW);}
  else if(voice == "*light tree off") {digitalWrite(led3, LOW);}
 
//-----------------------------------------------------------------------// 
voice="";}} //Reset the variable after initiating

