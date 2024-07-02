#include <iostream>
#include <string>

using namespace std;

void reverseSegment(string& s, int start, int k) {
    int end = min(start + k - 1, (int)s.size() - 1);
    while (start < end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

string reverseStr(string s, int k) {
    int n = s.size();
    for (int i = 0; i < n; i += 2 * k)
        reverseSegment(s, i, k);

    return s;
}

int main() {
    string s = "abcdefg";
    int k = 2;

    cout << "Original string: " << s << endl;

    string reversed = reverseStr(s, k);

    cout << "After reverse with k=" << k << ": " << reversed << endl;

    return 0;
}
