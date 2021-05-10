
#include "max_e1_sensors.hpp"

constexpr uint16_t ADDR_TEMPERATURE = 90;

MaxE1Sensors::MaxE1Sensors(const std::shared_ptr<MaxE1Core> & core)
    : core_(core)
{
}

MaxE1Sensors::~MaxE1Sensors()
{
}

bool MaxE1Sensors::update()
{
    uint8_t data;
    core_->read_1byte(ADDR_TEMPERATURE, &data);
    temperature_ = data;

    return true;
}

int MaxE1Sensors::get_temperature()
{
    return temperature_;
}