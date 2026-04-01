class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> ans;
        int n=nums.size();
        while(n--){
            ans[nums[n]]++;
        }
        for(const auto& [val, freq]:ans){
            if(freq>=2) return true;
        }
        return false;
    }
};