#ifndef INPUT_HPP
#define INPUT_HPP

#include "task.hpp"            
#include <vector>              
#include <string>              

// this method will read tasks from tasks.txt and then return a list of task objects
std::vector<Task> loadTasksFromFile(const std::string& filePath);

#endif 
