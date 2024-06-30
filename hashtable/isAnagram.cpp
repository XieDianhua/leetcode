#include<vector>
#include<string>

using namespace std;

bool isAnagram(string s, string t) {
    // 1. 确保两个字符串长度相同
    if (s.length() != t.length())
        return false;

    // 2. 初始化长度为26的哈希表
    /* table = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
                a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
    */
    vector<int> table(26, 0);

    // 3. 遍历字符串s，遍历字符时，对应的'table'元素加1
    // table = [3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0]
    for (auto& ch : s) {
        table[ch - 'a']++;  //哈希函数是h(ch)=ch-'a'，将字符映射到哈希表的索引上
    }

    // 3. 遍历字符串t，遍历字符时，对应的'table'元素减
    for (auto& ch : t) {
        table[ch - 'a']--;
        if (table[ch - 'a'] < 0) {  //如果不是在s加完的基础上减的自然会有小于0的情况
            return false;
        }
    }

    // 4. 返回结果
    return true;
}
