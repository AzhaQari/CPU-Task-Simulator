#include "../include/input.hpp"
#include <fstream>     
#include <sstream>     
#include <iostream>    

std::vector<Task> loadTasksFromFile(const std::string& filePath) {
    std::vector<Task> tasks;

    std::ifstream file(filePath); 
    if (!file.is_open()) {          // handle file opening errs
        std::cerr << "Error: Could not open file: " << filePath << "\n";
        return tasks; // return empty list bc of error
    }

    std::string line;
    int lineNumber = 0;

    // read thru the file, line by line
    while (std::getline(file, line)) {
        lineNumber++;

        if (line.empty()) continue; 

        std::istringstream iss(line);
        int id, arrival, burst, priority;
        std::string name;

        // obtains corresponding values from the line OR throws an error if the format is incorrect
        if (!(iss >> id >> name >> arrival >> burst >> priority)) {
            std::cerr << "Warning: Incorrect task format on line " << lineNumber << ": " << line << "\n";
            continue;
        }

        // constructs a task obj based on values taken from each line and adds tehm to the task vector
        Task task(id, name, arrival, burst, priority);
        tasks.push_back(task);
    }

    file.close();
    return tasks;
}
