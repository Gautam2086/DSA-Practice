/* Approch:
1. make a set named dictionary and store wordlist
2. make queue (for BFS Algo)  and insert beginWord + also make vis string array + make variable to count steps or number of words
3. pop queue's top ele (string) and increase step counter and change each charac of string by all 26 characters 
4. check if modified string is equal to endWord, if yes then return steps+1
5. if modified string is not presnt in wordList then continue changing charac of original string
6. else if modified string is found in wordlist set && not present in vis string 
then add that string to queue (shortest tranformation seq)

*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> dict;
        for(auto s: wordList) {
            dict.insert(s);
        }
        
        if(dict.find(endWord) == dict.end())
            return 0;
        
        queue<string> q;
        unordered_set<string> vis;
        
        q.push(beginWord);
        vis.insert(beginWord);
        
        int depth= 0;
        
        while(!q.empty())
        {
            depth   ++;
            int s= q.size();
            while(s--)
            {
                string curr= q.front();   q.pop();
                for(int i=0; i<curr.length(); i++)
                {
                    string temp= curr;
                    
                    for(char c='a'; c<='z'; c++)
                    {
                        temp[i]= c;
                        
                        if(curr.compare(temp) == 0 || (dict.find(temp) == dict.end()) )
                            continue;
                        if(temp.compare(endWord) == 0) 
                            return depth+1;
                    
                        if(vis.find(temp) == vis.end() && dict.find(temp) != dict.end()) {
                            q.push(temp);
                            vis.insert(temp);
                        }
                    }
                }
                
            }
        }
        
        return 0;
    }
};