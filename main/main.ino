#include <SimpleDHT.h>
#include <SoftwareSerial.h>
#include <Wire.h>

SoftwareSerial I2CBT(13, 12);

int mode = -1 , light1 = 0, light2 = 0, light3 = 0, light4 = 0, heatMat = 0;
byte temperature = 0, humidity = 0;
SimpleDHT11 dht11;

const byte trigPin = 8;
const int echoPin = 7;
const byte trigPin2 = 4;
const int echoPin2 = 3;

byte cmmd[20];
int insize;
unsigned long d, d2;

void setup() {
  Serial.begin(9600);
  Serial.println("Connect success");
  I2CBT.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(trigPin , OUTPUT);
  pinMode(echoPin , INPUT);
  pinMode(trigPin2 , OUTPUT);
  pinMode(echoPin2 , INPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  int err = SimpleDHTErrSuccess;
  
  if ((err = dht11.read(2, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    //  return;
  }
  
  d = ping() / 58;
  d2 = ping2() / 58;
  delay(1000);
  Serial.print("sensor:");
  Serial.println(sensorValue);
  Serial.print("tmp:");
  Serial.println(temperature);
  Serial.print("dis:");
  Serial.println(d);
  Serial.print("dis2:");
  Serial.println(d2);
  Serial.print("mode:");
  Serial.println(mode);

  readBT();
  
  if (cmmd[0] == 'a') {
    mode = 0;
  }else if (cmmd[0] == 't' && cmmd[1] == '1') {
    mode = 1;
  }
  else if (cmmd[0] == 't' && cmmd[1] == '2') {
    mode = 1;
  }
  else if (cmmd[0] == 't' && cmmd[1] == '3') {
    mode = 1;
  }
  
  if (mode == 0) {
    readBT();
    
    switch (cmmd[0]) {
      case 'c':
        readNum(light1);
        break;
      case 'd':
        readNum(light2);
        break;
      case 'e':
        readNum(light3);
        break;
      case 'f':
        readNum(light4);
        break;
      case 'g':
        readNum(heatMat);
        break;
      case 'x':
        light1 = light2 = light3 = light4 = heatMat = 1;
        break;
    }
    
    analogWrite(11, map(light1, 1, 9, 0, 255));
    analogWrite(10, map(light2, 1, 9, 0, 255));
    analogWrite(9, map(light3, 1, 9, 0, 255));
    analogWrite(6, map(light4, 1, 9, 0, 255));
    analogWrite(5, map(heatMat, 1, 9, 0, 255));

    String report = "Temperature=";
    report += temperature;
    report += "'C\nHumidity=";
    report += humidity;
    report += "%";
    I2CBT.print(report);
  }
  else if (mode == 1) {
    int lightPower = -(temperature - 27);
    Serial.print("lightPower:");
    Serial.println(lightPower);
    if (sensorValue >= 41) {
      if (temperature <= 30) {
        if (d <= 10 && d2 <= 10) {
          light2 = light3 = light4 = heatMat = -10;
          light1 = lightPower;
        }
        else if (d <= 10 && d2 >= 10) {
          light1 = light3 = light4 = heatMat = -10;
          light2 = lightPower;
        }
        else if (d >= 10 && d2 <= 10) {
          light2 = light1 = light4 = heatMat = -10;
          light3 = lightPower;
        }
        else if (d >= 10 && d2 >= 10) {
          light2 = light3 = light1 = heatMat = -10;
          light4 = lightPower;
        }
      }
    }
    else if (sensorValue <= 40) {
      light1 = light2 = light3 = light4 = -10;
      heatMat = lightPower;
      analogWrite(5, map(heatMat, -10, 27, 0, 255));
    }

    analogWrite(11, map(light1, -10,  27, 0, 255));
    analogWrite(10, map(light2, -10,  27, 0, 255));
    analogWrite(9, map(light3, -10,  27, 0, 255));
    analogWrite(6, map(light4, -10,  27, 0, 255));
    analogWrite(5, map(heatMat, -10,  27, 0, 255));

    String report = "Temperature=";
    report += temperature;
    report += "'C\nHumidity=";
    report += humidity;
    report += "%\nLight1=";
    report += map(light1, -10, 27, 0, 9);
    report += "\nLight2=";
    report += map(light2, -10, 27, 0, 9);
    report += "\nLight3=";
    report += map(light3, -10, 27, 0, 9);
    report += "\nLight4=";
    report += map(light4, -10, 27, 0, 9);
    report += "\nHeatMat=";
    report += map(heatMat, -10, 27, 0, 9);
    I2CBT.print(report);

  }
  Serial.println("");
}

void readBT() {
  if ((insize = (I2CBT.available())) > 0) {
    Serial.print("input size = ");
    Serial.println(insize);
    for (int i = 0; i < insize; i++) {
      Serial.print(cmmd[i] = char(I2CBT.read()));
    }
    Serial.println("");
  }
}

void readNum(int &input) {
  int tmp = 0;
  tmp += (int)(cmmd[1] - 48);
  input = tmp;
}

unsigned long ping() {
  digitalWrite(trigPin , HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin , LOW);

  return pulseIn(echoPin, HIGH , 23200);
}
unsigned long ping2() {
  digitalWrite(trigPin2 , HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2 , LOW);

  return pulseIn(echoPin2, HIGH , 23200);
}