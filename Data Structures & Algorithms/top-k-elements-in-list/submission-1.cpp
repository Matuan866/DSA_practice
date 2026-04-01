class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        return solution(nums, k);
    }
private:
    vector<int> solution(const vector<int>& nums, int k){
        unordered_map<int, int> freq;
        for(int n:nums) freq[n]++;
        vector<pair<int, int>> freqArr;
        for(const auto& p:freq) freqArr.emplace_back(p);

        sort(freqArr.begin(), freqArr.end(), [](const auto& p1, const auto& p2){
            return p1.second>p2.second;
        });
        vector<int> res(k);
        for(int i=0;i<k;++i) res[i]=freqArr[i].first;
        return res;
    }
};
