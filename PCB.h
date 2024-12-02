#ifndef PCB_H
#define PCB_H

#include<string>

struct PCB {
    int processID;
    std::string processName;
    std::string processStatus;
    int commandCounter;
    int cpuRegisters[8];

    // Конструктор
    PCB(int id, const std::string& name, const std::string& status, int counter)
        : processID(id), processName(name), processStatus(status), commandCounter(counter) {
        // Все элементы cpuRegisters делаем нули
        for (int& reg : cpuRegisters) {
            reg = 0;
        }
    }
};

#endif // PCB_H