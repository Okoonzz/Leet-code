#include <bits/stdc++.h>
using namespace std;

int reverse(int x) {
    long res = 0;
    while (x!=0)
    {
        res = res*10 + x%10;
        x /= 10;
    }
    return (res < INT_MIN || res > INT_MAX) ? 0 : res;       
}

int main(){

    int test = 1534236469;
    cout << reverse(test);

}
