class Solution {
private:
    int LCS(const string& text1, const string& text2, int i, int j, vector<vector<int>>& dp){
        if(i==0||j==0) return 0;
        if(dp[i-1][j-1]!=-1) return dp[i-1][j-1];

        if(text1[i-1]==text2[j-1]){
            return dp[i-1][j-1]=1+LCS(text1, text2, i-1, j-1, dp);
        }
        else {
            int l1=LCS(text1, text2, i-1, j, dp);
            int l2=LCS(text1, text2, i, j-1, dp);
            return dp[i-1][j-1]=max(l1, l2);
        }
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int size_text1=text1.length();
        int size_text2=text2.length();
        vector<vector<int>> dp(size_text1, vector<int>(size_text2, -1));
        return LCS(text1, text2, text1.length(), text2.length(), dp);
    }
};
