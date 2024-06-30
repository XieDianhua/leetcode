#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* detectCycle(ListNode* head) {
    //定义快、慢指针
    ListNode* slow = head, * fast = head;
    while (fast != nullptr) {
        slow = slow->next;//慢指针每次向后移动一个位置
        if (fast->next == nullptr) {    //判断链表是否有环
            return nullptr;
        }
        fast = fast->next->next;//快指针每次向后移动两个位置
        if (fast == slow) {
            //快慢指针相遇
            ListNode* ptr = head;
            while (ptr != slow) {   //慢指针（从相遇位置开始）和遍历指针ptr（开始位置head）同时出发
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
    }
    return nullptr;
}
