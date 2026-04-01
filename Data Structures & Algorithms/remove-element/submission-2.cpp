class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int k=0;
        while(i<nums.size()){
            if(nums[i]==val){
                ++i;
                continue;
            }
            nums[k++]=nums[i++];
        }
        return k;
    }
};