#ifndef MAX_E1_ACTUATORS_HPP_
#define MAX_E1_ACTUATORS_HPP_

#include "max_e1_core.hpp"

class MaxE1Actuators
{
public:
    MaxE1Actuators(const std::shared_ptr<MaxE1Core> & core);
    ~MaxE1Actuators();
    bool init();

private:
    std::shared_ptr<MaxE1Core> core_;
};

#endif