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
        vector<int> v;
        
        ListNode* tmp= head;
        
        while(tmp) {
            v.push_back(tmp->val);
            tmp= tmp->next;
        }
        
        if(k >= v.size())
            k= k % v.size();
        
        ListNode* dummy= new ListNode(0);
        tmp= dummy;
        
        
        reverse(v.begin(), v.end()-k);
        reverse(v.end()-k, v.end());
        
        reverse(v.begin(), v.end());
        
        for(int i=0; i<v.size(); i++) {
            tmp->next= new ListNode(v[i]);
            tmp= tmp->next;
        }
        tmp->next= NULL;
        
        return dummy->next;
    }
};