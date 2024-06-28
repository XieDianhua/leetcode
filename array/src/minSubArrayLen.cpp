#include<vector>
#include<stdint.h>

using namespace std;

//int minSubArrayLen(int target, vector<int>& nums) {
//    int result = INT32_MAX;
//    int sum = 0;
//    int subLength = 0;/* 子序列长度 */

//    for (int i = 0;i < nums.size();i++) {   /* 设置子序列起点为i */
//        sum = 0;
//        for (int j = i;j < nums.size();j++) { /* 设置子序列终止位置为j */
//            sum += nums[j];
//            if (sum >= target) {    /* 一旦发现子序列和超过了target，更新result */
//                subLength = j - i + 1;
//                result = result < subLength ? result : subLength;
//                break;
//            }
//        }
//    }
//    return result == INT32_MAX ? 0 : result;
//}

/* 滑动窗口法 */
int minSubArrayLen(int target, vector<int>& nums) {
    int result = INT32_MAX;
    int sum = 0;
    int i = 0;
    int subLength = 0;

    for (int j = 0;j < nums.size();j++) {
        sum += nums[j];
        while (sum >= target) {
            subLength = j - i;
            result = result < subLength ? result : subLength;
            sum -= nums[i];
            i++;
        }
    }

    return result == INT32_MAX ? 0 : result;
}

int main() {

}
