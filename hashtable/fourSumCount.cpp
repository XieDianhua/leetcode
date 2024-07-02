#include<vector>
#include<unordered_map>

using namespace std;

// 哈希表法
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    unordered_map<int, int> hashTableAB;

    // 1. 遍历num1和num2，把和存储到哈希表中，键是和，值是和出现次数
    for (int i : nums1) {
        for (int j : nums2) {
            hashTableAB[i + j]++;
        }
    }

    int count = 0;

    // 2. 遍历nums3和nums4，查找相反的和是否存在于哈希表中
    for (int k : nums3) {
        for (int l : nums4) {
            int sumCD = -(k + l);
            if (hashTableAB.find(sumCD) != hashTableAB.end())
                count += hashTableAB[sumCD];    //找到相反的和，叠加A+B和出现的次数
        }
    }

    // 3. 返回元组个数
    return count;
}

// // 暴力法
// int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
//     int size = nums1.size();
//     int cnt = 0;

//     // for (int i = 0;i < size;i++) {
//     //     for (int j = 0;j < size;j++) {
//     //         for (int k = 0;k < size;k++) {
//     //             for (int m = 0;m < size;m++) {
//     //                 if (nums1[i] + nums2[j] + nums3[k] + nums4[m] == 0)
//     //                     cnt++;
//     //             }
//     //         }
//     //     }
//     // }
//     for (auto a : nums1) {
//         for (auto b : nums2) {
//             for (auto c : nums3) {
//                 for (auto d : nums4) {
//                     if (a + b + c + d == 0)
//                         cnt++;
//                 }
//             }
//         }
//     }

//     return cnt;
// }