#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {

    //sort để lọc ra được các tiền tố giống nhau dài nhất
    sort(strs.begin(), strs.end());

    // tìm độ dài nhỏ nhất vì chỉ duyệt qua chuỗi nào có độ dài nhỏ nhất
    int min_len = min(strs.front().size(), strs.back().size());

    //for (auto str: strs) cout << str << " ";

    // khi đã sắp xếp rồi thì chỉ cần tìm ở chuỗi đầu và cuối
    // vì tiền tố chung nào giữa 2 chuỗi này cũng là tiền tố cho chuỗi ở giữa
    int i = 0;
    while (i <= min_len && strs.front()[i] == strs.back()[i])
    {
        i++;
    }
    if (i == 0) return "";
    return strs.front().substr(0, i);
}

int main(){
    vector<string> strs = {"flower","flow","flight"};
    cout << longestCommonPrefix(strs);
}
