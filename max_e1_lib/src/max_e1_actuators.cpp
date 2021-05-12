
#include <iostream>
#include <algorithm>
#include "max_e1_actuators.hpp"

// CM-550 e-manual:https://emanual.robotis.com/docs/en/parts/controller/cm-550/
constexpr uint16_t ADDR_BUZZER_INDEX = 84;
constexpr uint16_t ADDR_BUZZER_TIME = 85;
constexpr uint16_t ADDR_RED_LED = 91;
constexpr uint16_t ADDR_GREEN_LED = 92;
constexpr uint16_t ADDR_BLUE_LED = 93;

constexpr uint8_t BUZZER_MODE_MELODY = 255;
constexpr uint8_t BUZZER_MODE_SCALE = 0;

MaxE1Actuators::MaxE1Actuators(const std::shared_ptr<MaxE1Core> & core)
    : core_(core)
{
}

MaxE1Actuators::~MaxE1Actuators()
{
}

bool MaxE1Actuators::init()
{
    std::cout<<"Actuators init() is called."<<std::endl;
    return true;
}

bool MaxE1Actuators::buzzer_melody(const int index)
{
    const int MAX_MELODY_INDEX = 25;
    const int MIN_MELODY_INDEX = 0;

    core_->write_1byte(ADDR_BUZZER_TIME, BUZZER_MODE_MELODY);

    return core_->write_1byte(
        ADDR_BUZZER_INDEX,
        std::clamp(index, MIN_MELODY_INDEX, MAX_MELODY_INDEX));
}


bool MaxE1Actuators::buzzer_scale(const int index, const double time_seconds)
{
    const int MAX_SCALE_INDEX = 51;
    const int MIN_SCALE_INDEX = 0;
    const int MAX_PLAY_TIME = 50;

    int buzzer_time = time_seconds * 10;
    core_->write_1byte(ADDR_BUZZER_TIME,
        std::clamp(buzzer_time, 0, MAX_PLAY_TIME));

    return core_->write_1byte(
        ADDR_BUZZER_INDEX,
        std::clamp(index, MIN_SCALE_INDEX, MAX_SCALE_INDEX));
}

bool MaxE1Actuators::led(const bool red, const bool green, const bool blue)
{
    if(core_->write_1byte(ADDR_RED_LED, red) && 
        core_->write_1byte(ADDR_GREEN_LED, green) &&
        core_->write_1byte(ADDR_BLUE_LED, blue)){
        return true;
    }else{
        return false;
    }
}
