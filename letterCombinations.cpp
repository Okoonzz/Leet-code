#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<string>& res, string digits, int idx, vector<pair<char, string>> phone, string& path) {
    if(digits.empty()) {
        return;
    }

    //GOAL
    if(idx == digits.size()) {
        res.push_back(path);
        return;
    }

    //constraint
    // get string of current digit
    string letter = phone[digits[idx]-'0'].second;

    //choice
    for(auto c:letter){
        path.push_back(c);
        backtrack(res, digits, idx+1, phone, path);
        path.pop_back();
    }


}

vector<string> letterCombinations(string digits) {
    vector<string> res;
    
    vector<pair<char, string>> phone = {
        {'0', ""},
        {'1', ""},
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    
    string path;
    backtrack(res, digits, 0, phone, path);
    return res;
}

int main() {
    string digits = "13";
    vector<string> res = letterCombinations(digits);
    for (const string& s : res) {
        cout << s << " ";
    }
    return 0;
}
