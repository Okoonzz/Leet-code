#include <bits/stdc++.h>
using namespace std;

bool isPo(int x)
{
    if (x < 0)
        return false;
    int tmp_1 = x;
    long long tmp_2 = 0;
    while (tmp_1 != 0)
    {
        long long tmp_3 = tmp_1 % 10;
        tmp_2 = tmp_2 * 10 + tmp_3;
        tmp_1 /= 10;
    }
    if (tmp_2 == x)
        return true;
    return false;
}

int main()
{
    cout << isPo(-121);
}
