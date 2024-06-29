#include<list.hpp>


ListNode* removeElements(ListNode* head, int val) {
    //1. 创建头结点，并将头指针指向头结点，同时将头结点设置为当前结点
    ListNode* dummyHead = new ListNode(0, head);
    ListNode* current = dummyHead;

    //2. 遍历链表，直到最后一个结点（最后一个结点的标志为指针域为空）
    while (current->next != nullptr) {
        //3. 查找到特定值即删除该结点，否则将当前结点向后移动
        if (current->next->val == val) {   //删除的是当前结点的下一个结点
            ListNode* toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
        }
        else {
            current = current->next;
        }
    }

    //4. 返回头指针
    return dummyHead->next;
}

int main() {

}
