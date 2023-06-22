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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<int>s ;
        for (auto x : lists){
            ListNode* node = x ;
            while (node!=nullptr){
                s.insert(node->val) ;
                node = node->next ;
            }
        }
        ListNode* dummy = new ListNode(-1) ;
        ListNode* var = dummy ;

        for (auto x : s){
            ListNode* node = new ListNode(x) ;
            var->next = node ;
            var = var->next ;
        }
        return dummy->next ;
    }
};