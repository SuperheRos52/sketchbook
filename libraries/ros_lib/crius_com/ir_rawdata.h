#ifndef _ROS_crius_com_ir_rawdata_h
#define _ROS_crius_com_ir_rawdata_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace crius_com
{

  class ir_rawdata : public ros::Msg
  {
    public:
      float distance;
      float min_range;
      float max_range;

    ir_rawdata():
      distance(0),
      min_range(0),
      max_range(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.real = this->distance;
      *(outbuffer + offset + 0) = (u_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance);
      union {
        float real;
        uint32_t base;
      } u_min_range;
      u_min_range.real = this->min_range;
      *(outbuffer + offset + 0) = (u_min_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_range);
      union {
        float real;
        uint32_t base;
      } u_max_range;
      u_max_range.real = this->max_range;
      *(outbuffer + offset + 0) = (u_max_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_range);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.base = 0;
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance = u_distance.real;
      offset += sizeof(this->distance);
      union {
        float real;
        uint32_t base;
      } u_min_range;
      u_min_range.base = 0;
      u_min_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_range = u_min_range.real;
      offset += sizeof(this->min_range);
      union {
        float real;
        uint32_t base;
      } u_max_range;
      u_max_range.base = 0;
      u_max_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_range = u_max_range.real;
      offset += sizeof(this->max_range);
     return offset;
    }

    const char * getType(){ return "crius_com/ir_rawdata"; };
    const char * getMD5(){ return "cd59025b9292f9481ab3a805c9f24bca"; };

  };

}
#endif