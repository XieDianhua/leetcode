#include<unordered_set>

using namespace std;

int getNext(int n) {
    int totalSum = 0;
    while (n > 0) {
        int d = n % 10;
        n = n / 10;
        totalSum += d * d;
    }
    return totalSum;
}

bool isHappy(int n) {
    // 1. 初始化一个集合
    unordered_set<int> set;
    // 2. 一直循环下去直到n变为1或者遇到环
    while (n != 1 && set.find(n) == set.end()) { //find查找set中是否包含n
        set.insert(n);
        n = getNext(n); //计算下一个数
    }
    // 3. 返回结果
    return n == 1;
}