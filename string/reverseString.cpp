#include<string>
#include<vector>
#include<iostream>

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

int main() {
    vector<char> str{ 'h', 'e', 'l', 'l', 'o' };

    cout << "Before reverse: ";
    for (char ch : str) {
        cout << ch << " ";
    }
    cout << endl;

    reverseString(str);

    cout << "After reverse: ";
    for (char ch : str) {
        cout << ch << " ";
    }
    cout << endl;

    return 0;
}