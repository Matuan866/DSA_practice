class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected(heights.begin(), heights.end());
        for(int i=0;i<(int)heights.size();++i){
            bool swaped=false;
            for(int j=0;j<(int)heights.size()-i-1;++j){
                if(heights[j]>heights[j+1]) 
                    {swap(heights[j], heights[j+1]);swaped=true;}
            }
            if(!swaped) break;
        }

        int cnt=0;
        for(int i=0;i<(int)heights.size();++i){
            if(heights[i]!=expected[i]) ++cnt;
        }
        return cnt;
    }
};