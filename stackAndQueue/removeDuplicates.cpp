#include<string>
#include<stack>
#include<iostream>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> resStr;

        // 遍历字符串
        for (int i = 0;i < s.length();i++) {
            if (!resStr.empty() && resStr.top() == s[i]) {
                resStr.pop();
            }
            else {
                resStr.push(s[i]);
            }
        }

        std::string result;
        while (!resStr.empty()) {
            result = resStr.top() + result; // 将字符添加到结果字符串的前面
            resStr.pop();
        }

        return result;
    }
};
int main() {
    Solution s;
    // 测试数据
    std::string testData = "abbaca";

    std::cout << "Original: " << testData << std::endl;
    std::string result = s.removeDuplicates(testData);
    std::cout << "Processed: " << result << std::endl;
    std::cout << std::endl;

    return 0;
}