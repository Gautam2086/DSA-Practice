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

/* Use Merge Sort 
=> TC: O(n*logn)
=> SC: O(1)
*/

class Solution {
public:
    
    ListNode* mergedList(ListNode* l1, ListNode* l2) {       // Recursively merge Two sorted Lists
        
        if(l1 == NULL) return l2;               //Base case
        if(l2 == NULL) return l1;               //Base case
        
        ListNode* res;
        
        if(l1->val < l2->val) {
            res= l1;
            res->next= mergedList(l1->next, l2);         //recursion
        }
        
        else {
            res= l2;
            res->next= mergedList(l1, l2->next);         //recursion
        }
        return res;
    }
    
    ListNode* middle(ListNode* head) {           // find middle node using Tortoise & Hare approach 
        
        if(head==NULL || head->next == NULL)                // Base Case
            return head;
        
        ListNode* fast= head, *slow= head;                      
        
                                        
        while(fast->next != NULL && fast->next->next != NULL)   // if there are two mid nodes then 
        {                                                       // return 1st middle one
            slow= slow->next;                                   
            fast= fast->next->next;
        }
        return slow;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next == NULL)        // base case
            return head;
        
        ListNode* mid= middle(head);                // Find middle node
        
        ListNode* head2= mid->next;                 // break 2 lists at mid point
        mid->next= NULL;                            // as 1st half and 2nd half
        
        ListNode* left= sortList(head);             // 1st half is sorted recursively
        ListNode* right= sortList(head2);           // 2nd half is sorted recursively
                
        return mergedList(left, right);             // merge both sorted half
    }
};