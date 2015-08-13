#include <ros.h>
#include <ros/time.h>
#include <crius_com/ir_rawdata.h>

//ROS declarations
ros::NodeHandle nh;									//Setup NodeHandle
crius_com::ir_rawdata custom_msg;					//Create message instance
ros::Publisher pub_dist("ir_data", &custom_msg);	//Initialize Publisher

//IR Sensor settings
const int analog_pin = A8;							//Input pin on the crius
unsigned int range_time;

//ADC declarations
float v_ref   = 5.0;								//Reference voltage for ADC conversion
float adc_max = 1024.0;								//10-bit ADC
float voltage_slope = (v_ref/adc_max);

//Calculation of Distance (values from datasheet)
float eqn_offset = 0.1836092;
float eqn_slope = 2.5513414;
float cal_offset = 0.02;
float analog_vol ;
float dist_mtr = 0.0;

float get_dist(int analog_pin)						  //Convert sensor voltage to distance
{
  pinMode(analog_pin, INPUT);    						//Force input mode
  float input  = analogRead(analog_pin);		//Read sensor voltage
  analog_vol = input * voltage_slope;
  dist_mtr = ((1/analog_vol)- eqn_offset)/eqn_slope;	//Converts volts to meters
  return dist_mtr;									                  //Return distance
}

void setup()
{  
  //ROS node setup 
  nh.initNode();										//Initialize Node
  nh.advertise(pub_dist);						//Publisher Call
  custom_msg.min_range = 1.5;				//Max Range is 1.5m
  custom_msg.max_range = 0.2;				//Min Range is 0.2m
}

void loop()
{
  custom_msg.distance = get_dist(analog_pin);
  delay(50);									//Wait 50 msec for sensor to stabilize
  pub_dist.publish(&custom_msg);				//Publish message  
  
  nh.spinOnce(); 
}
