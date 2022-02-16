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
    // TC: O(n), where n is the size of the linked list
    // SC: O(n), where n is the stack space utilized for recursion
    
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)                    // Edge case
            return head;
        
        ListNode* prev= NULL;
        ListNode* curr= head;
        ListNode* next= NULL;
        
        int count= 0;
        while(curr!=NULL && count<2)                // Swap first two links in linked list
        {
            next= curr->next;                       // backup
            curr->next= prev;                       // link
            prev= curr;                             // move forward
            curr= next;
            count++;
        }
        
        head->next= swapPairs(next);                // swap rest all nodes through recursion
        
        return prev;                                // prev is pointing the new head
        
    }
};