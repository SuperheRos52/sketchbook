#ifndef _ROS_street_environment_Waypoints_h
#define _ROS_street_environment_Waypoints_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"

namespace street_environment
{

  class Waypoints : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t position_length;
      geometry_msgs::Point st_position;
      geometry_msgs::Point * position;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = position_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < position_length; i++){
      offset += this->position[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t position_lengthT = *(inbuffer + offset++);
      if(position_lengthT > position_length)
        this->position = (geometry_msgs::Point*)realloc(this->position, position_lengthT * sizeof(geometry_msgs::Point));
      offset += 3;
      position_length = position_lengthT;
      for( uint8_t i = 0; i < position_length; i++){
      offset += this->st_position.deserialize(inbuffer + offset);
        memcpy( &(this->position[i]), &(this->st_position), sizeof(geometry_msgs::Point));
      }
     return offset;
    }

    const char * getType(){ return "street_environment/Waypoints"; };
    const char * getMD5(){ return "462c48acc786f8a133a7a96467f0b02e"; };

  };

}
#endif