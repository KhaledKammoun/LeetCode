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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int rest = 0 ;
        ListNode* dummy = new ListNode(0) ;
        ListNode* sum = dummy ;
        while (l1!=nullptr || l2!=nullptr || rest!=0){
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            sum->next = new ListNode((x+y+rest)%10) ;
            rest = (x + y +rest)/ 10;
            sum = sum->next ;

            if (l1 != nullptr){
                ListNode*n = l1 ;
                l1 = l1->next;
                delete n ;
            }
            if (l2 != nullptr){
                ListNode*n = l2 ;
                l2 = l2->next;
                delete n ;
            }

        }

        return dummy->next ;
    }
};