class Solution {
public:
    int helper(int i, int n, vector<int>& costs, vector<int>& dp){

        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = INT_MAX;

        for(int k = 1; k <= 3; k++){
            if(i + k <= n){
                int next = helper(i + k, n, costs, dp);
                if(next != INT_MAX){
                    ans = min(ans, costs[i+k] + k*k + next);
                }
            }
        }

        return dp[i] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {

        costs.insert(costs.begin(),0);   // make 1-indexed

        vector<int> dp(n+1,-1);

        return helper(0,n,costs,dp);
    }
};
