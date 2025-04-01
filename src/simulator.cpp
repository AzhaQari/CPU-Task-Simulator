#include "../include/simulator.hpp"
#include "../include/input.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

// loads tasks from tasks file and runs the scheduler
void Simulator::loadAndRun(const std::string& filename) {
    std::vector<Task> tasks = loadTasksFromFile(filename); // load the tasks

    if (tasks.empty()) {
        std::cerr << "No tasks to simulate.\n";
        return;
    }

    // loops thru tasks and adds them to scheduler 
    for (const Task& task : tasks) {
        scheduler.addTask(task);
    }

    scheduler.runPreemptive(); // runs the scheduler
    scheduler.printAndLogResults(); // this prints results to terminal and to the shecedule_log.txt file
}
