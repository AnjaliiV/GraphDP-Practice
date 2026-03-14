class Solution {
public:
    int helper(int ind1,int ind2,string &text1,string &text2,vector<vector<int>> &dp){
        // Base Case:
        if(ind1==text1.length() || ind2==text2.length()) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(text1[ind1]==text2[ind2]){
            return 1+helper(ind1+1,ind2+1,text1,text2,dp);
        }
        int skip1=helper(ind1+1,ind2,text1,text2,dp);
        int skip2=helper(ind1,ind2+1,text1,text2,dp);
        return dp[ind1][ind2]=max(skip1,skip2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(),vector<int>(text2.length(),-1));
        return helper(0,0,text1,text2,dp);
        
    }
};
