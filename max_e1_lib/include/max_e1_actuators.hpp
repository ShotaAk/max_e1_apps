#ifndef MAX_E1_ACTUATORS_HPP_
#define MAX_E1_ACTUATORS_HPP_

#include "max_e1_core.hpp"

class MaxE1Actuators
{
public:
    MaxE1Actuators(const std::shared_ptr<MaxE1Core> & core);
    ~MaxE1Actuators();
    bool init();
    bool buzzer_melody(const int index=0);
    bool buzzer_scale(const int index=0, const double time_seconds=0);
    bool led(const bool red, const bool green, const bool blue);

private:
    std::shared_ptr<MaxE1Core> core_;
};

#endif