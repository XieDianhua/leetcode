#include<vector>
#include<unordered_set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    // 1. 数组转换为去重的集合
    unordered_set<int> set1, set2;
    for (auto& num : nums1) {
        set1.insert(num);
    }
    for (auto& num : nums2) {
        set2.insert(num);
    }
    return getIntersection(set1, set2);
}

vector<int> getIntersection(unordered_set<int>& set1, unordered_set<int>& set2) {
    // 2. 确保遍历较小的集合
    if (set1.size() > set2.size()) {
        return getIntersection(set2, set1);
    }
    vector<int> intersection;
    // 3. 遍历较小集合，判断另一个集合是否也存在当前元素，存在则将其添加到返回值
    for (auto& num : set1) {
        if (set2.count(num)) {
            intersection.push_back(num);
        }
    }

    //4. 返回交集
    return intersection;
}