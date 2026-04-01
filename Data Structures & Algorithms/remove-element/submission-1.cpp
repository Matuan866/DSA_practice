class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i=0;i<nums.size();++i){
            if(nums[i]==val){
                for(int j=i+1;j<nums.size();++j){
                    nums[j-1]=nums[j];
                }
                nums.pop_back();--i;
            }
        }
        return nums.size();
    }
};