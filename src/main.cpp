#include "../include/scheduler.hpp"
#include "../include/input.hpp"  
#include <iostream>
#include "../include/simulator.hpp"  

int main() {
    // loads tasks.txt and runs the scheduler
    std::string filePath = "tasks.txt";

    Simulator simulator;
    simulator.loadAndRun(filePath);

    return 0;
}
