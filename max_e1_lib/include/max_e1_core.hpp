#ifndef MAX_E1_CORE_HPP_
#define MAX_E1_CORE_HPP_

#include <memory>
#include "dynamixel_sdk/dynamixel_sdk.h"

class MaxE1Core
{
public:
    MaxE1Core(const std::string device_name, const int baudrate);
    ~MaxE1Core();
    bool open_port();
    void close_port();
    bool read_1byte(const uint16_t address, uint8_t *received_data);
    bool read_2bytes(const uint16_t address, uint16_t *received_data);
    bool write_1byte(const uint16_t address, const uint8_t write_data);
    bool write_2bytes(const uint16_t address, const uint16_t write_data);

private:
    bool parse_dxl_error(const std::string & func_name, const uint8_t id,
        const uint16_t address, const int dxl_comm_result, const uint8_t dxl_packet_error);

    std::shared_ptr<dynamixel::PortHandler> port_handler_;
    std::shared_ptr<dynamixel::PacketHandler> packet_handler_;
    int baudrate_;
};

#endif