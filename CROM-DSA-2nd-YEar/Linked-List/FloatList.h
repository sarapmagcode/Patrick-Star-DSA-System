#ifndef FLOATLIST_H
#define FLOATLIST_H

class FloatList {
    private:
        struct ListNode {
            float value;
            struct ListNode *next;
        };
        ListNode *head;
    public:
        FloatList();
        ~FloatList();
        void appendNode(float num);
        void insertNode(float num);
        void deleteNode(float num);
        void displayList();
};

#endif