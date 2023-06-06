/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
    class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
        {
            ListNode* newList = new ListNode() ;
            ListNode* var = newList;
            if (l1==nullptr)
                return l2 ;
            if (l2==nullptr)
                return l1 ;
            while (l1!=nullptr || l2!=nullptr){  
                if (l2==nullptr || (l1!=nullptr && l1->val<l2->val)){
                    var->next = l1 ; 
                    l1 = l1->next ;
                }
                else{
                    var->next = l2 ;
                    l2 = l2->next ;
                }
                var = var->next;
            }

            return newList->next ;
        }
};	