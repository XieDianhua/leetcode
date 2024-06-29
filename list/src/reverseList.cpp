#include"list.hpp"

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr, * current = head, * temp = nullptr;

    while (current) {
        //1. 保存当前结点的下一个结点
        temp = current->next;

        //2. 反转操作：将当前结点的next指针指向前一个结点
        current->next = prev;

        //3. 更新prev和current指针，进入下一次迭代
        prev = current;
        current = temp;
    }

    return prev;
}

