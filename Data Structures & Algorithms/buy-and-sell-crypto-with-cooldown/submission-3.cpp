class Solution {
private: 
    int bottom_up(const vector<int>& prices, vector<vector<int>>& dp){
        int n=prices.size();
        dp.assign(prices.size()+1, vector<int>(2, 0));
        for(int i=n-1;i>=0;--i){
            for(int canBuy=1;canBuy>=0;--canBuy){
                if(canBuy){
                    int buy=dp[i+1][0]-prices[i];
                    int cooldown=dp[i+1][1];
                    dp[i][canBuy]=max(buy, cooldown);
                }
                else{
                    int sell=(i+2<n)?(prices[i]+dp[i+2][1]):prices[i];
                    int cooldown=dp[i+1][0];
                    dp[i][canBuy]=max(sell, cooldown);
                }
            }
        }

        return dp[0][1];
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp;
        return bottom_up(prices, dp);
    }
};
