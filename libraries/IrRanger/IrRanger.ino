/*
 * rosserial IR Ranger Example
 *
 * This example is calibrated for the Sharp GP2D120XJ00F.
 */

#include <ros.h>
#include <ros/time.h>
#include <sensor_msgs/Range.h>

ros::NodeHandle  nh;
sensor_msgs::Range range_msg;
ros::Publisher pub_range( "range_data", &range_msg);

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

float get_distance(int pin_num)
{
    int sample = analogRead(pin_num);
    voltage = sample * voltage_slope;
    // equation: a(x) = mx + b with a = 1/y
    // -> x(y) = (1/y - b) / m
    meter = ((1/voltage) - equation_offset) / equation_slope;
    return meter;
}

void setup()
{
  nh.initNode();
  nh.advertise(pub_range);

  range_msg.radiation_type = sensor_msgs::Range::INFRARED;
  range_msg.header.frame_id =  frameid;
  range_msg.field_of_view = 0.01;
  range_msg.min_range = 0.1;
  range_msg.max_range = 0.8;
}

void loop()
{
  // publish the range value every 50 milliseconds
  //   since it takes that long for the sensor to stabilize
  if ( (millis() - range_timer) > 50){
    range_msg.range = get_distance(analog_pin);
    range_msg.header.stamp = nh.now();
    pub_range.publish(&range_msg);
    range_timer =  millis();
  }
  nh.spinOnce();
}

