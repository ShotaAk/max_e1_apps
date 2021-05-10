
#include "max_e1_sensors.hpp"

constexpr uint16_t ADDR_VOLTAGE = 89;
constexpr uint16_t ADDR_TEMPERATURE = 90;

MaxE1Sensors::MaxE1Sensors(const std::shared_ptr<MaxE1Core> & core)
    : core_(core), temperature_(0)
{
}

MaxE1Sensors::~MaxE1Sensors()
{
}

bool MaxE1Sensors::update()
{
    uint8_t data;
    if(core_->read_1byte(ADDR_VOLTAGE, &data))
        voltage_ = to_real_voltage(data);
    if(core_->read_1byte(ADDR_TEMPERATURE, &data))
        temperature_ = data;

    return true;
}

double MaxE1Sensors::get_voltage()
{
    return voltage_;
}

int MaxE1Sensors::get_temperature()
{
    return temperature_;
}


double MaxE1Sensors::to_real_voltage(const int raw_voltage)
{
    const double UNIT = 0.1;  // Volts
    return raw_voltage * UNIT;
}