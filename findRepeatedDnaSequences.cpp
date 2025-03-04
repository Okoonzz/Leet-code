#include <bits/stdc++.h>
using namespace std;
//sliding window
vector<string> findRepeatedDnaSequences(string s) {
    if(s.size() < 10) return {};

    set<string> seen, res;
    for(int i = 0; i < s.size() - 9; i++){
        string cur = s.substr(i, 10);
        if(seen.find(cur) == seen.end()){
            seen.insert(cur);
        }
        else{
            res.insert(cur);
        }
    }
    return vector<string>(res.begin(), res.end());

}

int main(){
    string strs = {"A"};
    vector<string> res = findRepeatedDnaSequences(strs);
    cout << res[0] << endl;
}
