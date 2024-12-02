#ifndef LISTNODE_H
#define LISTNODE_H

#include "PCB.h"

class ListNode {
public:
    PCB data;
    ListNode* next;
    ListNode(const PCB& pcb);
    ~ListNode();
};

#endif // LISTNODE_H