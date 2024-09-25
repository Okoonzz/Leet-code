#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // tạo node đầu và node cur để quản lý. Sau cùng trả về node đầu
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            int sum = carry;

            if(l1 != nullptr) {
                sum += l1->val;
                l1 = l1 ->next;
            }
            if(l2 != nullptr){
                sum += l2->val;
                l2 = l2 ->next;
            }

            carry = sum / 10;

            // dùng cách này sẽ tránh được việc carry không reset. Nếu dùng if thì 
            // carry sẽ không reset
            ListNode* tmp = new ListNode(sum%10);

            if(cur == nullptr){
                cur = head = tmp; //gán node cur = head = tmp để quản lý linked list
            }
            else{
                cur->next = tmp;
                cur = cur->next;
            }
        }

        if(carry > 0){
            cur->next = new ListNode(carry);
        }
        return head;
    }
};

void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val;
        if (node->next != nullptr) {
            cout << " -> ";
        }
        node = node->next;
    }
    cout << endl;
}

int main() {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    
    Solution solution;
    
    ListNode* result = solution.addTwoNumbers(l1, l2);

    printList(result);

    return 0;
}
