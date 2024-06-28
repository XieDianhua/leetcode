#include<iostream>

class MyLinkedList {
public:

    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    MyLinkedList() :size(0), head(nullptr) {
    }

    int get(int index) {
        ListNode* p;
        int cnt = 0;

        p = this->head;
        while (p && cnt < index) {
            p = p->next;
            cnt++;
        }

        if ((cnt == index) && p)
            return p->val;
        else
            return -1;
    }

    void addAtHead(int val) {
        ListNode* p = new ListNode(val);
        p->next = head;
        head = p;
        size++;
    }

    void addAtTail(int val) {
        ListNode* p = new ListNode(val);

        ListNode* current = head;
        while (current && current->next) {  /* 查找最后一个结点 */
            current = current->next;
        }
        current->next = p;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > this->size)
            return;

        if (index == this->size) {
            addAtTail(val);
            return;
        }

        ListNode* current, * p = new ListNode(val);
        int cnt = 0;

        current = this->head;
        while (current && current->next && cnt < index - 1) {
            current = current->next;
            cnt++;
        }
        if (current) {
            p->next = current->next;
            current->next = p;
            size++;
        }
    }

    void deleteAtIndex(int index) {
        if (index >= this->size || index < 0)
            return; //如果索引无效，不执行删除操作

        //如果删除的是头结点
        if (index == 0) {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
        }
        else {
            ListNode* current = head;
            int i = 0;
            while (i < index - 1) { //遍历到index-1的位置，需要知道前驱结点
                current = current->next;
                i++;
            }
            ListNode* toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
        }

        size--;
    }

private:
    int size;
    ListNode* head;
};
