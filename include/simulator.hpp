#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include "scheduler.hpp"

class Simulator {
private:
    Scheduler scheduler;

public:
    void loadAndRun(const std::string& filename);
};

#endif 
