#include <bits/stdc++.h>
using namespace std;

int lenMax(string s){
    set<char> tmp;
    int l = 0;
    int res = 0;
    // dùng 2 con trỏ. Right duyệt qua hết string. Nếu trùng thì xóa từ ptu left 
    // đến khi nào hết trùng thì dừng lại. Nếu không trùng thì thêm vào set. Sau cùng
    // tính toán kết quả bằng cách lấy r - l + 1
    for(int r = 0; r < s.length(); r++){
        while(tmp.find(s[r])!=tmp.end()){
            tmp.erase(s[l]);
            l += 1;
        }
        tmp.insert(s[r]);
        res = max(res, r-l+1);
    }
    return res;
}

int main()
{
    cout << lenMax("pwwkew");
}
