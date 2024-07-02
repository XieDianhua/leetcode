#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    int size = nums.size();
    int threeSum = 0;

    // 1. 对数组进行排序,方便处理重复数字
    sort(nums.begin(), nums.end());

    // 2. 遍历数组
    for (int i = 0;i < size;i++) {
        //2.1 如果当前数字和前一个数字相同，跳过以避免重复的三元组
        if (i > 0 && (nums[i] == nums[i - 1]))
            continue;

        int left = i + 1, right = size - 1;
        // 2.2 当左右指针相遇时结束循环
        while (left < right) {
            threeSum = nums[i] + nums[left] + nums[right];
            if (threeSum > 0)
                right--;    //如果三数之和大于0，说明右边数字太大，右指针左移
            else if (threeSum < 0)
                left++;
            else {
                res.push_back({ nums[i],nums[left],nums[right] });
                left++; //左指针右移，寻找下一个可能的三元组
                while (left < right && nums[left] == nums[left + 1])    //跳过重复的数字，避免结果集中出现重复的三元组
                    left++;
            }
        }
    }

    // 3. 返回结果集
    return res;
}