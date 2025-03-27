#include "../include/scheduler.hpp"
#include <iostream>
#include <algorithm>

// adds tasks to the queue and sorts them by priority
void Scheduler::addTask(const Task& task) {
    readyQueue.push_back(task);
    std::sort(readyQueue.begin(), readyQueue.end(), [](const Task& a, const Task& b) {
        return a.priority < b.priority;
    });
}

// displays tasks in the queue
void Scheduler::displayQueue() const {
    std::cout << "Ready Queue:\n";
    for (const auto& task : readyQueue) {
        std::cout << "Task ID: " << task.id
                  << ", Name: "  << task.name
                  << ", Priority: " << task.priority
                  << ", Arrival Time: " << task.arrival_time
                  << ", Burst Time: " << task.burst_time << '\n';
    }
}