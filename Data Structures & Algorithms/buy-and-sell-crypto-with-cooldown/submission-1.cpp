class Solution {
private:
    int dfs(int i, bool canBuy, const vector<int>& prices, vector<vector<int>>& dp){
        if(i>=prices.size()) return 0;
        if(dp[i][canBuy]!=-1) return dp[i][canBuy];
        
        int cooldown=dfs(i+1, canBuy, prices, dp);
        if(canBuy){
            int buy=dfs(i+1, false, prices, dp)-prices[i];
            return dp[i][canBuy]=max(cooldown, buy);
        }
        else{
            int sell=prices[i]+dfs(i+2, true, prices, dp);
            return dp[i][canBuy]=max(sell, cooldown);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return dfs(0, true, prices, dp);
    }
};
