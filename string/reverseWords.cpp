#include <iostream>
#include<string>
#include<vector>

using namespace std;

string reverseWords(string s) {
    int size = s.length();
    int i = 0;
    string res;

    while (i < size) {
        while (i < size && s[i] == ' ') i++;//排除前导空格
        if (i >= size) break;
        int j = i + 1; //这里是j=i+1还是j=i

        while (j < size && s[j] != ' ') j++;    //j会加到下一个空格字符所在位置

        string subStr = s.substr(i, j - i);
        if (res.length() == 0) res = subStr;
        else res = subStr + " " + res;
        i = j + 1;
    }

    return res;
}

int main() {
    string s = "  hello world!  ";
    cout << reverseWords(s) << endl; // 应输出: "world! hello"

    s = "a good   example";
    cout << reverseWords(s) << endl; // 应输出: "example good a"

    s = "  Bob    Loves  Alice   ";
    cout << reverseWords(s) << endl; // 应输出: "Alice Loves Bob"

    return 0;
}