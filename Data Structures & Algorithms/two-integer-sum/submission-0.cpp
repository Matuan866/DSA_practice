class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complements;
        vector<int> ans;
        for(int i=0;i<(int)nums.size();++i){
            int comple=target-nums[i];
            if(complements.count(comple)){
                ans={complements[comple], i};
            }
            else {
                complements[nums[i]]=i;
            }
        }
    return ans;
    }
};
