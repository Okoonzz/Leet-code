#include <bits/stdc++.h>
using namespace std;

int getval(char c){
    vector<pair<char, int>> romanValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    for (auto num: romanValues){
        if(num.first == c) return num.second;
    }
    return 0;
}

int romanToInt(string s) {
    int res = 0;
    int next = 0;
    for (int i = 0; i < s.length(); i++) {
        int cur = getval(s[i]);

        if (i < s.length() - 1) next = getval(s[i + 1]);  
        else next = 0;

        if (cur < next) res -= cur;
        else res += cur;
    }
    return res;
}

int main(){
    cout<<romanToInt("LVIII");
}
