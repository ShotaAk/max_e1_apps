#ifndef MAX_E1_SENSORS_HPP_
#define MAX_E1_SENSORS_HPP_

#include "max_e1_core.hpp"

class MaxE1Sensors
{
public:
    MaxE1Sensors(const std::shared_ptr<MaxE1Core> & core);
    ~MaxE1Sensors();
    bool update();
    double voltage(){ return voltage_; }
    int temperature(){ return temperature_; };
    int sound_detecting_count(){
        // 拍手を続けるとカウントが増えていく
        // 1秒くらい音を検出しなかったらカウントが0にリセットされる
        // sound_detected_countの場合は、リセットされない（カウントが変わるたびに上書き）
        return sound_detecting_count_; };
    double acc_x(){ return acc_x_; };
    double acc_y(){ return acc_y_; };
    double acc_z(){ return acc_z_; };

private:
    double to_real_voltage(const uint8_t raw_voltage);
    double to_real_acc(const uint16_t raw_acc);

    std::shared_ptr<MaxE1Core> core_;
    int temperature_;
    double voltage_;
    int sound_detecting_count_;
    double acc_x_;
    double acc_y_;
    double acc_z_;
};

#endif