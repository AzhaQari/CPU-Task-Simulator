#include "../include/task_loader.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

// loads tasks adn returns tasks in a vector
std::vector<Task> loadTasksFromFile(const std::string& filename) {
    std::vector<Task> tasks;
    std::ifstream file(filename);
    std::string line;

    // handles errors in file opening
    if (!file) {
        std::cerr << "Error opening file: " << filename << '\n';
        return tasks;
    }

    // parses file line by line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;

        int id, arrival, burst, priority;
        std::string name;

        // parse each value, delimeter = , 
        std::getline(ss, token, ',');
        id = std::stoi(token);

        std::getline(ss, name, ',');
        name = std::string(name.begin() + (name[0] == ' ' ? 1 : 0), name.end()); 

        std::getline(ss, token, ',');
        arrival = std::stoi(token);

        std::getline(ss, token, ',');
        burst = std::stoi(token);

        std::getline(ss, token, ',');
        priority = std::stoi(token);

        // Create the task and add it to the vector
        tasks.emplace_back(id, name, arrival, burst, priority);
    }

    return tasks;
}
