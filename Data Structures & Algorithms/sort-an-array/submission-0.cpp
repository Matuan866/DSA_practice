class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        myMergeSort(nums);
        return nums;
    }
private:
    void MergeArr(vector<int>& arr, vector<int>& arr1, vector<int>& arr2){
        int i=0, j=0, index=0;
        while(i<arr1.size()&&j<arr2.size()){
            if(arr1[i]<arr2[j]) arr[index++]=arr1[i++];
            else arr[index++]=arr2[j++];
        }

        while(i<arr1.size()) arr[index++]=arr1[i++];
        while(j<arr2.size()) arr[index++]=arr2[j++];
    }

    void myMergeSort(vector<int>& nums){
        int mid=nums.size()/2;
        if(mid==0) return ;
        vector<int> left(nums.begin(), nums.begin()+mid);
        vector<int> right(nums.begin()+mid, nums.end());

        myMergeSort(left);
        myMergeSort(right);
        MergeArr(nums, left, right);
    }
};