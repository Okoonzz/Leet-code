#include <bits/stdc++.h>
using namespace std;

/*
- Ý tưởng vẫn lấy số bị chia trừ cho số chia nhưng trừ theo lớn nhất chứ không phải trừ từng đơn vị
- ví dụ: 20/3
- lần lượt 20 - (3*6)
- Ta thấy 6 =  (2^2+2^1) ==> 3*6 = 3*2^2 + 2*2^1 ==> (20 - 3*2^2) - (3*2^1)
- Ta cứ duyệt tìm số lớn nhất mà số bị chia có thể trừ. Tìm được trừ đi và lấy kết quả duyệt tìm tiếp và trừ tiếp
đến khi nào số bị chia nhỏ hơn số chia thì thôi. Kết quả sẽ là các số viết dưới dạng 2^0+2^1+2^2+...
*/
// https://www.youtube.com/watch?v=pBD4B1tzgVc

int divide(int dividend, int divisor) {
    bool sign = false;
    if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
    }
    if((dividend >= 0 && divisor < 0) || (dividend <=0 && divisor > 0)) sign = true;
    long quotient = 0;

    long div_end = abs(dividend);
    long div_or = abs(divisor);

    while(div_end >= div_or){
        int cnt = 0;

        // so bi chia >= 2^(cnt+1) nếu thỏa thì mới cộng cnt, nếu không thì không cộng cnt
        while(div_end >= (div_or << (cnt+1) )){
            cnt++;
        }

        quotient += (1<<cnt);
        div_end -= (div_or << cnt);
    }

    return sign ? -quotient : quotient;
}
int main(){
    cout << divide(20, 3);
}
