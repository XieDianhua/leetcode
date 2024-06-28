#include<iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr, * current = head, * temp = nullptr;

    while (current) {
        //保存当前结点的下一个结点
        temp = current->next;

        //反转操作：将当前结点的next指针指向前一个结点
        current->next = prev;

        //更新prev和current指针，进入下一次迭代
        prev = current;
        current = temp;
    }

    return prev;
}

void printList(ListNode* node) {
    while (node) {
        std::cout << node->val << " -> ";
        node = node->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    // 创建一个链表 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    std::cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    std::cout << "Reversed List: ";
    printList(head);

    ListNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
