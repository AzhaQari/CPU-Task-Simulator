#ifndef TASK_LOADER_HPP
#define TASK_LOADER_HPP

#include "task.hpp"
#include <vector>
#include <string>

std::vector<Task> loadTasksFromFile(const std::string& filename);

#endif 
