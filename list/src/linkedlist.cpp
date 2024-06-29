#include<iostream>

class MyLinkedList {
public:

    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    // MyLinkedList() :size(0), head(nullptr) {    //无头结点，head指向空指针
    // }

    MyLinkedList() {
        this->size = 0;
        this->head = new ListNode(0); //建立头结点（开辟一块内存空间，head将指向这块空间）
    }

    int get(int index) {
        // 1. 判断索引是否合法
        if (index < 0 || index >= size)
            return -1;

        // 2. 查找指定索引的结点
        ListNode* current = head;
        for (int i = 0; i <= index; i++) {
            current = current->next;
        }

        // 3. 返回结点值
        return current->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        //1. 判断索引是否合法
        if (index > size)
            return;
        if (index < 0)
            index = 0;

        size++;

        //2. 设置头结点为当前结点
        ListNode* current = head; //current指向了头结点
        int cnt = 0;

        /* index=2
        cnt   current     T/F
        0      头结点    0<2  T
        1        0       1<2  T
        2        1       2<2  F
        */

        //3. 遍历链表到索引为index的前一个结点
        while (current->next != nullptr && cnt < index) { //不用判断current != nullptr头结点内存空间肯定有
            cnt++;
            current = current->next;
        }

        //4. 插入结点
        ListNode* toAdd = new ListNode(val);
        toAdd->next = current->next;
        current->next = toAdd;
    }

    void deleteAtIndex(int index) {
        // 1. 判断索引是否合法
        if (index >= size || index < 0)
            return;

        size--;

        // 2. 设置头结点为当前结点
        ListNode* current = head;
        int cnt = 0;
        /*
        index = 2
        cnt     current     T/F
        0       头结点      0<2 T
        1       0           1<2 T
        2       1           2<2 F
         */

         // 3. 遍历范围为0~size-1，最后一个结点在1.已经排除了
        while (cnt < index) {
            cnt++;
            current = current->next;
        }

        // 4. 删除索引为index的结点
        ListNode* toDelete = current->next;
        current->next = current->next->next;
        delete toDelete;
    }
private:
    int size;
    ListNode* head;
};

int main() {

}