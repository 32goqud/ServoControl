#if (ARDUINO >=100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <Servo.h>
#include <ros.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle nh;

Servo servo;

void servo_cb(const std_msgs::UInt16&cmd_msg){

  servo.write(cmd_msg.data);
  digitalWrite(13, HIGH-digitalRead(13));
}

ros::Subscriber<std_msgs::UInt16> sub("servo", servo_cb);

void setup() {
  // put your setup code here, to run once:

  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  servo.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:

  nh.spinOnce();
  delay(1);
}
