
#include <chrono>
#include <thread>
#include <iostream>

#include "max_e1.hpp"

int main() {
    MaxE1 max_e1("/dev/ttyACM0", 1000000);
    if(max_e1.connect()){
        max_e1.init();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        std::cout<<"LED on: R"<<std::endl;
        max_e1.actuators->led(true, false, false);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        std::cout<<"LED on: G"<<std::endl;
        max_e1.actuators->led(false, true, false);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        std::cout<<"LED on: B"<<std::endl;
        max_e1.actuators->led(false, false, true);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        std::cout<<"LED on: RG"<<std::endl;
        max_e1.actuators->led(true, true, false);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        std::cout<<"LED on: GB"<<std::endl;
        max_e1.actuators->led(false, true, true);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        std::cout<<"LED on: RB"<<std::endl;
        max_e1.actuators->led(true, false, true);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        std::cout<<"LED on: RGB"<<std::endl;
        max_e1.actuators->led(true, true, true);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        std::cout<<"LED off"<<std::endl;
        max_e1.actuators->led(false, false, false);

        std::cout<<"Play scale 0, 3.0 seconds."<<std::endl;
        max_e1.actuators->buzzer_scale(0, 3.0);
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));

        std::cout<<"Play scale 1, 2.0 seconds."<<std::endl;
        max_e1.actuators->buzzer_scale(1, 2.0);
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));

        std::cout<<"Play scale 2, 1.0 seconds."<<std::endl;
        max_e1.actuators->buzzer_scale(2, 1.0);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        for(auto i=0; i <= 25; i++){
            std::cout<<"Play melody: "<<std::to_string(i)<<std::endl;
            max_e1.actuators->buzzer_melody(i);
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        }
    }
    max_e1.disconnect();
}
