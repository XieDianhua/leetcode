#include<queue>
#include<iostream>

using namespace std;

// class MyStack {
// public:
//     MyStack() {
//         inQueue = new queue<int>();
//         outQueue = new queue<int>();
//     }

//     void push(int x) {
//         inQueue->push(x);
//     }

//     int pop() {
//         // 如果两个队列都为空，返回-1
//         if (inQueue->empty() && outQueue->empty())
//             return -1;

//         // 如果输出队列为空
//         if (outQueue->empty()) {

//             // 把输入队列中除了最后一个的所有元素移动到输出队列中
//             while (inQueue->size() > 1) {
//                 int element = inQueue->front();
//                 inQueue->pop();
//                 outQueue->push(element);
//             }
//             // 交换输入输出队列内容
//             swap(inQueue, outQueue);
//         }

//         int result = outQueue->front();
//         outQueue->pop();
//         return result;
//     }

//     int top() {
//         if (outQueue->empty())
//             return inQueue->back();
//         else
//             return outQueue->front();
//     }

//     bool empty() {
//         return (inQueue->empty() && outQueue->empty());
//     }

//     queue<int>* inQueue, * outQueue;
// };

class MyStack {
public:
    MyStack() {
        storyQueue = new queue<int>();
        auxQueue = new queue<int>();
    }

    void push(int x) {
        // 将新元素存储在辅助队列中
        auxQueue->push(x);

        // 将栈队列中元素依次出队然后入队到辅助队列中
        while (!storyQueue->empty()) {
            auxQueue->push(storyQueue->front());
            storyQueue->pop();
        }


        // 交换两个队列内容
        swap(storyQueue, auxQueue);
    }

    // 移除并返回栈顶元素
    int pop() {
        if (storyQueue->empty())
            return -1;

        int topElement = storyQueue->front();
        storyQueue->pop();

        return topElement;
    }

    int top() {
        if (storyQueue->empty())
            return -1;

        return storyQueue->front();
    }

    bool empty() {
        return storyQueue->empty();
    }

    queue<int>* storyQueue, * auxQueue;
};

int main() {
    MyStack stack;  // 创建一个 MyStack 实例

    // 向栈中压入元素
    stack.push(1);
    stack.push(2);

    // 输出栈顶元素，但不移除它
    std::cout << "Top element is: " << stack.top() << std::endl;  // 应该输出2

    stack.push(3);

    // 输出栈顶元素，但不移除它
    std::cout << "Top element is: " << stack.top() << std::endl;  // 应该输出3

    return 0;
}