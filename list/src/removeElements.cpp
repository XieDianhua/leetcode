#include<include/list.hpp>

ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummyHead = new ListNode(0, head);
    ListNode* current = dummyHead;

    while (current->next != nullptr) {  //下一节点非空（遍历所有节点，从虚拟节点->最后一个）
        if (current->next->val == val) {
            ListNode* toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
        }
        else {
            current = current->next;
        }
    }

    return dummyHead->next;
}
