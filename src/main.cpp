#include "../include/scheduler.hpp"
#include <iostream>

int main() {
    Scheduler scheduler;

    Task task1(1, "Task 1", 0, 5, 3);
    Task task2(2, "Task 2", 2, 3, 1);
    Task task3(3, "Task 3", 1, 4, 2);

    // adds some sample tasks^^^
    scheduler.addTask(task1);
    scheduler.addTask(task2);
    scheduler.addTask(task3);

    scheduler.displayQueue();
    scheduler.runPreemptive();
    
    return 0;
}