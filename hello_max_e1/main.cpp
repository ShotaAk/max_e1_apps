
#include <chrono>
#include <thread>
#include <iostream>

#include "max_e1.hpp"

int main() {
    MaxE1 max_e1("/dev/ttyACM0", 1000000);
    if(max_e1.connect()){
        int i = 0;
        while(i < 100){
            // i++;

            max_e1.sensors->update();
            std::cout<<"sound_detecting_count:"<<max_e1.sensors->sound_detecting_count()<<std::endl;
            std::cout<<"voltage:"<<max_e1.sensors->voltage()<< std::endl;
            std::cout<<"temperature:"<<max_e1.sensors->temperature() << std::endl;
            std::cout<<"acc_x:"<<max_e1.sensors->acc_x() << std::endl;
            std::cout<<"acc_y:"<<max_e1.sensors->acc_y() << std::endl;
            std::cout<<"acc_z:"<<max_e1.sensors->acc_z() << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        

    }
    max_e1.disconnect();
}
