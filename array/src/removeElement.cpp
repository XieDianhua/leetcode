#include<iostream>
#include<vector>

/* 暴力搜索 */
//int removeElement(std::vector<int>& nums, int val) {
//    int size = nums.size();
//    for (int i = 0; i < size; i++) {
//        if (nums[i] == val) {
//            for (int j = i + 1; j < size; j++) {
//                nums[j - 1] = nums[j];
//            }
//            i--; //避免漏查找，或许下一个元素也是待查找数
//            size--;
//        }
//    }
//    return size;
//}

/* 双指针法 */
int removeElement(std::vector<int>& nums, int val) {
    int slowIndex = 0;
    for (int fastIndex = 0;fastIndex < nums.size();fastIndex++) {
        if (nums[fastIndex] != val) {
            nums[slowIndex] = nums[fastIndex];
            slowIndex++;
        }
    }
}
int main() {
    // removeElement();
}
