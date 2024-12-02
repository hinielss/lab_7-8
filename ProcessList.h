#ifndef PROCESSLIST_H
#define PROCESSLIST_H

#include "ListNode.h"

class ProcessList {
private:
    ListNode* head;
public:
    ProcessList();
    ~ProcessList();
    bool insert(const PCB& newPCB);
    bool remove(int pid);
    void printList();
};

#endif // PROCESSLIST_H