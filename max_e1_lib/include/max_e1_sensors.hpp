#ifndef MAX_E1_SENSORS_HPP_
#define MAX_E1_SENSORS_HPP_

#include "max_e1_core.hpp"

class MaxE1Sensors
{
public:
    MaxE1Sensors(const std::shared_ptr<MaxE1Core> & core);
    ~MaxE1Sensors();
    bool update();
    double get_voltage();
    int get_temperature();

private:
    double to_real_voltage(const int raw_voltage);

    std::shared_ptr<MaxE1Core> core_;
    int temperature_;
    double voltage_;
};

#endif