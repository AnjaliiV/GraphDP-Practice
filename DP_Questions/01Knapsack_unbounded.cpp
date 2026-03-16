class Solution {
  public:
   int helper(vector<int>& val, vector<int>& wt, int capacity,vector<vector<int>> &dp,int n ){
    //   int n=val.size();
       if(n==0 || capacity==0) return 0;
       if(dp[n][capacity]!=-1) return dp[n][capacity];
       
       int take=0;
       if(wt[n-1]<=capacity){
           take=val[n-1]+helper(val,wt,capacity-wt[n-1],dp,n);
       }
        int skip=helper(val,wt,capacity,dp,n-1);
        return dp[n][capacity]=max(take,skip);

   }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        vector<vector<int>> dp(n+1,vector<int>(capacity+1,-1));
        return helper(val,wt,capacity,dp,n);
        
    }
};
