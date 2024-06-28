#include<iostream>
#include<vector>

int binarySearch(std::vector<int>& array, int target) {
    int low = 0;
    int high = sizeof(array) - 1;
    int mid = 0;

    while (low <= high) {
        mid = (low + high) / 2; //mid在while内和while外定义有什么区别

        if (target == array[mid])
            return mid;
        else if (target < array[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main() {

    return 0;
}