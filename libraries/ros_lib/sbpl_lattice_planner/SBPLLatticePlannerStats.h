#ifndef _ROS_sbpl_lattice_planner_SBPLLatticePlannerStats_h
#define _ROS_sbpl_lattice_planner_SBPLLatticePlannerStats_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace sbpl_lattice_planner
{

  class SBPLLatticePlannerStats : public ros::Msg
  {
    public:
      float initial_epsilon;
      float final_epsilon;
      bool plan_to_first_solution;
      float allocated_time;
      float actual_time;
      float time_to_first_solution;
      float solution_cost;
      float path_size;
      int64_t final_number_of_expands;
      int64_t number_of_expands_initial_solution;
      geometry_msgs::PoseStamped start;
      geometry_msgs::PoseStamped goal;

    SBPLLatticePlannerStats():
      initial_epsilon(0),
      final_epsilon(0),
      plan_to_first_solution(0),
      allocated_time(0),
      actual_time(0),
      time_to_first_solution(0),
      solution_cost(0),
      path_size(0),
      final_number_of_expands(0),
      number_of_expands_initial_solution(0),
      start(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->initial_epsilon);
      offset += serializeAvrFloat64(outbuffer + offset, this->final_epsilon);
      union {
        bool real;
        uint8_t base;
      } u_plan_to_first_solution;
      u_plan_to_first_solution.real = this->plan_to_first_solution;
      *(outbuffer + offset + 0) = (u_plan_to_first_solution.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->plan_to_first_solution);
      offset += serializeAvrFloat64(outbuffer + offset, this->allocated_time);
      offset += serializeAvrFloat64(outbuffer + offset, this->actual_time);
      offset += serializeAvrFloat64(outbuffer + offset, this->time_to_first_solution);
      offset += serializeAvrFloat64(outbuffer + offset, this->solution_cost);
      offset += serializeAvrFloat64(outbuffer + offset, this->path_size);
      union {
        int64_t real;
        uint64_t base;
      } u_final_number_of_expands;
      u_final_number_of_expands.real = this->final_number_of_expands;
      *(outbuffer + offset + 0) = (u_final_number_of_expands.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_final_number_of_expands.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_final_number_of_expands.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_final_number_of_expands.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_final_number_of_expands.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_final_number_of_expands.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_final_number_of_expands.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_final_number_of_expands.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->final_number_of_expands);
      union {
        int64_t real;
        uint64_t base;
      } u_number_of_expands_initial_solution;
      u_number_of_expands_initial_solution.real = this->number_of_expands_initial_solution;
      *(outbuffer + offset + 0) = (u_number_of_expands_initial_solution.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_number_of_expands_initial_solution.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_number_of_expands_initial_solution.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_number_of_expands_initial_solution.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_number_of_expands_initial_solution.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_number_of_expands_initial_solution.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_number_of_expands_initial_solution.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_number_of_expands_initial_solution.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->number_of_expands_initial_solution);
      offset += this->start.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->initial_epsilon));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->final_epsilon));
      union {
        bool real;
        uint8_t base;
      } u_plan_to_first_solution;
      u_plan_to_first_solution.base = 0;
      u_plan_to_first_solution.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->plan_to_first_solution = u_plan_to_first_solution.real;
      offset += sizeof(this->plan_to_first_solution);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->allocated_time));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->actual_time));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->time_to_first_solution));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->solution_cost));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->path_size));
      union {
        int64_t real;
        uint64_t base;
      } u_final_number_of_expands;
      u_final_number_of_expands.base = 0;
      u_final_number_of_expands.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_final_number_of_expands.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_final_number_of_expands.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_final_number_of_expands.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_final_number_of_expands.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_final_number_of_expands.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_final_number_of_expands.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_final_number_of_expands.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->final_number_of_expands = u_final_number_of_expands.real;
      offset += sizeof(this->final_number_of_expands);
      union {
        int64_t real;
        uint64_t base;
      } u_number_of_expands_initial_solution;
      u_number_of_expands_initial_solution.base = 0;
      u_number_of_expands_initial_solution.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_number_of_expands_initial_solution.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_number_of_expands_initial_solution.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_number_of_expands_initial_solution.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_number_of_expands_initial_solution.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_number_of_expands_initial_solution.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_number_of_expands_initial_solution.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_number_of_expands_initial_solution.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->number_of_expands_initial_solution = u_number_of_expands_initial_solution.real;
      offset += sizeof(this->number_of_expands_initial_solution);
      offset += this->start.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "sbpl_lattice_planner/SBPLLatticePlannerStats"; };
    const char * getMD5(){ return "b1c85b1cec5e7b196cc477ac1440bbf0"; };

  };

}
#endif