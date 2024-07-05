#include <iostream>
#include<string>
#include<vector>

using namespace std;

int strStr(string haystack, string needle) {
    if (needle == "")
        return 0;

    for (int i = 0;i < haystack.length() + 1 - needle.length();i++) {
        for (int j = 0;j < needle.length();j++) {
            if (haystack[i + j] != needle[j])
                break;
            if (j == needle.length() - 1)
                return i;
        }
    }

    return -1;
}
