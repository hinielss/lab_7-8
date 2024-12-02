#include "ProcessList.h"
#include <iostream>
using namespace std;

int main() {
    ProcessList processList;

    // Добавление элементов
    processList.insert(PCB(1, "Process1", "Running", 10));
    processList.insert(PCB(2, "Process2", "Waiting", 20));
    processList.insert(PCB(3, "Process3", "Stopped", 30));

    // Вывод списка
    std::cout << "Список после добавления:\n";
    processList.printList();

    // Удаление элемента
    processList.remove(2);
    std::cout << "\nСписок после удаления ID 2:\n";
    processList.printList();

    // Неуспешная вставка
    if (!processList.insert(PCB(1, "DuplicateProcess1", "Stopped", 40))) {
        std::cout << "\nОшибка: процесс с ID 1 уже существует.\n";
    }

    // Удаление несуществующего элемента
    if (!processList.remove(7)) {
        std::cout << "\nОшибка: процесс с ID 7 не найден.\n";
    }

    // Вывод списка
    std::cout << "\nСписок:\n";
    processList.printList();

    return 0;
}
