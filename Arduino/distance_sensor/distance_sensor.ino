/* This example shows how to use continuous mode to take
range measurements with the VL53L0X. It is based on
vl53l0x_ContinuousRanging_Example.c from the VL53L0X API.

The range readings are in units of mm. */

#include <Wire.h>
#include <VL53L0X.h>

int SAMPLE_RATE_HZ = 150;

VL53L0X sensor;
float laser_cm;

// HC SR04 Fields
int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
long sonic_duration;
float sonic_cm;

unsigned long int timestamp;

void getHCSR04()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  sonic_duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  sonic_cm = (sonic_duration/2.000) / 29.100;     // Divide by 29.1 or multiply by 0.0343
}

void getVL53L0X()
{
  int dist = sensor.readRangeContinuousMillimeters();
  laser_cm = dist/10.000;
}

void serialOutputPlottable()
{
  Serial.print(laser_cm);
  Serial.print(' ');
  Serial.print(sonic_cm);
  Serial.print('\n');
}

void serialOutputWithTimestamp()
{
  Serial.print(laser_cm);
  Serial.print(' ');
  Serial.print(sonic_cm);
  Serial.print(' ');
  Serial.print(timestamp);
  Serial.print('\n');
}

void plot()
{
  Serial.print("Laser: ");
  Serial.print(laser_cm);
  Serial.print(", ");
  Serial.print("Ultrasonic: ");
  Serial.println(sonic_cm);
}

void setDefaultRange()
{
  sensor.setSignalRateLimit(0.25);
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 14);
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 10);
}

void setLongRange()
{
  sensor.setSignalRateLimit(0.1);
  // increase laser pulse periods (defaults are 14 and 10 PCLKs)
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
}

void setHighAccuracy()
{
  sensor.setMeasurementTimingBudget(200000);  
}

void setHighSpeed()
{
  sensor.setMeasurementTimingBudget(20000);
}

void setDefaultTimingBudget()
{
  sensor.setMeasurementTimingBudget(30000);
}

void setup()
{
  Serial.begin(9600);
  
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Wire.begin();
  
  sensor.setTimeout(500);
  if (!sensor.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1) {}
  }
  
  //setLongRange();
  setDefaultRange();
  //setHighAccuracy();
  //setHighSpeed();
  setDefaultTimingBudget();
  sensor.startContinuous();
  delay( 1000 );
}

void loop()
{  
  getVL53L0X();
  getHCSR04();
  timestamp = millis();
  serialOutputWithTimestamp();
  //plot();
}
