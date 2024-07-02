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

    // 2. 遍历数组中的每一个元素
    for (int i = 0; i < nums.size(); ++i) {
        // 3. 查找哈希表中是否存在满足条件的另一个数
        auto it = hashtable.find(target - nums[i]);

        // 4. 如果找到了，返回这两个数索引
        if (it != hashtable.end()) {
            return { it->second, i };
        }

        // 5. 如果没有找到，将当前数和它的索引存入哈希表
        hashtable[nums[i]] = i;
    }

    // 6. 如果没有找到任何两个数的和等于目标值，返回空的 vector
    return {};
}
