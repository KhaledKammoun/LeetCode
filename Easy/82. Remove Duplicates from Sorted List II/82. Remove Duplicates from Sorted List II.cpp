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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==nullptr || head->next==nullptr)
            return head ;
        map<int,int> m ;
        ListNode* x = head ;
        while (x!=nullptr){
            m[x->val]++ ;
            x=x->next ;
        }
        ListNode dummy ;
        dummy.next = head ;
        ListNode* prev = &dummy ;
        ListNode* curr = head ;
        while (curr!=nullptr){
            ListNode* nxt = curr->next ;
            if (m[curr->val]>1){
                prev->next = nxt ;
            }
            else 
                prev = curr ;
            curr = nxt ;
        }
        return dummy.next ;
    }
};