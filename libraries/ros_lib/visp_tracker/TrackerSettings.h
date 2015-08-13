#ifndef _ROS_visp_tracker_TrackerSettings_h
#define _ROS_visp_tracker_TrackerSettings_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace visp_tracker
{

  class TrackerSettings : public ros::Msg
  {
    public:
      float angle_appear;
      float angle_disappear;

    TrackerSettings():
      angle_appear(0),
      angle_disappear(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->angle_appear);
      offset += serializeAvrFloat64(outbuffer + offset, this->angle_disappear);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angle_appear));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angle_disappear));
     return offset;
    }

    const char * getType(){ return "visp_tracker/TrackerSettings"; };
    const char * getMD5(){ return "3af7f3dad594635cfe340be2c0b60a68"; };

  };

}
#endif