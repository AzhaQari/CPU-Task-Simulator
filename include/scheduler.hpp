#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <vector>
#include "task.hpp"

class Scheduler {
    private:
        std::vector<Task> readyQueue; // holds tasks sorted by their priorities

    public:
        void addTask(const Task& task); // adds task to queue and sorts it
        void displayQueue() const; // displays tasks in the queue
};

#endif