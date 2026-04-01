class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int res=0;
        int maxCnt=0;
        int threshold=nums.size()/2;
        for(int num:nums){
            cnt[num]++;
            if(cnt[num]>maxCnt){
                res=num;
                maxCnt=cnt[num];
            }
        }
        return res;
    }
};