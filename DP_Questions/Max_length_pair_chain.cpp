class Solution {
public:
// RECURSION + MEMOIZATION:
    /*int helper(int i,int prev,vector<vector<int>> &pairs,vector<vector<int>> &dp){
        // Base Case:
        if(i==pairs.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        // take element to make pairs:
        int take=0;
        if(prev==-1 || pairs[i][0]>pairs[prev][1]){
                take=1+helper(i+1,i,pairs,dp);
        }
        // skip elements
        int skip=helper(i+1,prev,pairs,dp);
        return dp[i][prev+1]= max(take,skip);
    }*/
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end()); //You can select pairs in any order.
        // vector<vector<int>> dp(pairs.size(),vector<int>(pairs.size(),-1));
        // return helper(0,-1,pairs,dp);
        vector<int> dp(pairs.size(),1);
        int max_pairs=1;
        for(int i=0;i<pairs.size();i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i]=max(dp[i],dp[j]+1);
                     max_pairs=max(max_pairs,dp[i]);
                }
            }
        }
        return max_pairs;
    }
};
