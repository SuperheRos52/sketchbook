#ifndef _ROS_visp_tracker_KltSettings_h
#define _ROS_visp_tracker_KltSettings_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace visp_tracker
{

  class KltSettings : public ros::Msg
  {
    public:
      int64_t max_features;
      int64_t window_size;
      float quality;
      float min_distance;
      float harris;
      int64_t size_block;
      int64_t pyramid_lvl;
      float angle_appear;
      float angle_disappear;
      int64_t mask_border;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_max_features;
      u_max_features.real = this->max_features;
      *(outbuffer + offset + 0) = (u_max_features.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_features.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_features.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_features.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_max_features.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_max_features.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_max_features.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_max_features.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->max_features);
      union {
        int64_t real;
        uint64_t base;
      } u_window_size;
      u_window_size.real = this->window_size;
      *(outbuffer + offset + 0) = (u_window_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_window_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_window_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_window_size.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_window_size.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_window_size.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_window_size.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_window_size.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->window_size);
      offset += serializeAvrFloat64(outbuffer + offset, this->quality);
      offset += serializeAvrFloat64(outbuffer + offset, this->min_distance);
      offset += serializeAvrFloat64(outbuffer + offset, this->harris);
      union {
        int64_t real;
        uint64_t base;
      } u_size_block;
      u_size_block.real = this->size_block;
      *(outbuffer + offset + 0) = (u_size_block.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_size_block.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_size_block.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_size_block.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_size_block.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_size_block.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_size_block.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_size_block.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->size_block);
      union {
        int64_t real;
        uint64_t base;
      } u_pyramid_lvl;
      u_pyramid_lvl.real = this->pyramid_lvl;
      *(outbuffer + offset + 0) = (u_pyramid_lvl.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pyramid_lvl.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pyramid_lvl.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pyramid_lvl.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pyramid_lvl.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pyramid_lvl.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pyramid_lvl.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pyramid_lvl.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pyramid_lvl);
      offset += serializeAvrFloat64(outbuffer + offset, this->angle_appear);
      offset += serializeAvrFloat64(outbuffer + offset, this->angle_disappear);
      union {
        int64_t real;
        uint64_t base;
      } u_mask_border;
      u_mask_border.real = this->mask_border;
      *(outbuffer + offset + 0) = (u_mask_border.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mask_border.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mask_border.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mask_border.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_mask_border.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_mask_border.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_mask_border.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_mask_border.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->mask_border);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_max_features;
      u_max_features.base = 0;
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->max_features = u_max_features.real;
      offset += sizeof(this->max_features);
      union {
        int64_t real;
        uint64_t base;
      } u_window_size;
      u_window_size.base = 0;
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->window_size = u_window_size.real;
      offset += sizeof(this->window_size);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->quality));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->min_distance));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->harris));
      union {
        int64_t real;
        uint64_t base;
      } u_size_block;
      u_size_block.base = 0;
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->size_block = u_size_block.real;
      offset += sizeof(this->size_block);
      union {
        int64_t real;
        uint64_t base;
      } u_pyramid_lvl;
      u_pyramid_lvl.base = 0;
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pyramid_lvl = u_pyramid_lvl.real;
      offset += sizeof(this->pyramid_lvl);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angle_appear));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angle_disappear));
      union {
        int64_t real;
        uint64_t base;
      } u_mask_border;
      u_mask_border.base = 0;
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->mask_border = u_mask_border.real;
      offset += sizeof(this->mask_border);
     return offset;
    }

    const char * getType(){ return "visp_tracker/KltSettings"; };
    const char * getMD5(){ return "a9f61cd7210b4d3872b77b5d1101b830"; };

  };

}
#endif