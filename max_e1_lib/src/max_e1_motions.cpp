
#include <iostream>
#include <algorithm>
#include "max_e1_motions.hpp"

// CM-550 e-manual:https://emanual.robotis.com/docs/en/parts/controller/cm-550/
constexpr uint16_t ADDR_MOTION_INDEX_NUMBER = 66;
constexpr uint16_t ADDR_MOTION_PLAY_STATUS = 68;

constexpr uint16_t INDEX_STOP_WITH_EXIT_UNIT = 0;
constexpr uint16_t INDEX_STOP_IMMEDIATELY = 65533;
constexpr uint16_t INDEX_STOP_KEY_FRAME = 65534;
constexpr uint16_t INDEX_STOP_UNIT = 65535;

MaxE1Motions::MaxE1Motions(const std::shared_ptr<MaxE1Core> & core)
    : core_(core)
{
}

MaxE1Motions::~MaxE1Motions()
{
}

bool MaxE1Motions::init()
{
    std::cout<<"Motions init() is called."<<std::endl;
    return true;
}

bool MaxE1Motions::play(const int index)
{
    const int MAX_INDEX = 65532;
    const int MIN_INDEX = 1;

    if(index < MIN_INDEX || index > MAX_INDEX){
        std::cout << "Invalid index:" << std::to_string(index) << std::endl;
        return false;
    }

    return core_->write_2bytes(ADDR_MOTION_INDEX_NUMBER, index); 
}

bool MaxE1Motions::stop(const std::string option)
{
    uint16_t index = INDEX_STOP_WITH_EXIT_UNIT;

    if(option=="immediately"){
        index = INDEX_STOP_IMMEDIATELY;
    }else if(option=="keyframe"){
        index = INDEX_STOP_KEY_FRAME;
    }else if(option=="unit"){
        index = INDEX_STOP_UNIT;
    }

    return core_->write_2bytes(ADDR_MOTION_INDEX_NUMBER, index); 
}

bool MaxE1Motions::playing()
{
    uint8_t playing;
    bool result = core_->read_1byte(ADDR_MOTION_PLAY_STATUS, &playing); 

    return (bool)playing;
}
