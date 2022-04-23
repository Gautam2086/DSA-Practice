class Solution {
public:
    map<string, string> mp;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(!mp.count(longUrl))
        {
            string shortUrl= "http://tinyurl.com/" + to_string(mp.size());
            mp[longUrl]= shortUrl;
            mp[shortUrl]= longUrl;
        }
        return mp[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));