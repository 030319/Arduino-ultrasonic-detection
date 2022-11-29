#include <LiquidCrystal.h>

#include <Servo.h>

Servo myservo;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); //

int pos = 0; 

//初始化定义
//包括距离、led灯等等
const int trigPin = 9;
const int echoPin = 10;
const int moteur = 11;
const int buzzer = 12;
const int ledPin1 = 14;
const int ledPin2 = 15;
float distanceCm, DistanceSec,duration;

//设置led灯的输入输出
void setup() 
{
myservo.attach(moteur); //
lcd.begin(16,2); // 
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
DistanceSec=20;

}

//对角度做一个循环
void loop() {
for (pos = 0; pos <= 180; pos += 1) { // 

myservo.write(pos); 
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
  
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
//距离的测量方法
distanceCm= duration*0.034/2;
  
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
  
//判断距离是否在范围内
if (distanceCm <= DistanceSec)
{

if(distanceCm <= DistanceSec/2)
{

//蜂鸣器显示
//灯2亮high
tone(buzzer, 10); // 
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, HIGH);
delay(700);
noTone(buzzer); // 
lcd.setCursor(0,0); //
lcd.print("Distance: "); // 
lcd.print(distanceCm); // 
lcd.print(" cm "); // 
delay(10);
lcd.setCursor(0,1);
lcd.print("Angle : ");
lcd.print(pos);
lcd.print(" deg ");
delay(2000);
}
  
else
{
  
//蜂鸣器high'
//灯1亮high
digitalWrite(buzzer, HIGH);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin1, HIGH);
delay(100);
digitalWrite(buzzer, LOW);
lcd.setCursor(0,0); //
lcd.print("Distance: "); // 
lcd.print(distanceCm); // 
lcd.print(" cm "); // 
delay(10);
lcd.setCursor(0,1);
lcd.print("Angle : ");
lcd.print(pos);
lcd.print(" deg ");
delay(2000);
}
}
  
//蜂鸣器、两个led灯均为low
else{
digitalWrite(buzzer, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
}

lcd.setCursor(0,0); // 
  
lcd.print("Distance: "); // 
lcd.print(distanceCm); // 
lcd.print(" cm "); // 
delay(10);
lcd.setCursor(0,1);
lcd.print("Angle : ");
lcd.print(pos);
lcd.print(" deg ");
delay(80); //

}

  //角度超出范围时
for (pos = 180; pos >= 0; pos -= 1) { //
myservo.write(pos); //
digitalWrite(trigPin, LOW);
  
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
  
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
  
if (distanceCm <= DistanceSec)
{
if(distanceCm <= DistanceSec/2)
{
  
  //蜂鸣器high'
//灯2亮high
tone(buzzer, 10); // 
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, HIGH);
delay(700);
noTone(buzzer); // 
lcd.setCursor(0,0); //
  
lcd.print("Distance: "); // 
lcd.print(distanceCm); // 
lcd.print(" cm "); // 
delay(10);
lcd.setCursor(0,1);
lcd.print("Angle : ");
lcd.print(pos);
lcd.print(" deg ");
delay(2000);
}
  
  
  //蜂鸣器high'
//灯1亮high
else
{
digitalWrite(buzzer, HIGH);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin1, HIGH);
delay(100);
digitalWrite(buzzer, LOW);
lcd.setCursor(0,0); // 
  
lcd.print("Distance: "); // 
lcd.print(distanceCm); // 
lcd.print(" cm "); // 
delay(10);
lcd.setCursor(0,1);
lcd.print("Angle : ");
lcd.print(pos);
lcd.print(" deg ");
delay(2000);
}

}
  
 //蜂鸣器、两个led灯均为low
else{
digitalWrite(buzzer, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
}

lcd.setCursor(0,0); //

//倒车距离周围物体的距离
lcd.print("Distance: "); //
lcd.print(distanceCm); //
lcd.print(" cm ");
delay(10);
lcd.setCursor(0,1);
  
//角度
lcd.print("Angle : ");
lcd.print(pos);
lcd.print(" deg ");
delay(80);
  
lcd.print("Distance: "); //
lcd.print(distanceCm); //
lcd.print(" cm ");
delay(10);
lcd.setCursor(0,1);
  
lcd.print("Angle : ");
lcd.print(pos);
lcd.print(" deg ");
delay(80);
}
}