class Solution {
  public:
  int helper(int W, vector<int> &val, vector<int> &wt,vector<vector<int>> &dp,int n){
        if(W==0 || n==0){
            return 0;
        }
        if (dp[n][W]!=-1) return dp[n][W];
        
        //Skip
        int notTake=helper(W,val,wt,dp,n-1);
        
        //Take:
        int take=0;
        if(wt[n-1]<=W){
            take=val[n-1]+helper(W-wt[n-1],val,wt,dp,n-1);
        }
        return dp[n][W]=max(take,notTake);
  }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
        return helper(W,val,wt,dp,n);
    }
};
