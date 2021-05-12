
#include <iostream>
#include "max_e1_sensors.hpp"

// CM-550 e-manual:https://emanual.robotis.com/docs/en/parts/controller/cm-550/
constexpr uint16_t ADDR_SOUND_DETECTING_COUNT = 87;
constexpr uint16_t ADDR_VOLTAGE = 89;
constexpr uint16_t ADDR_TEMPERATURE = 90;
constexpr uint16_t ADDR_ROLL = 102;
constexpr uint16_t ADDR_PITCH = 104;
constexpr uint16_t ADDR_YAW = 106;
constexpr uint16_t ADDR_GYRO_X = 108;
constexpr uint16_t ADDR_GYRO_Y = 110;
constexpr uint16_t ADDR_GYRO_Z = 112;
constexpr uint16_t ADDR_ACC_X = 114;
constexpr uint16_t ADDR_ACC_Y = 116;
constexpr uint16_t ADDR_ACC_Z = 118;

MaxE1Sensors::MaxE1Sensors(const std::shared_ptr<MaxE1Core> & core)
    : core_(core), temperature_(0), voltage_(0), sound_detecting_count_(0),
      acc_x_(0), acc_y_(0), acc_z_(0)
{
}

MaxE1Sensors::~MaxE1Sensors()
{
}

bool MaxE1Sensors::init()
{
    std::cout<<"Sensors init() is called."<<std::endl;
    return true;
}

bool MaxE1Sensors::update()
{
    uint8_t data8;
    uint16_t data16;

    if(core_->read_1byte(ADDR_SOUND_DETECTING_COUNT, &data8))
        sound_detecting_count_ = data8;
    if(core_->read_1byte(ADDR_VOLTAGE, &data8))
        voltage_ = to_real_voltage(data8);
    if(core_->read_1byte(ADDR_TEMPERATURE, &data8))
        temperature_ = data8;

    // TODO:Use sync read
    if(core_->read_2bytes(ADDR_ROLL, &data16))
        orientation_r_ = to_real_orientation(data16);
    if(core_->read_2bytes(ADDR_PITCH, &data16))
        orientation_p_ = to_real_orientation(data16);
    if(core_->read_2bytes(ADDR_YAW, &data16))
        orientation_y_ = to_real_orientation(data16);

    if(core_->read_2bytes(ADDR_GYRO_X, &data16))
        gyro_x_ = to_real_gyro(data16);
    if(core_->read_2bytes(ADDR_GYRO_Y, &data16))
        gyro_y_ = to_real_gyro(data16);
    if(core_->read_2bytes(ADDR_GYRO_Z, &data16))
        gyro_z_ = to_real_gyro(data16);

    if(core_->read_2bytes(ADDR_ACC_X, &data16))
        acc_x_ = to_real_acc(data16);
    if(core_->read_2bytes(ADDR_ACC_Y, &data16))
        acc_y_ = to_real_acc(data16);
    if(core_->read_2bytes(ADDR_ACC_Z, &data16))
        acc_z_ = to_real_acc(data16);

    return true;
}

double MaxE1Sensors::to_real_voltage(const uint8_t raw_voltage)
{
    const double UNIT = 0.1;  // Volts
    return raw_voltage * UNIT;
}

double MaxE1Sensors::to_real_orientation(const uint16_t raw_orientation)
{
    const double UNIT = 0.01;  // deg
    return int16_t(raw_orientation) * UNIT;  // 符号付きに変換
}

double MaxE1Sensors::to_real_gyro(const uint16_t raw_gyro)
{
    const double UNIT = 0.01;  // deg/sec
    return int16_t(raw_gyro) * UNIT;  // 符号付きに変換
}

double MaxE1Sensors::to_real_acc(const uint16_t raw_acc)
{
    const double UNIT = 0.001;  // G (e-manualだと0.01Gとなってて、よくわからん)
    return int16_t(raw_acc) * UNIT;  // 符号付きに変換
}