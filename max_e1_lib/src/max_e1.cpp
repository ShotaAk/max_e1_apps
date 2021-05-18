
#include <iostream>
#include "max_e1.hpp"

// CM-550 e-manual:https://emanual.robotis.com/docs/en/parts/controller/cm-550/
constexpr uint16_t ADDR_MODE_NUMBER = 21;

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
    actuators = std::make_shared<MaxE1Actuators>(core_);
    motions = std::make_shared<MaxE1Motions>(core_);
    
    return result;
}

void MaxE1::disconnect()
{
    core_->close_port();
}

bool MaxE1::init()
{
    std::cout<<"MaxE1 init() is called."<<std::endl;

    core_->write_1byte(ADDR_MODE_NUMBER, 2);  // モードをIDLEに変更
    uint8_t data=100;
    core_->read_1byte(ADDR_MODE_NUMBER,&data);
    std::cout<<"Mode:"<<std::to_string(data)<<std::endl;

    sensors->init();
    actuators->init();
    motions->init();
    return true;
}
