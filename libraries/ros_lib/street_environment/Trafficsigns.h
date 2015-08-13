#ifndef _ROS_street_environment_Trafficsigns_h
#define _ROS_street_environment_Trafficsigns_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "street_environment/Trafficsign.h"

namespace street_environment
{

  class Trafficsigns : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t signs_length;
      street_environment::Trafficsign st_signs;
      street_environment::Trafficsign * signs;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = signs_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < signs_length; i++){
      offset += this->signs[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t signs_lengthT = *(inbuffer + offset++);
      if(signs_lengthT > signs_length)
        this->signs = (street_environment::Trafficsign*)realloc(this->signs, signs_lengthT * sizeof(street_environment::Trafficsign));
      offset += 3;
      signs_length = signs_lengthT;
      for( uint8_t i = 0; i < signs_length; i++){
      offset += this->st_signs.deserialize(inbuffer + offset);
        memcpy( &(this->signs[i]), &(this->st_signs), sizeof(street_environment::Trafficsign));
      }
     return offset;
    }

    const char * getType(){ return "street_environment/Trafficsigns"; };
    const char * getMD5(){ return "5150c516715ee7c22c8043458024d5d9"; };

  };

}
#endif