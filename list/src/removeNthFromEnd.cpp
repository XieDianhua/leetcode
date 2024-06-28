struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
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