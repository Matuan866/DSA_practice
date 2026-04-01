class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> tmp(nums.size());
        mergeSort(nums, tmp, 0, nums.size()-1);
        return nums;
    }
private:
    void mergeSort(vector<int>& nums, vector<int>& tmp, int left, int right){
        if(left>=right) return ;
        int mid=left+(right-left)/2;

        mergeSort(nums, tmp, left, mid);
        mergeSort(nums, tmp, mid+1, right);
        merge(nums, tmp, left, mid, right);

    }
    void merge(vector<int>& nums, vector<int>& tmp, int left, int mid, int right){
        int i=left;
        int j=mid+1;
        int k=left;


        while(i<=mid&&j<=right){
            if(nums[i]<=nums[j]) tmp[k++]=nums[i++];
            else tmp[k++]=nums[j++];
        }
        while(i<=mid) tmp[k++]=nums[i++];
        while(j<=right) tmp[k++]=nums[j++];

        for(int index=left;index<=right;++index) nums[index]=tmp[index];
    }
};