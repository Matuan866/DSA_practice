class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for(int i=0;i<k;++i){
            for(int j=0;j<(int)nums.size()-1;++j){
                if(nums[j]>nums[j+1]) swap(nums[j], nums[j+1]);
            }
        }
        return *(nums.rbegin()+k-1);
    }
};
