class Solution {
public:
    int helper(int i,int end,vector<int>& nums,vector<int> &dp){
        // int n=nums.size();
        if(i>end) return 0;
        if(dp[i]!=-1) return dp[i];
        int steal=helper(i+2,end,nums,dp)+nums[i];
        int skip=helper(i+1,end,nums,dp);
        return dp[i]=max(skip,steal);
    }
    int solve(vector<int> &nums,int st,int end){
        int n=nums.size();
        vector<int> dp(n,-1);
        return helper(st,end,nums,dp);

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        if(n==1) return nums[0];
        int include1=solve(nums,0,n-2);
        int include2=solve(nums,1,n-1);
        return max(include1,include2);
        
    }
};
