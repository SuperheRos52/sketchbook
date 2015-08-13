#include <ros.h>
#include <std_msgs/Int32.h>

ros::NodeHandle  nh;                        			  //Create the NodeHandle
void led_callback(const std_msgs::Int32& receive_msg)     //CallBack function
{
  if (receive_msg.data >=0)
  {
  for (int i=0; i<= receive_msg.data; i++)
  {
  digitalWrite(13, HIGH);                    //switch LED ON
  delay(100);								 //Wait for 100ms
  digitalWrite(13, LOW);                     //switch LED OFF
  delay(100);							     //Wait for 100ms
  }
 }
}
//Subscriber definition
ros::Subscriber<std_msgs::Int32> sub("led_blink", led_callback);

void setup()
{ pinMode(13, OUTPUT);
  nh.initNode();			//Initialize Node 
  nh.subscribe(sub);        //Subscriber Call
}

void loop()
{ 
  nh.spinOnce();
  delay(1);
}