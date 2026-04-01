class Solution {
private: 
    int maxProfit(int i, bool canBuy, const vector<int>& prices, vector<vector<int>>& dp){
        if(i>=prices.size()) return 0;
        else if(dp[i][canBuy]!=-1) return dp[i][canBuy];

        if(canBuy){
            int buy = maxProfit(i+1, false, prices, dp)-prices[i];
            int cooldown=maxProfit(i+1, true, prices, dp);

            return dp[i][canBuy]=max(buy, cooldown);
        }
        else{
            int sell=maxProfit(i+2, true, prices, dp)+prices[i];
            int cooldown=maxProfit(i+1, false, prices, dp);

            return dp[i][canBuy]=max(sell, cooldown);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int i=0;
        bool canBuy=true;
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return maxProfit(0, canBuy, prices, dp);
    }
};
