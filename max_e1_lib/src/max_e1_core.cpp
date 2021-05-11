#include <iostream>
#include "max_e1_core.hpp"

constexpr double PROTOCOL_VERSION = 2.0;
constexpr uint8_t CM550_ID = 200;

MaxE1Core::MaxE1Core(const std::string device_name, const int baudrate)
    : baudrate_(baudrate)
{
    port_handler_ = std::shared_ptr<dynamixel::PortHandler>(
        dynamixel::PortHandler::getPortHandler(device_name.c_str()));
    packet_handler_ = std::shared_ptr<dynamixel::PacketHandler>(
        dynamixel::PacketHandler::getPacketHandler(PROTOCOL_VERSION));
}

MaxE1Core::~MaxE1Core()
{
    close_port();
}

bool MaxE1Core::open_port()
{
    if(!port_handler_->openPort()) {
        std::cerr << "Unable to open port: " << port_handler_->getPortName() << std::endl;
        return false;
    }

    return true;
}

void MaxE1Core::close_port()
{
    port_handler_->closePort();
}


bool MaxE1Core::read_1byte(const uint16_t address, uint8_t *received_data)
{
    uint8_t dxl_error = 0;
    int dxl_result = packet_handler_->read1ByteTxRx(port_handler_.get(), CM550_ID, address, received_data, &dxl_error);

    if(!parse_dxl_error(dxl_result, dxl_error)){
        return false;
    }
    return true;
}

bool MaxE1Core::read_2bytes(const uint16_t address, uint16_t *received_data)
{
    uint8_t dxl_error = 0;
    int dxl_result = packet_handler_->read2ByteTxRx(port_handler_.get(), CM550_ID, address, received_data, &dxl_error);

    if(!parse_dxl_error(dxl_result, dxl_error)){
        return false;
    }
    return true;
}

bool MaxE1Core::write_1byte(const uint16_t address, const uint8_t write_data)
{
    uint8_t dxl_error = 0;
    int dxl_result = packet_handler_->write1ByteTxRx(port_handler_.get(), CM550_ID, address, write_data, &dxl_error);

    if(!parse_dxl_error(dxl_result, dxl_error)){
        return false;
    }
    return true;
}

bool MaxE1Core::write_2bytes(const uint16_t address, const uint16_t write_data)
{
    uint8_t dxl_error = 0;
    int dxl_result = packet_handler_->write2ByteTxRx(port_handler_.get(), CM550_ID, address, write_data, &dxl_error);

    if(!parse_dxl_error(dxl_result, dxl_error)){
        return false;
    }
    return true;
}

bool MaxE1Core::parse_dxl_error(const int dxl_comm_result, const uint8_t dxl_packet_error)
{
    bool retval = true;

    if (dxl_comm_result != COMM_SUCCESS)
    {
        std::cerr << std::string(packet_handler_->getTxRxResult(dxl_comm_result)) << std::endl;
        retval = false;
    }

    if (dxl_packet_error != 0)
    {
        std::cerr << std::string(packet_handler_->getRxPacketError(dxl_packet_error)) << std::endl;
        retval = false;
    }

    return retval;
}
