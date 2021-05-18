#ifndef MAX_E1_MOTIONS_HPP_
#define MAX_E1_MOTIONS_HPP_

#include "max_e1_core.hpp"

class MaxE1Motions
{
public:
    MaxE1Motions(const std::shared_ptr<MaxE1Core> & core);
    ~MaxE1Motions();
    bool init();
    bool play(const int index=0, const bool wait=false, const int timeout_ms=3000);
    bool stop(const std::string option="");
    bool playing();

private:
    std::shared_ptr<MaxE1Core> core_;
};

#endif