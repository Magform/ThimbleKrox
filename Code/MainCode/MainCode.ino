//Code to control the mouse pointer through the movement of a finger
//To calibrate the device run "ThimbleKrox calibration code" and follow the tutorial at https://github.com/Magform/ThimbleKrox
//The lines that need to be changed for calibration have "//calibration line" 
//code write by Magform

#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <Mouse.h>

MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int vx, vy;
int sensibility=10;                  //Change this value to change the sensitivity of the device
        

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
  if (!mpu.testConnection()) {       //check connection with the MPU-6050, if there is no connection stop to work
    while (1);
    }
}

void up(){
  Mouse.move(0, -sensibility);
  }
void down(){
  Mouse.move(0, sensibility);
  }
void left(){
  Mouse.move(-sensibility, 0);
  }
void right(){
  Mouse.move(sensibility, 0);
  }


void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  
  if(ax>=15000){                          //calibration line
    right();
  }
  if(ax<=-9000){                         //calibration line
    left();
  }
    
  if(ay<=-8000){                          //calibration line
    up();
  }
  if(ay>=10000){                          //calibration line
    down();
  }

//uncomment the following lines to set the right click with a sprint up and the left click with a sprint down (Work in progress part)
/*
  if(gy>=20000){                         //calibration line        
    Mouse.click(MOUSE_RIGHT);
    delay(100);
  }
  if(gy<=-20000){                        //calibration line
    Mouse.click(MOUSE_LEFT);
    delay(100);
  }
*/

delay(10);
}
