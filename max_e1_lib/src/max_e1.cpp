
#include "max_e1.hpp"

MaxE1::MaxE1(const std::string device_name, const int baudrate)
{
    core_ = std::make_shared<MaxE1Core>(device_name, baudrate);
}

MaxE1::~MaxE1()
{
    disconnect();
}

bool MaxE1::connect()
{
    bool result = core_->open_port();
    sensors = std::make_shared<MaxE1Sensors>(core_);
    return result;
}

void MaxE1::disconnect()
{
    core_->close_port();
}
