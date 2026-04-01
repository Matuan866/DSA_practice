class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt;
        solution(nums, cnt);
    }
private:
    void solution(vector<int>& nums, vector<int>& cnt){
        cnt.resize(3);
        for(int color:nums) cnt[color]++;
        
        int index=0;
        for(int i=0;i<3;++i){
            while(cnt[i]>0){
                nums[index++]=i;
                --cnt[i];
            }
        }
    }
};