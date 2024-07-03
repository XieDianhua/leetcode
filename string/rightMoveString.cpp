#include <iostream>
#include<string>
#include<vector>

using namespace std;

void reverseSegment(string& s, int start, int k) {
    int end = min(start + k - 1, (int)s.size() - 1);
    while (start < end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

void rightMoveString(string& s, int k) {
    int size = s.length();

    //1. 翻转整个字符串
    reverseSegment(s, 0, size);
    //2. 翻转前k个字符串
    reverseSegment(s, 0, k);
    //3. 翻转后size-k个字符串
    reverseSegment(s, k, size - k);
}

int main() {
    string s = "abcdefg";
    int k = 2;

    rightMoveString(s, k);

    cout << s << endl; // 输出: "fgabcde"

    return 0;
}