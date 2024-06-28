#include<vector>
#include<algorithm>

using namespace std;

/* 暴力法 */
//vector<int> sortedSquares(vector<int>& nums) {
//    for (int i = 0; i < nums.size(); i++) {
//        nums[i] *= nums[i];
//    }
//    sort(nums.begin(), nums.end()); // 快速排序
//    return nums;
//}

/* 双指针法 */
vector<int> sortedSquares(vector<int>& nums) {
    vector<int> resultNums(nums.size(), 0);
    int k = 0;

    for (int left = 0, right = nums.size() - 1;left <= right;)  /* left<=right是终止条件，两个指针刚好相遇，说明已经遍历了一遍所有元素 */
        if (nums[left] * nums[left] < nums[right] * nums[right]) {
            resultNums[k] = nums[right] * nums[right];
            k--; // k始终指向未排序数组末尾，确定一个最大值k就减1
            right--;
        }
        else {
            resultNums[k] = nums[left] * nums[left];
            k--;
            left++;
        }

}

int main() {

}
