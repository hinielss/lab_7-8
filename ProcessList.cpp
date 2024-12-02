#include "ProcessList.h"
#include <iostream>

ProcessList::ProcessList() : head(nullptr) {}

ProcessList::~ProcessList() {
    // Удяляем все указатели
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

bool ProcessList::insert(const PCB& newPCB) {

    // Ставим элемент в начало, если список пустой или ID головного > ID нового
    if (head == nullptr || head->data.processID > newPCB.processID) {
        ListNode* node = new ListNode(newPCB);
        node->next = head;
        head = node;
        return true;
    }

    ListNode* current = head;
    // Ищем элемент, после которого надо вставить ноду
    while (current->next && current->next->data.processID < newPCB.processID) {
        current = current->next;
    }

    // Нода с таким ID уже существует
    if (current->data.processID == newPCB.processID) {
        return false;
    }

    // Вставляем ноду на своё место
    ListNode* node = new ListNode(newPCB);
    node->next = current->next;
    current->next = node;
    return true;
}

bool ProcessList::remove(int pid) {

    // Если списко пустой - удалять нечего, return
    if (head == nullptr) {
        return false;
    }

    // Головной элемент подошёл для удаления
    if (head->data.processID == pid) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    // Ищем ноду, которую надо удалить
    ListNode* current = head;
    while (current->next && current->next->data.processID != pid) {
        current = current->next;
    }

    // Ноды, которую нужно удалить, не существует
    if (current->next == nullptr) {
        return false;
    }

    // Удаляем ноду и обновляем указатели
    ListNode* temp = current->next;
    current->next = current->next->next;
    delete temp;
    return true;
}

void ProcessList::printList() {
    ListNode* current = head;
    while (current) {
        std::cout << "processID: " << current->data.processID
                    << ", processStatus: " << current->data.processStatus
                    << ", commandCounter: " << current->data.commandCounter << "\n";
        current = current->next;
    }
}