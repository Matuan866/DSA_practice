class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashTable;
        for(const string& s:strs){
            int cnt[26]={0};
            for(char c:s) cnt[c-'a']++;
            string key="";
            for(int i=0;i<26;++i) key+=cnt[i]+'#';
            hashTable[key].push_back(s);
        }
        vector<vector<string>> res;
        res.reserve(hashTable.size());
        for(auto& pair:hashTable){
            res.push_back(move(pair.second));
        }
        return res;
    }
};
