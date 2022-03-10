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
    /*
        3 4 2            9 9 9 9 9 9 9 
        4 6 5            9 9 9 9
        -----            ---------------
        8 0 7            8 9 9 9 0 0 0 1
        -----            ---------------
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        long carry= 0;
        long sum= 0;
        ListNode *tmp1= l1;
        ListNode* tmp2= l2;
        ListNode* dummy= new ListNode(0);
        ListNode* temp= dummy;
        
        while(tmp1 && tmp2) 
        {
            sum= tmp1->val + tmp2->val + carry;
            
            temp->next= new ListNode(sum % 10);
            temp= temp->next;
            
            carry= sum/10;
            
            tmp1= tmp1->next;
            tmp2= tmp2->next;
        }
        
        if(tmp1!=NULL)
        {
            while(tmp1)
            {
                sum= tmp1->val+carry;
                temp->next= new ListNode(sum%10);
                temp= temp->next;
                tmp1= tmp1->next;
                carry= sum/10;
            }
            
        }
        if(tmp2!=NULL)
        {
            while(tmp2)
            {
                sum= tmp2->val+carry;
                temp->next= new ListNode(sum%10);
                temp= temp->next;
                carry= sum/10;
                tmp2= tmp2->next;
            }
            
        }
        
        while(carry != 0) {
            temp->next= new ListNode (carry);
            temp= temp->next;
            carry /= 10;
        }
         
        temp->next= NULL;
        
        return dummy->next;
    }
};