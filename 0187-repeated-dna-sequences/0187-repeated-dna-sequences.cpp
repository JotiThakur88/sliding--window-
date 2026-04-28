class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        vector<string> result;
        
        for (int i = 0; i + 9 < s.size(); i++) {
            string sub = s.substr(i, 10);
            mp[sub]++;
            
            if (mp[sub] == 2) {  // add only once
                result.push_back(sub);
            }
        }
        
        return result;
    }
};