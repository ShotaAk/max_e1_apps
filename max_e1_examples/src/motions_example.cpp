
#include <chrono>
#include <thread>
#include <iostream>

#include "max_e1.hpp"

int main() {
    MaxE1 max_e1("/dev/ttyACM0", 1000000);
    if(max_e1.connect()){
        max_e1.init();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        std::cout<<"Move forward"<<std::endl;
        max_e1.motions->play(18);
        max_e1.motions->play(20);
        max_e1.motions->play(22);

        std::cout<<"Move backward"<<std::endl;
        max_e1.motions->play(23);
        max_e1.motions->play(25);
        max_e1.motions->play(27);

        std::cout<<"Stop a play immediately"<<std::endl;
        max_e1.motions->play(4);
        max_e1.motions->stop("immediately");

        std::cout<<"Stop a play at keyframe"<<std::endl;
        max_e1.motions->play(4);
        max_e1.motions->stop("keyframe");

        std::cout<<"Stop a play at unit"<<std::endl;
        max_e1.motions->play(4);
        max_e1.motions->stop("unit");
    }
    max_e1.disconnect();
}
