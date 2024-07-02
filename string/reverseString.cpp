#include<string>
#include<vector>

using namespace std;

void reverseString(vector<char>& s) {
    int size = s.size();

    int left = 0, right = size - 2;
    while (left < right) {
        char tmp = '0';

        tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;

        left++;
        right--;
    }
}