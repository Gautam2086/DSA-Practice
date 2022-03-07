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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)  return l2;                      // Edge case
        if(l2 == NULL)  return l1;                      // Edge case
                
        ListNode* res;                                  // merged list
            
        if(l1->val < l2->val) {
            res= l1;
            res->next= mergeTwoLists(l1->next, l2);     // recursion
        }
        else {
            res= l2;
            res->next= mergeTwoLists(l1, l2->next);     // recursion
        }
     
        return res;
    }
};