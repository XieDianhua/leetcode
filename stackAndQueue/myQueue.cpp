#include <stack>
#include <iostream>

using namespace std;

class MyQueue {
public:
    MyQueue() {}

    // 将元素 x 推到队列的末尾
    void push(int x) { inStack.push(x); }

    //从队列的开头移除并返回元素
    int pop() {
        if (outStack.empty()) {
            if (!inStack.empty()) { //输入栈非空
                while (!inStack.empty()) {
                    int element = inStack.top();
                    inStack.pop();
                    outStack.push(element);
                }
            }
        }

        if (outStack.empty())
            return -1;
        else {
            int element = outStack.top();
            outStack.pop();
            return element;
        }
    }

    //返回队列开头元素
    int peek() {
        if (outStack.empty()) {
            if (!inStack.empty()) { //假设inStack中有元素
                while (!inStack.empty()) {
                    int element = inStack.top();
                    inStack.pop();
                    outStack.push(element);
                }

            }
        }

        if (outStack.empty())
            return -1;
        else
            return outStack.top();
    }

    // 如果队列为空，返回 true ；否则，返回 false
    bool empty() { return (inStack.empty() && outStack.empty()); }

    stack<int> inStack, outStack;
};

int main() {
    MyQueue myQueue;

    myQueue.push(1);
    myQueue.push(2);

    int peekResult = myQueue.peek();
    std::cout << "Peek Result: " << peekResult << std::endl; // 应输出1

    // 出队队首元素
    int popResult = myQueue.pop();
    std::cout << "Pop Result: " << popResult << std::endl; // 应输出1

    // 检查队列是否为空
    bool emptyResult = myQueue.empty();
    std::cout << "Empty Result: " << emptyResult << std::endl; // 应输出0（false）

    return 0;
}
