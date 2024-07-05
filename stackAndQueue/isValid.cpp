#include<string>
#include<stack>
#include<unordered_map>
#include<iostream>

using namespace std;

// 闭合条件判断
class Solution {
public:
    bool isValid(string s) {
        // 判断字符串的有效性
        if (s.length() % 2 != 0)
            return false;

        unordered_map<char, char> hashTable = {
                                    {')','('},
                                    {'}','{'},
                                    {']','['}
        };

        stack<char> leftChar;
        for (char ch : s) {
            if (hashTable.count(ch)) {
                if (leftChar.empty() || leftChar.top() != hashTable[ch])
                    return false;
                leftChar.pop();
            }
            else
                leftChar.push(ch);
        }

        return leftChar.empty();
    }
};

int main() {
    Solution solution;

    // 测试数据点
    string testCases[] = { "()", "()[]{}", "(]", "([)]", "{[]}" };
    int numTests = sizeof(testCases) / sizeof(testCases[0]);

    // 遍历测试数据点
    for (int i = 0; i < numTests; i++) {
        cout << "Testing: \"" << testCases[i] << "\" -> ";
        if (solution.isValid(testCases[i])) {
            cout << "Valid" << endl;
        }
        else {
            cout << "Invalid" << endl;
        }
    }

    return 0;
}