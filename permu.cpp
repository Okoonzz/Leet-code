#include <bits/stdc++.h>
using namespace std;


// tham khảo tại: https://www.youtube.com/watch?v=Nabbpl7y4Lo
// keywords backtracking: https://www.youtube.com/watch?v=Zq4upTEaQyM


void backtrack(vector<int>&nums, vector<vector<int>>&res, vector<bool> used, vector<int>&permu){
    // GOAL
    if(permu.size() == nums.size()){
        res.push_back(permu);
        return;
    }

    for(int i =0; i<nums.size(); i++){
        // CONSTRAINT
        if(!used[i]){

            // CHOICE
            permu.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, res, used, permu);
            permu.pop_back();
            used[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<bool> used(nums.size(), false);
    vector<int> permu;
    backtrack(nums, res, used, permu);
    return res;
}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permute(nums);
    for(auto& res : result) {
        for(int num : res) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
