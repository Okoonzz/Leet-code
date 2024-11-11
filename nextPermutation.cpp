#include <bits/stdc++.h>
using namespace std;

/*
Ý tưởng cho bài này sẽ xác định 2 vấn đề chính
1. Xác định phần tử cần di chuyển (pivot)
2. xác định phần tử cần thay thế

- Đối với phần tử cần di chuyển xác định bằng cách tìm phần tử bên phải cùng trong mảng xét, sao cho phần tử đó
nhỏ hơn phần tử bên phải nó.
- Đối với phần tử cần thay thế xác định bằng cách tìm phần tử bên phải cùng trong mảng xét, sao cho phần tử đó
lớn hơn phần tử cần di chuyển.

- Sau khi xác định và thay thế xong, cần sắp xếp lại thứ tự phía sau pivot

https://www.geeksforgeeks.org/next-permutation/
*/


void nextPermutation(vector<int>& nums) {
    int pivot = -1;

    // tìm pivot bên phải cùng
    for(int i = nums.size()-2; i >= 0; i--){
        if(nums[i] < nums[i+1]){
            pivot = i;
            break;
        }
    }

    if(pivot == -1){
        reverse(nums.begin(), nums.end());
        return;
    } 

    // tìm phần tử cần thay thế
    for(int i = nums.size()-1; i > pivot ; i--){
        if(nums[i] > nums[pivot]){
            swap(nums[i], nums[pivot]);
            break;
        }
    }

    reverse(nums.begin()+pivot+1, nums.end());
}
int main()
{
    vector<int> arr = {1,3,2};
    nextPermutation(arr);    
    for (int x : arr) 
        cout << x << " ";    
    return 0;
}
