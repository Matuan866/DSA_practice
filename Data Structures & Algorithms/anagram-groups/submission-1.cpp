class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty()) return {};
        unordered_map<string, vector<string>> hashTable;

        vector<string>::iterator it=strs.begin();
        while(it!=strs.end()){
            string key=*it;
            sort(key.begin(),  key.end());
            hashTable[key].push_back(*it);
            ++it;
        }
        vector<vector<string>> res;
        for(const auto& pair:hashTable){
            res.push_back(pair.second);
        }
        return res;
    
    }
};
