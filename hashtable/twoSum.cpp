#include<vector>
#include<unordered_map>

using namespace std;

//暴力法
// vector<int> twoSum(vector<int>& nums, int target) {
//     int sum = 0;
//     vector<int> res;

//     for (int i = 0;i < nums.size();i++) {
//         for (int j = i + 1;j < nums.size();j++) {
//             sum = nums[i] + nums[j];
//             if (sum == target) {
//                 return { i,j };
//             }
//         }
//     }
//     return {};
// }

// 哈希表法
vector<int> twoSum(vector<int>& nums, int target) {
    // 1. 创建哈希表
    unordered_map<int, int> hashtable;
    for (int i = 0; i < nums.size(); ++i) {
        auto it = hashtable.find(target - nums[i]); //找到target-x则返回地址，未找到返回尾迭代器
        if (it != hashtable.end()) {
            return { it->second, i }; //返回map中的value，即索引
        }
        hashtable[nums[i]] = i;
    }
    return {};
}
