
#include <chrono>
#include <thread>
#include <iostream>

#include "max_e1.hpp"

int main() {
    MaxE1 max_e1("/dev/ttyACM0", 1000000);
    if(max_e1.connect()){
        int i = 0;
        while(i < 100){
            i++;

            max_e1.sensors->update();
            std::cout<<max_e1.sensors->get_temperature() << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        

    }
    max_e1.disconnect();
}
