#ifndef _ROS_SERVICE_SetArmsEnabled_h
#define _ROS_SERVICE_SetArmsEnabled_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace naoqi_msgs
{

static const char SETARMSENABLED[] = "naoqi_msgs/SetArmsEnabled";

  class SetArmsEnabledRequest : public ros::Msg
  {
    public:
      bool left_arm;
      bool right_arm;

    SetArmsEnabledRequest():
      left_arm(0),
      right_arm(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_left_arm;
      u_left_arm.real = this->left_arm;
      *(outbuffer + offset + 0) = (u_left_arm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->left_arm);
      union {
        bool real;
        uint8_t base;
      } u_right_arm;
      u_right_arm.real = this->right_arm;
      *(outbuffer + offset + 0) = (u_right_arm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->right_arm);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_left_arm;
      u_left_arm.base = 0;
      u_left_arm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->left_arm = u_left_arm.real;
      offset += sizeof(this->left_arm);
      union {
        bool real;
        uint8_t base;
      } u_right_arm;
      u_right_arm.base = 0;
      u_right_arm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->right_arm = u_right_arm.real;
      offset += sizeof(this->right_arm);
     return offset;
    }

    const char * getType(){ return SETARMSENABLED; };
    const char * getMD5(){ return "4da9069facca935244c3405e288ba555"; };

  };

  class SetArmsEnabledResponse : public ros::Msg
  {
    public:

    SetArmsEnabledResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return SETARMSENABLED; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetArmsEnabled {
    public:
    typedef SetArmsEnabledRequest Request;
    typedef SetArmsEnabledResponse Response;
  };

}
#endif
