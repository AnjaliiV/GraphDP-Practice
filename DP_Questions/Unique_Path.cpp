class Solution {
public:
    // TABULATION:
    int helper(int m,int n){
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }

    // Recursion + Memoization:
    // int helper(int m,int n,vector<vector<int>> &dp){
    //     // Base Case:
    //     if(m==1 || n==1) return 1;
    //     if(dp[m][n]!=-1) return dp[m][n];
    //     return dp[m][n]=helper(m-1,n,dp) + helper(m,n-1,dp);

    // }

    // Recursion:
    // int helper(int i,int j,int m,int n){
    //     // Base Case:
    //     if(i==m-1 && j==n-1){
    //         return 1;
    //     }
    //     // out of bound:
    //     if(i>=m ||j>=n){
    //         return 0;
    //     }
    //     int right=helper(i,j+1,m,n);
    //     int down=helper(i+1,j,m,n);
    //     return right+down;  
    // }

        int uniquePaths(int m, int n) {
        return helper(m,n);
        // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        // return helper(m,n,dp);
        // return helper(0,0,m,n);  
        }
};
