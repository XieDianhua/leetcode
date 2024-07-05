#include <iostream>
#include <deque>
#include <string>
#include <vector>

using namespace std;


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (k == 0) return {};
    vector<int> res;
    deque<size_t> window;
    /*Init K integers in the list*/
    for (size_t i = 0; i < k; i++) {
        while (!window.empty() && nums[i] > nums[window.back()]) {
            window.pop_back();
        }
        window.push_back(i);
    }
    res.push_back(nums[window.front()]);
    /*End of initialization*/
    for (size_t i = k; i < nums.size(); i++) {
        if (!window.empty() && window.front() <= i - k) {
            window.pop_front();
        }
        while (!window.empty() && nums[i] > nums[window.back()]) {
            window.pop_back();
        }
        window.push_back(i);
        res.push_back(nums[window.front()]);
    }
    return res;
}

int main() {
    vector<int> inNums{ 1,3,-1,-3,5,3,6,7 }, outNums;
    int k = 3;

    outNums = maxSlidingWindow(inNums, k);

    return 0;
}