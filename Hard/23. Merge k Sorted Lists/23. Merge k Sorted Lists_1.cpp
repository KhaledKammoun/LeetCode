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
        if (lists.empty())
            return nullptr ;
        while (lists.size()>1){
            vector<ListNode*> new_list ;
            for (int i = 0 ; i< lists.size() ; i+=2){
                ListNode* l1 = lists[i] ;
                ListNode* l2 = (i+1<lists.size()) ?lists[i+1]  : nullptr ;
                l1 = mergeTwoLists(l1,l2) ;
                new_list.push_back(l1) ;
            }
            lists = new_list ;
        }
        return lists[0] ;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0) ; 
        ListNode* new_list = dummy ; 
        while (l1 || l2){
            if (!l1 || (l2 && l1->val > l2->val)){
                new_list->next = new ListNode(l2->val) ;
                l2 = l2->next ;
            }
            else{
                new_list->next = new ListNode(l1->val) ;
                l1 = l1->next ;
            }
            new_list = new_list->next ;   
        }
        return dummy->next ;
    }
};