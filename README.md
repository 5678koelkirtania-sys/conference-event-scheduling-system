# Conference Event Scheduling System

An automated event scheduling engine built in C++ designed to allocate conference sessions across multiple rooms while dynamically detecting conflicts and maximizing utilization.

## 🚀 Features
* **Greedy Interval Scheduling:** Implements interval management logic and sorting strategies based on finish times to optimize event placement.
* **Conflict Detection Engine:** Processes multiple overlapping booking requests, preventing double-booking and assigning room slots efficiently.
* **Room Utilization Optimization:** Dynamically tracks room availability schedules to maximize throughput.

## ⚙️ Compilation and Execution
```bash
g++ -std=c++17 main.cpp -o conference_scheduler
./conference_scheduler
