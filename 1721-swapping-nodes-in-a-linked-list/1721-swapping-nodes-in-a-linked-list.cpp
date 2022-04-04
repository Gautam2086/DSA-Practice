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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> v;
        ListNode* tmp= head;
        
        while(tmp) {
            v.push_back(tmp->val);
            tmp= tmp->next;
        }
        
        swap(v[k-1], v[v.size()-k]);
        
        tmp= head;
        int i= 0;
        
        while(tmp) {
            tmp->val= v[i++];
            tmp= tmp->next;
        }
        
        return head;
    }
};