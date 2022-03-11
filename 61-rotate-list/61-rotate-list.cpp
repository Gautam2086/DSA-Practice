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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k== 0 ) return head;
        
        int len= 0;
        ListNode* temp= head;
        while(temp) {
            len++;
            temp= temp->next;
        }
        
        if(k>len)   k= k % len;
        if(k== 0 || k==len) return head;
        
        temp= head;
        while(temp->next) {
            temp= temp->next;
        }
        temp->next= head;
        
        temp= head;
        int currLen=1;
        while(currLen != len-k)
        {
            temp= temp->next;
            currLen++;
        }
        ListNode* newHead= temp->next;
        temp->next= NULL;
        
        return newHead;
    }
};