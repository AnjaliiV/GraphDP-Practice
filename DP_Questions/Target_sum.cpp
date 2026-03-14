class Solution {
public:
// RECURSION + MEMOIZATION
    int S;
    int helper(int i,int sum,int target,vector<int> &nums,vector<vector<int>> &dp){
        // Base Case:
        if(i==nums.size()) {
            if(sum==target) return 1; //we found 1 way
            else return 0;
        }
        if(dp[i][sum+S] != -1) return dp[i][sum+S];
        int take=helper(i+1,sum+nums[i],target,nums,dp);
        int skip=helper(i+1,sum-nums[i],target,nums,dp);
        return dp[i][sum+S]=take+skip;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
         S=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(nums.size()+1,vector<int>(2*S+1,-1));
        return helper(0,0,target,nums,dp);
    }
};
