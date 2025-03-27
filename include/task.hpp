#ifndef TASK_HPP
#define TASK_HPP

#include <string>

struct Task {
    int id;
    std::string name;
    int arrival_time; // time when the task is created
    int burst_time; // time required to complete task
    int priority; // lower number means higher priority
    int start_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;

    Task(int id, const std::string& name, int arrival, int burst, int priority)
    : id(id),
      name(name),
      arrival_time(arrival),
      burst_time(burst),
      priority(priority),
      start_time(-1),
      remaining_time(burst),
      completion_time(-1),
      turnaround_time(-1),
      waiting_time(-1) {}

};


#endif 