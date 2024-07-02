#include<string>
#include<unordered_map>

using namespace std;

/* 思路：这道题和isAnagram很相似
1. 把magazine的字符存储在哈希表中，键为字符，值为同一字符出现个数
2. 遍历ransomNote，查看每个字符能否在哈希表中找到，找到一次删除一个*/
// bool canConstruct(string ransomNote, string magazine) {
//     unordered_map<char, int> hashTable;

//     for (char s : magazine)
//         hashTable[s]++;

//     for (char c : ransomNote) {
//         hashTable[c]--;
//         if (hashTable[c] < 0) {
//             return false;
//         }
//     }

//     return true;
// }
