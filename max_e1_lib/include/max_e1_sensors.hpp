#ifndef MAX_E1_SENSORS_HPP_
#define MAX_E1_SENSORS_HPP_

#include "max_e1_core.hpp"

class MaxE1Sensors
{
public:
    MaxE1Sensors(const std::shared_ptr<MaxE1Core> & core);
    ~MaxE1Sensors();
    bool update();
    int get_temperature();

private:
    std::shared_ptr<MaxE1Core> core_;
    int temperature_;
};

#endif