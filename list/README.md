## 链表

```C++
// 定义链表节点
struct ListNode {
    int val;           // 节点存储的数据
    ListNode *next;    // 指向下一个节点的指针

    // 构造函数
    ListNode(int x) : val(x), next(nullptr) {}
};

```

处理链表时一般选择创建一个虚拟头节点，来处理可能涉及头节点的问题

## 203 移除链表元素
法一：迭代法

终止条件：current->next==nullptr

