#include"list.hpp"

ListNode* swapPairs(ListNode* head) {
    // 1. 创建头结点，并将头指针指向头结点，同时将头结点设置为当前结点
    ListNode* dummyHead = new ListNode(0, head);
    ListNode* current = dummyHead;

    // 2. 遍历链表，直到当前结点后面没有或者只有一个结点
    while ((current->next != nullptr) && (current->next->next != nullptr)) {
        ListNode* node1 = current->next;
        ListNode* node2 = current->next->next;

        // 3. 交换结点
        current->next = node2;
        node1->next = node2->next;
        node2->next = node1;

        // 4. 把交换后的第二个结点设为当前结点
        current = node1;
    }

    // 5. 返回交换后链表头指针
    ListNode* res = dummyHead->next;
    delete dummyHead;
    return res;
}