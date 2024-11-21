#include <iostream>
#include <vector>
#include <climits>
using namespace std;
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

// ------------------------------------------------BACKTRACKING------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

/* 
# mã giả backtracking
function backtrack(partial_solution):
    if is_solution(partial_solution):
        output(partial_solution)
        return
    
    if reject(partial_solution):
        return
        
    candidates = get_candidates(partial_solution)
    for candidate in candidates:
        add_to_solution(partial_solution, candidate)
        backtrack(partial_solution)
        remove_from_solution(partial_solution, candidate)
*/

class Solution {
private:
    int minJumps = INT_MAX;
    vector<int> bestPath;
    
    // Lấy các ứng cử viên (candidates) là các độ dài bước nhảy có thể chọn từ vị trí hiện tại
    // Ví dụ: nếu nums[index] = 3 thì có thể chọn 1, 2 hoặc 3 bước nhảy
    vector<int> getCandidates(vector<int>& nums, int index) {
        vector<int> candidates;
        for(int j = nums[index]; j > 0; j--) {
            candidates.push_back(j);
        }
        return candidates;
    }

    bool isValidSolution(int index, int n) {
        return index == n - 1;
    }

    bool shouldReject(int jumps) {
        return jumps >= minJumps;
    }
    
    void backtrack(vector<int>& nums, int index, int jumps, vector<int>& path) {
        int n = nums.size();
        
        if (index >= n - 1) {
            if (isValidSolution(index, n) && jumps < minJumps) {
                minJumps = jumps;
                bestPath = path;
            }
            return;
        }
        
        if (shouldReject(jumps)) return;
        
        vector<int> candidates = getCandidates(nums, index);

        // thử tất cả các bước nhảy có thể từ vị trí hiện tại
        // mỗi bước nhảy sẽ thêm vào path và thử tiếp tục với bước nhảy tiếp theo
        // nếu không thành
        // thì bỏ bước nhảy hiện tại ra khỏi path và thử bước nhảy tiếp theo
        // đến khi thử hết tất cả các bước nhảy có thể
        // thì quay lại bước nhảy trước đó
        for(int jump : candidates) {
            // Add candidate to solution
            path.push_back(jump);
            
            // Recur with candidate
            backtrack(nums, index + jump, jumps + 1, path);
            
            // Remove candidate from solution
            path.pop_back();
        }
    }
    
public:
    pair<int, vector<int>> jump(vector<int>& nums) {
        minJumps = INT_MAX;
        bestPath.clear();
        vector<int> path;
        backtrack(nums, 0, 0, path);
        return {minJumps, bestPath};
    }
};

int main() {
    vector<vector<int>> testCases = {
        {2,3,1,1,4},
        {2,3,0,1,4},
        {1,2,3}
    };
    
    Solution sol;
    for (auto& nums : testCases) {
        cout << "Array: ";
        for (int num : nums) cout << num << " ";
        
        auto [jumps, path] = sol.jump(nums);
        
        cout << "\nMinimum jumps: " << jumps;
        cout << "\nPath: ";
        for (int jump : path) cout << jump << " ";
        cout << "\n\n";
    }
    
    return 0;
}

