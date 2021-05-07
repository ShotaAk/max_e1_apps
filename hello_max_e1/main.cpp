#include "max_e1_core.hpp"

int main() {
    MaxE1Core max_e1("/dev/ttyACM0", 1000000);
    max_e1.open_port();
}
