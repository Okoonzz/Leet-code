struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode() : val(0), next(nullptr) {}
    ListNode (int x, ListNode *next) : val(x), next(next) {}
};



ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> mergelist;
        while(list1 != NULL){
            mergelist.push_back(list1->val);
            list1 = list1->next;
        }

        while(list2 != NULL){
            mergelist.push_back(list2->val);
            list2 = list2->next;
        }

        sort(mergelist.begin(), mergelist.end());

        ListNode *tmp = new ListNode();
        ListNode *head = tmp;
        for (int i = 0; i < mergelist.size(); ++i){
            tmp->next = new ListNode(mergelist[i]);
            tmp = tmp->next;
        }
        head = head->next;

        return head;
}
