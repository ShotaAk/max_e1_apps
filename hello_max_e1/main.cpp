
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

        while(i < 100){
            // i++;

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
        

    }
    max_e1.disconnect();
}
