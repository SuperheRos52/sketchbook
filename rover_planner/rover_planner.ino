#include "Arduino.h"
#include <Servo.h> 		//Header file to operate Servos 
#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <ros/time.h>
#include <sensor_msgs/Range.h>

  //-------------------> Servo Motor Declarations
    Servo servo_drive;         //Servo object 1 for steering 
    Servo servo_steer;           //Servo object 2 for moving
    float input_drive = 1450;  //float value for PWM1 signal 	
    float input_steer = 1350;  //float value for PWM2 signal 
    
    bool positiv = false;     //flag to avoid brushless motor behavior


  //-------------------> IR Sensor Declarations
    const int analog_pin = A8;              //analog input pin for the IR sensor
    unsigned long range_time;   //variable of the ROS time for the ROS range msg
    char frame_id[] = "ir_sensor";  //variable of frame id for the ROS range msg

  //-------------------> ADC declarations
    float v_ref   = 5.0;
    float adc_max = 1024.0;
    float voltage_slope = (v_ref/adc_max);

  //-------------------> Calculations
    float eqn_offset = 0.1836092;
    
    float eqn_slope = 2.5513414;
    float cal_offset = 0.02;
    float analog_vol ;
    float dist_mtr = 0.0;
    
  

  //-------------------> Function to fetch sensor data and return distance
    float get_dist(int analog_pin)
      {
        pinMode(analog_pin, INPUT);
        float input  = analogRead(analog_pin);
        analog_vol = input * voltage_slope;
        dist_mtr = ((1/analog_vol)- eqn_offset)/eqn_slope;
        
        return dist_mtr;
      }

  //-------------------> Initialize ROS Node
    ros::NodeHandle  nh;       //Create NodeHandle

  //-------------------> CallBack function of Subscriber
  
    void servo_callback( const geometry_msgs::Twist& cmd_msg)     
    {
      float linear;
      
      if (cmd_msg.linear.x < 0.0 && positiv)      //sending a zero command
          {
            servo_drive.writeMicroseconds(1450);  //to avoid brushless motor behavior
            delay(500);
          }
      
      if (cmd_msg.linear.x > 0.0)
          positiv = true;
      else
          positiv = false;
          
      if (cmd_msg.linear.x > 0.0 && cmd_msg.linear.x < 0.5)
          linear = 0.5;    
      else if (cmd_msg.linear.x < 0.0 && cmd_msg.linear.x > -0.5)
          linear = -0.5;
      else
          linear = cmd_msg.linear.x;    
          
      //---> map function converts incoming data to PWM Signal
      //---> map function works for integer values only !!! 
      input_drive = map(linear*100,-100,100,1300,1600);   //PWM1 Signal
      input_steer = map(cmd_msg.angular.z*100,-100,100,1050,1650);  	//PWM2 Signal
      //digitalWrite(13, !digitalRead(13));                  //Toggle LED (Debug) 
   
    }

  //-------------------> Subscriber definition
    ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", servo_callback);

  //-------------------> Initialize Publisher and ROS msg for the range data
    sensor_msgs::Range range_msg;
    ros::Publisher pub_dist("range", &range_msg);

  void setup()
  {
    //-------------------> LED
      //pinMode(13, OUTPUT);             //LED (Debug)
    
    //-------------------> Servo
      pinMode(2, OUTPUT);     //Servo motor for moving
      pinMode(5, OUTPUT);   //Servo motor for steering
      servo_drive.attach(2);     //PWM1 Pin assignment
      servo_steer.attach(5);     //PWM2 Pin assignment
    
    //-------------------> IR-Sensor
      pinMode(A8, INPUT);		//IR Sensor
    
    //-------------------> Node functions
      nh.initNode();      //Initialize the ROS Node
      nh.subscribe(sub);    //Servo Subscriber Call
      nh.advertise(pub_dist);   //IR publisher call 
    
    //-------------------> ROS message range_msg header setup
      range_msg.radiation_type = sensor_msgs::Range::INFRARED;
      range_msg.header.frame_id = frame_id;
      range_msg.field_of_view = 0.01;
      range_msg.min_range = 0.01;
      range_msg.max_range = 0.8;
  }
  
  void loop()
  {
    //-------------------> IR Sensor Data publish to ROS
      if ((millis() - range_time)>50)  //publish at intervals of 50 milli seconds
      {
        range_msg.range = get_dist(analog_pin);
        range_msg.header.stamp = nh.now();
        pub_dist.publish(&range_msg);	
        range_time = millis();
      }
    
    //-------------------> Drive Motors using PWM
      servo_drive.writeMicroseconds(input_drive);    //create PWM1 signal 
      servo_steer.writeMicroseconds(input_steer);    //create PWM2 signal 
      


        
     
      nh.spinOnce();		
      delay(1);
}
