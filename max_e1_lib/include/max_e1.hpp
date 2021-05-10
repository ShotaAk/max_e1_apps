#ifndef MAX_E1_HPP_
#define MAX_E1_HPP_

#include "max_e1_core.hpp"
#include "max_e1_sensors.hpp"

class MaxE1
{
public:
    MaxE1(const std::string device_name, const int baudrate);
    ~MaxE1();
    bool connect();
    void disconnect();
    std::shared_ptr<MaxE1Sensors> sensors;

private:
    std::shared_ptr<MaxE1Core> core_;
};

#endif