#include <bits/stdc++.h>
#include "FloatList.h"

using namespace std;

FloatList::FloatList() {
    // constructor
    head = NULL;
}

FloatList::~FloatList() {
    // destructor
    ListNode *nodePtr, *nextNode;
    nodePtr = head;
    while (nodePtr != NULL) {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
    cout << "Linked List has been destroyed!" << endl;
}

void FloatList::appendNode(float num) {
    ListNode *newNode, *nodePtr;
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = NULL;
    if (!head) {
        head = newNode;
    } else {
        nodePtr = head;
        while (nodePtr->next) {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
    cout << "Input has been APPENDED!" << endl;
}

void FloatList::displayList() {
    ListNode *nodePtr;
    if (head == NULL) {
        cout << "The list is empty!" << endl;
    } else {
        nodePtr = head;
        while (nodePtr) {
            cout << nodePtr->value << endl;
            nodePtr=nodePtr->next;
        }
    }
}

void FloatList::insertNode(float num) {
    ListNode *newNode, *nodePtr, *previousNode;
    newNode = new ListNode;
    newNode->value = num;
    if (!head) {
        head = newNode;
        newNode->next = NULL;
    } else {
        nodePtr = head;
        previousNode = NULL;
        while (nodePtr != NULL && nodePtr->value < num) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (previousNode == NULL) {
            head = newNode;
            newNode->next = nodePtr;
        } else {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
    cout << "Input has been INSERTED!" << endl;
}

void FloatList::deleteNode(float num) {
    ListNode *nodePtr, *previousNode;
    int found = 0;
    if (!head) {
        cout << "The list is empty!" << endl;
        return;
    }
    if (head->value == num) {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
        found = 1;
    } else {
        nodePtr = head;
        previousNode = NULL;
        while (nodePtr != NULL && nodePtr->value != num) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (nodePtr != NULL) {
            previousNode->next = nodePtr->next;
            delete nodePtr;
            cout << "Input has been DELETED!" << endl;
            found = 1;
        }
    }
    if (found == 0) {
        cout << "Input not in the list!" << endl;
    }
}
