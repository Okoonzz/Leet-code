//dp: https://viblo.asia/p/gioi-thieu-ve-thuat-toan-dynamic-programming-Ljy5VYmGlra
// ví dụ s = "aabbaa"
// lập 1 bảng dp 2D (n*n n là size strings) dùng để ghi lại những chuỗi nào là Palindromic với index từng hàng từng cột là từng char của strings
// Với (i, j) là thứ tự bắt đầu của chuỗi con cần xét. Ví dụ s(0,3) = "aabb"
// Đánh dấu tất cả các phần tử chéo vì s(i,i) chắc chắn Palindromic.
// Xét tiếp đến chuỗi con có len là 2. Nếu là Palindromic đánh dấu true còn không thì flase
// xét các chuỗi con có len lớn hơn 2. Với chuỗi con có len lớn hơn 2 ta sẽ có công thức như sau:
// Để thỏa được 1 chuỗi là Palindromic xét xem vị trí bắt đầu (i,j) có như nhau hay không
// Nếu thỏa thì xét tiếp (i+1, j-1) nếu là true thì đánh dấu(i,j) đó là Palindromic
// Nếu không thỏa thì không phải là Palindromic
/*
            |----|----|----|----|----|----|
            |  0 |  1 |  2 |  3 |  4 |  5 |
            |----|----|----|----|----|----|     
            |  a |  a |  b |  b |  a |  a |
    |--|----|----|----|----|----|----|----|
    |0 |  a |  1 |    |    |    |    |    |
    |--|----|----|----|----|----|----|----|
    |1 |  a |    | 1  |    |    |    |    |
    |--|----|----|----|----|----|----|----|
    |2 |  b |    |    |  1 |    |    |    |
    |--|----|----|----|----|----|----|----|
    |3 |  b |    |    |    |  1 |    |    |
    |--|----|----|----|----|----|----|----|
    |4 |  a |    |    |    |    | 1  |    |
    |--|----|----|----|----|----|----|----|
    |5 |  b |    |    |    |    |    |  1 |
    |--|----|----|----|----|----|----|----|
*/

#include <bits/stdc++.h>
using namespace std;

    string longestPalindrome(string s) {
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // đánh dấu ptu trên đường chéo chính
    int maxlen = 1;
    for(int i = 0; i < n; i++){
        dp[i][i] = true;
    }

    // xâu có len là 2
    int start =0;
    for(int i = 0; i < n-1; i++){
        if(s[i] == s[i+1]){
            dp[i][i+1]=true;
            start = i;
            maxlen = 2;
        }
    }

    for(int k = 3; k <= n; k++){
        for(int i = 0; i <= n-k; i++){ // chỉ chạy đến n-k vì đang xét xâu có len = 3
            int j = i+k-1;             // tìm phần cuối của xâu đang xét
            if(dp[i+1][j-1] && s[i] == s[j]){
                dp[i][j] =  true;

                if(k > maxlen){
                    start = i;
                    maxlen = k;
                }
            }
        }
    }

    return s.substr(start, maxlen);
    }

int main(){
//https://www.youtube.com/watch?v=UflHuQj6MVA

    cout << longestPalindrome("babad");

}
