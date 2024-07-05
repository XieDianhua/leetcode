#include<vector>
#include<string>
#include<stack>
#include<iostream>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<string> stk;

    //1. 遍历输入字符串数组
    for (string& str : tokens) {    //???为什么范围for需要改变值时用引用
        // 2. 判断当前字符是否为运算符
        if (str == "+" || str == "-" || str == "*" || str == "/") {
            // 2.1 是则保存并弹出栈顶两个元素
            int num1, num2;
            num2 = stoi(stk.top());
            stk.pop();
            num1 = stoi(stk.top());
            stk.pop();

            char operators = str[0];
            int operateResult;

            switch (operators)
            {
            case '+':
                operateResult = num1 + num2;
                break;
            case '-':
                operateResult = num1 - num2;
                break;
            case '*':
                operateResult = num1 * num2;
                break;
            case '/':
                operateResult = num1 / num2;
                break;
            default:
                break;
            }

            stk.push(to_string(operateResult));
        }
        else {
            // 2.2 否则将元素压入栈中
            stk.push(str);
        }
    }
    // 3. 当栈中不再有运算符号时，栈顶的值就是表达式的值
    return stoi(stk.top());
}

int main() {
    vector<string> str = { "4", "13", "5", "/", "+" };
    int res = 0;

    res = evalRPN(str);

    return 0;
}