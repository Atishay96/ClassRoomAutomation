int k=0;
const int in = A2 ;
const int out = A5 ;
const int led1 = 9;//Connect LED 1 To Pin #9
const int led2 =10;//Connect LED 2 To Pin #10
const int led3 =11;//Connect LED 3 To Pin #11
void setup() {
  Serial.begin(9600);
 pinMode (in,INPUT);
 pinMode (out,INPUT);
 pinMode (led1,OUTPUT);
 pinMode (led2,OUTPUT);
 pinMode (led3,OUTPUT);
 // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
if (analogRead(in) >= 220)
{
 k++;
 delay(2000);
}
 if (analogRead(out)>=220)
{
  k--;
  delay(2000);
}
   if (k <= 0)//there are no students in the class
  {
    digitalWrite (led1,LOW);//Will turn off Led 1
    digitalWrite (led2,LOW);//WIll turn off Led 2
    Serial.println(k);//Will print current number of students on Serial Monitor
  }
    if (k != 0 && k <= 6 )//If students are less than 7 and more than 0
  {
    digitalWrite (led1,HIGH);//Will turn on Led 1
    digitalWrite (led2,LOW);//WIll turn off Led 2
    Serial.println(k);//Will print current number of students on Serial Monitor
  }
  if (k >=7 && k <= 12)//If students are less than 13 and more than 6
  {
    digitalWrite (led2,HIGH);//Will turn on Led 2
    digitalWrite(led3,LOW);//Will turn off Led 3
    Serial.println(k);//Will print current number of students on Serial Monitor
  }
  if (k>=13)//If students are more than or equal to 13
  {
    digitalWrite(led3,HIGH);//Will turn on Led 3
    Serial.println(k);}//Will print current number of students in the class on Serial Monitor
  }

