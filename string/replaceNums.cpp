#include <iostream>
#include<string>
#include<vector>

using namespace std;

string replaceNums(const string& s) {
    string res;

    for (char c : s) {
        if ('0' <= c && c <= '9') {
            res += "number";
        }
        else {
            res += c;
        }
    }

    return res;
}

int main() {
    string str1{ "a1b2c3" }, str2;

    str2 = replaceNums(str1);

    cout << "替换后的字符串为" << str2 << endl;

    return 0;
}