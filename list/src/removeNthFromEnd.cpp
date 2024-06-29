#include"list.hpp"


ListNode* removeNthFromEnd(ListNode* head, int n) {
    // 1. 创建头结点，并将头指针指向头结点，同时将头结点设置为当前结点
    ListNode* dummyHead = new ListNode(0, head);
    ListNode* current = dummyHead;

    //遍历一遍链表，获取链表节点个数size
    int size = 0;
    while (head) {
        size++;
        head = head->next;
    }

    for (int i = 1;i < size - n + 1;i++) {//查找第size-n+1个节点，即倒数第n+1节点
        current = current->next;
    }
    current->next = current->next->next;

    ListNode* res = dummyHead->next;
    delete dummyHead;

    return res;
}