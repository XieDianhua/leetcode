struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    //创建虚拟头结点
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* current = dummyHead;//当前到达的结点，开始时为虚拟头结点

    while (current->next && current->next->next) { //终止条件：current后面没有节点或者只有一个节点
        //定义当前节点的后两个节点
        ListNode* node1 = current->next;
        ListNode* node2 = current->next->next;

        current->next = node2;
        node1->next = node2->next;
        node2->next = node1;

        current = node1;
    }

    ListNode* res = dummyHead->next;
    delete dummyHead;

    return res;
}