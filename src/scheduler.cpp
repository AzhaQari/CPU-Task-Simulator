#include "../include/scheduler.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>

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

void Scheduler::runPreemptive() {
    if (readyQueue.empty()) {
        std::cout << "No tasks to schedule.\n";
        return;
    }

    int current_time = 0;
    Task* current_task = nullptr;

    while (std::any_of(readyQueue.begin(), readyQueue.end(), [](const Task& t) {
        return t.remaining_time > 0;
    })) {
        // firts we get all tasks that have arrived and still need CPU time
        std::vector<Task*> availableTasks;
        for (auto& task : readyQueue) {
            if (task.arrival_time <= current_time && task.remaining_time > 0) {
                availableTasks.push_back(&task);
            }
        }

        // then we pick tasks with the highest priorityu 
        if (!availableTasks.empty()) {
            auto next_task = *std::min_element(availableTasks.begin(), availableTasks.end(),
                [](const Task* a, const Task* b) {
                    return a->priority < b->priority;  
                });

            if (current_task != next_task) {
                current_task = next_task;  // switch to the new task
                std::cout << "Switching to task ID: " << current_task->id << " at time: " << current_time << '\n';
            }

            if (current_task->start_time == -1) {
                current_task->start_time = current_time; 
            }

            current_task->remaining_time--;
            current_time++;

            if (current_task->remaining_time == 0) {
                current_task->completion_time = current_time;
                current_task->turnaround_time = current_task->completion_time - current_task->arrival_time;
                current_task->waiting_time = current_task->turnaround_time - current_task->burst_time;
            }
        } else {
            // time++ if no tasks avaliable
            current_time++;
        }
    }

    // this will display the final results of all the tasks:
    std::cout << "\nAll tasks completed with preemptive priority scheduling.\n";
    std::cout << "-----------------------------------------------------------\n";
    std::cout << std::left << std::setw(5) << "ID"
              << std::setw(22) << "Name"
              << std::setw(20) << "Turnaround Time" // total time to complete task from arrival to completion
              << std::setw(18) << "Waiting Time" << '\n'; // total time the task spent waiting in the queue
    
    for (const auto& task : readyQueue) {
        std::cout << std::left << std::setw(5) << task.id
                  << std::setw(22) << task.name
                  << std::setw(20) << task.turnaround_time
                  << std::setw(18) << task.waiting_time << '\n';
    }
    std::cout << "-----------------------------------------------------------\n";
}
