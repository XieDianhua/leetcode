#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    int size = nums.size();
    int fourSum = 0;

    // 1. 对数组进行排序,方便处理重复数字
    sort(nums.begin(), nums.end());

    for (int i = 0;i < size;i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1;j < size;j++) {

            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1, right = size - 1;

            while (left < right) {
                fourSum = nums[i] + nums[j] + nums[left] + nums[right];
                if (fourSum < target)
                    left++;
                else if (fourSum > target)
                    right--;
                else {
                    res.push_back({ nums[i],nums[j],nums[left],nums[right] });
                    left++;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                }
            }
        }
    }

    return res;
}