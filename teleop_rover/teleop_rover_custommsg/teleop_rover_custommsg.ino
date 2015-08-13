#include <Servo.h> 
#include <ros.h>
#include <std_msgs/Int32.h>
#include <geometry_msgs/Twist.h>
#include <ros/time.h>
#include <sensor_msgs/Range.h>

Servo myservoX;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
Servo myservoZ;

int pos = 90;    // variable to store the servo position 
int xAxis = 1450;
int zAxis = 1350 ;
const int analog_pin = 8;
unsigned long range_timer;
char frameid[] = "/ir_ranger";

float v_ref = 5.0;
float adc_max = 1024.0;
float voltage_slope = (v_ref/adc_max);

float equation_offset = 0.1836092228;
float equation_slope = 2.5513414751;
float calibration_offset = 0.02;
float voltage, meter = 0.0;


ros::NodeHandle  nh;
sensor_msgs::Range range_msg;
ros::Publisher pub_range( "range", &range_msg);
			  //Create the NodeHandle


void servo_callback(const geometry_msgs::Twist& receive_msg)     //CallBack function
{
  
    //speed = map(receive_msg.linear.x, -1.0 ,1.0,1350,1550);
    xAxis = floor(receive_msg.linear.x * 200 + 1450) ; 
    zAxis = floor(receive_msg.angular.z * 250 + 1350) ; 
 }


float get_distance(int pin_num)
{
    int sample = analogRead(pin_num);
    voltage = sample * voltage_slope;
    // equation: a(x) = mx + b with a = 1/y
    // -> x(y) = (1/y - b) / m
    meter = ((1/voltage) - equation_offset) / equation_slope;
    return meter;
}
//Subscriber definition
ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", servo_callback);

 
void setup() 
{ 
  myservoX.attach(2);  // attaches the servo on pin 5 to the servo object 
  myservoZ.attach(5);
  nh.initNode();			//Initialize Node 
  nh.subscribe(sub);        //Subscriber Call
  
  
  
  
  nh.advertise(pub_range);

  range_msg.radiation_type = sensor_msgs::Range::INFRARED;
  range_msg.header.frame_id =  frameid;
  range_msg.field_of_view = 0.01;
  range_msg.min_range = 0.1;
  range_msg.max_range = 0.8;
} 
 
 
void loop() 
{ 
  myservoX.writeMicroseconds(xAxis);
  myservoZ.writeMicroseconds(zAxis);
  
  if ( (millis() - range_timer) > 50){
    range_msg.range = get_distance(analog_pin);
    range_msg.header.stamp = nh.now();
    pub_range.publish(&range_msg);
    range_timer =  millis();
  }
  
  nh.spinOnce();
  delay(1);
  
  
  
  
} 
