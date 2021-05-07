#include <iostream>
#include "max_e1_core.hpp"

constexpr double PROTOCOL_VERSION = 2.0;

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

    std::cout << "Port opened" << std::endl;

    return true;
}

void MaxE1Core::close_port()
{
    port_handler_->closePort();

    std::cout << "Port closed" << std::endl;
}
