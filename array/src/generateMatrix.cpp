#include<vector>
#include<iostream>
#include <iomanip>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0)); /* 定义一个二维数组 */
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int num = 1;

    while (num <= n * n) { //终止条件
        for (int i = left;i <= right;i++) { //边界条件，左闭右闭
            res[top][i] = num++;
        }
        top++; //立即更新机制，防止了同一个位置被多次写入

        for (int i = top;i <= bottom;i++) {
            res[i][right] = num++;
        }
        right--;

        for (int i = right;i >= left;i--) {
            res[bottom][i] = num++;
        }
        bottom--;

        for (int i = bottom;i >= top;i--) {
            res[i][left] = num++;
        }
        left++;
    }
    return res;
}

// vector<vector<int>> generateMatrix(int n) {
//     if (n <= 0) {
//         return {};
//     }

//     vector<vector<int>> matrix(n, vector<int>(n, 0));
//     int top = 0, bottom = n - 1, left = 0, right = n - 1;
//     int num = 1;

//     while (top <= bottom && left <= right) {
//         for (int i = left; i <= right; ++i) {
//             matrix[top][i] = num++;
//         }
//         top++;

//         for (int i = top; i <= bottom; ++i) {
//             matrix[i][right] = num++;
//         }
//         right--;

//         if (top <= bottom) {
//             for (int i = right; i >= left; --i) {
//                 matrix[bottom][i] = num++;
//             }
//             bottom--;
//         }

//         if (left <= right) {
//             for (int i = bottom; i >= top; --i) {
//                 matrix[i][left] = num++;
//             }
//             left++;
//         }
//     }

//     return matrix;
// }

// vector<vector<int>> generateMatrix(int n) {
//     vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
//     int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
//     int loop = n / 2; // 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
//     int mid = n / 2; // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
//     int count = 1; // 用来给矩阵中每一个空格赋值
//     int offset = 1; // 需要控制每一条边遍历的长度，每次循环右边界收缩一位
//     int i, j;
//     while (loop--) {
//         i = startx;
//         j = starty;

//         // 下面开始的四个for就是模拟转了一圈
//         // 模拟填充上行从左到右(左闭右开)
//         for (j; j < n - offset; j++) {
//             res[i][j] = count++;
//         }
//         // 模拟填充右列从上到下(左闭右开)
//         for (i; i < n - offset; i++) {
//             res[i][j] = count++;
//         }
//         // 模拟填充下行从右到左(左闭右开)
//         for (; j > starty; j--) {
//             res[i][j] = count++;
//         }
//         // 模拟填充左列从下到上(左闭右开)
//         for (; i > startx; i--) {
//             res[i][j] = count++;
//         }

//         // 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
//         startx++;
//         starty++;

//         // offset 控制每一圈里每一条边遍历的长度
//         offset += 1;
//     }

//     // 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
//     if (n % 2) {
//         res[mid][mid] = count;
//     }
//     return res;
// }

int main() {
    int n = 4; // 你可以修改这个值来测试不同大小的矩阵
    vector<vector<int>> result = generateMatrix(n);

    // 计算最大数位数，用于确定 setw 的宽度
    int maxVal = n * n;
    int maxDigits = to_string(maxVal).length();

    // 打印矩阵，使用 setw 和 right 来对齐
    for (const auto& row : result) {
        for (int val : row) {
            cout << setw(maxDigits) << right << val << " ";
        }
        cout << endl;
    }

    return 0;
}