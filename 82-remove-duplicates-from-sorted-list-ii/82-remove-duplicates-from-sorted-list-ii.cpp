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
        vector<int> v;
        
        ListNode* tmp= head;
        while(tmp) {
            v.push_back(tmp->val);
            tmp= tmp->next;
        }
        
        unordered_map<int, int> mp;
        for(auto n: v) {
            mp[n]++;
        }
        
        
        v.clear();
        
        for(auto it: mp) 
        {
            if(it.second ==1)
                v.push_back(it.first);
        }
        sort(v.begin(), v.end());
        
        ListNode* h= new ListNode(0);
        tmp = h;
        
        for(int i=0; i<v.size(); i++) {
            tmp->next= new ListNode(v[i]);
            tmp= tmp->next;
        }
        
        return h->next;
    }
};