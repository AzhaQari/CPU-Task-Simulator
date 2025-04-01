# Preemptive Task Scheduler Simulator (PTSS)

## TL;DR
- 🛠 **Language**: C++
- 🧪 **Purpose**: Simulates a preemptive priority-based task scheduler
- 📁 **Input**: `tasks.txt` containing task info (ID, Name, Arrival, Burst, Priority)
- 🖥 **Output**: Schedules tasks with context switching and logs results to terminal and `schedule_log.txt`
- 🧮 **Key Metrics**: Turnaround Time, Waiting Time, Burst Time
- 💻 **How to Run (MSYS2)**:
  ```bash
  g++ -Iinclude src/*.cpp -o bin/PTSS
  ./bin/PTSS
  ```

---

## Project Description
This project simulates a CPU scheduling environment using **preemptive priority-based scheduling**. Tasks are loaded from a file and executed one unit of time at a time, allowing higher-priority tasks to preempt others.

## Task Input File Format
Each line in `tasks.txt` should follow this format (space-separated):
```
<ID> <Name> <ArrivalTime> <BurstTime> <Priority>
```
Example:
```
0 ShowOffCoolProject 0 10 1
1 InitializeHardware 10 4 2
2 LoadBootConfig 3 3 5
3 StartNetworkService 10 6 3
```
> ⚠️ Make sure there are no commas or extra spaces. This is a space-delimited format.

## Metrics Definitions
- **Burst Time**: Time required by a task to complete execution (aka total processing time).
- **Turnaround Time**: `Completion Time - Arrival Time`
- **Waiting Time**: `Turnaround Time - Burst Time`

## Output
You’ll see a sequence of task switches (by task ID) in the terminal, followed by a summary table of all tasks.

Additionally, a `schedule_log.txt` file is created with the same output and explanations.

## How to Compile & Run (MSYS2)
Make sure you're inside the project root directory, then run:
```bash
g++ -Iinclude src/*.cpp -o bin/PTSS
./bin/PTSS
```

Ensure you have a `bin/` directory or create one if it doesn't exist:
```bash
mkdir -p bin
```

## Folder Structure
```
Green-Hills-Project/
├── include/
│   ├── task.hpp
│   ├── scheduler.hpp
│   ├── input.hpp
│   └── simulator.hpp
├── src/
│   ├── scheduler.cpp
│   ├── input.cpp
│   └── simulator.cpp
├── tasks.txt
├── bin/
│   └── PTSS.exe (after build)
├── schedule_log.txt (created at runtime)
└── README.md
```

---

## Potential Future Enhancements
- Visualize task execution with a Gantt chart
- Add support for round-robin or FCFS scheduling
- Export results as CSV or JSON

---

## Author
Azha Qari  
Computer Science Graduate from The Georgia Institute of Technology (Georgia Tech) 

