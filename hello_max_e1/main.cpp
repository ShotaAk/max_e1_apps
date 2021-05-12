
#include <chrono>
#include <thread>
#include <iostream>

#include "max_e1.hpp"

int main() {
    MaxE1 max_e1("/dev/ttyACM0", 1000000);
    if(max_e1.connect()){
        int i = 0;
        max_e1.init();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        while(i < 10){
            i++;

            auto begin = std::chrono::high_resolution_clock::now();
            max_e1.sensors->update();
            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
            std::cout << elapsed_time.count() << "マイクロ秒" << std::endl;

            std::cout<<"sound_detecting_count:"<<max_e1.sensors->sound_detecting_count()<<std::endl;
            std::cout<<"voltage:"<<max_e1.sensors->voltage()<< std::endl;
            std::cout<<"temperature:"<<max_e1.sensors->temperature() << std::endl;
            std::cout<<"orientation_r:"<<max_e1.sensors->orientation_r() << std::endl;
            std::cout<<"orientation_p:"<<max_e1.sensors->orientation_p() << std::endl;
            std::cout<<"orientation_y:"<<max_e1.sensors->orientation_y() << std::endl;
            std::cout<<"gyro_x:"<<max_e1.sensors->gyro_x() << std::endl;
            std::cout<<"gyro_y:"<<max_e1.sensors->gyro_y() << std::endl;
            std::cout<<"gyro_z:"<<max_e1.sensors->gyro_z() << std::endl;
            std::cout<<"acc_x:"<<max_e1.sensors->acc_x() << std::endl;
            std::cout<<"acc_y:"<<max_e1.sensors->acc_y() << std::endl;
            std::cout<<"acc_z:"<<max_e1.sensors->acc_z() << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }

        // for(auto i=0; i <= 30; i++){
        //     max_e1.actuators->buzzer_melody(i);
        //     std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        // }

        // max_e1.actuators->buzzer_scale(0, 3.0);
        // max_e1.actuators->buzzer_scale(1, 2.0);
        // max_e1.actuators->buzzer_scale(2, 1.0);

        max_e1.actuators->led(true, false, false);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        max_e1.actuators->led(false, true, false);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        max_e1.actuators->led(false, false, true);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        max_e1.actuators->led(true, true, false);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        max_e1.actuators->led(false, true, true);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        max_e1.actuators->led(true, false, true);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        max_e1.actuators->led(true, true, true);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        max_e1.actuators->led(false, false, false);
    }
    max_e1.disconnect();
}
