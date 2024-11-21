#include <iostream>
#include <vector>
#include <climits>
using namespace std;


// dùng backtracking, chọn từng bước nhảy từ vị trí hiện tại đến vị trí cuối cùng
// nếu vị trí hiện tại >= vị trí cuối cùng thì cập nhật số lần nhảy nhỏ nhất
// tham khảo mã giả của backtracking https://viblo.asia/p/thuat-toan-quay-lui-backtracking-bJzKmLbD59N

// int minJumps;

// void Backtracking(vector<int>& nums, int position, int jumps) {
//     if (position >= nums.size() - 1) {
//         if (jumps < minJumps) {
//             minJumps = jumps;
//         }
//         return;
//     }

//     for (int i = 1; i <= nums[position]; ++i) {
//         if (position + i < nums.size()) {
//             Backtracking(nums, position + i, jumps + 1);
//         }
//     }
// }

// int jump(vector<int>& nums) {
//     minJumps = INT_MAX;
//     Backtracking(nums, 0, 0);
//     return minJumps;
// }


// ý tưởng là tham lam, mỗi lần chọn vị trí i, ta chọn vị trí i + nums[i] xa nhất có thể
// nếu i == currentEnd thì tăng số lần nhảy và cập nhật currentEnd = currentFarthest
// vì nếu i == currentEnd thì ta đã nhảy đến vị trí xa nhất có thể từ vị trí trước đó
// nếu i != currentEnd thì cập nhật currentFarthest = max(currentFarthest, i + nums[i])
// vì ta cần chọn vị trí xa nhất có thể từ vị trí trước đó

// tham khảo thêm dùng 2 con trỏ tại https://www.youtube.com/watch?v=dJ7sWiOoK7g
// về cơ bản thì 2 con trỏ và cách code ở dưới như nhau
int jump(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
        return 0;
    }

    int jumps = 0, currentEnd = 0, currentFarthest = 0;
    for (int i = 0; i < n - 1; ++i) {
        currentFarthest = max(currentFarthest, i + nums[i]);
        if (i == currentEnd) {
            ++jumps;
            currentEnd = currentFarthest;
        }
    }

    return jumps;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << "Minimum jumps: " << jump(nums) << endl;
    return 0;
}
