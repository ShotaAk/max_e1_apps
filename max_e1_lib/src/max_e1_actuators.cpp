
#include <iostream>
#include "max_e1_actuators.hpp"

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
