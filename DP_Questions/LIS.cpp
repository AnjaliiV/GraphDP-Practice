class Solution {
public:
// RECURSION:
/*int helper(int i,int prev,vector<int> &nums){
    int n=nums.size();
    // Base Case:
    if(i>=n) return 0;

    //Take: only take when prev<ith element
    int take=0;
    if(prev==-1 || nums[prev]<nums[i]){
         take=1+helper(i+1,i,nums);
    }

    //Skip:
    int skip=helper(i+1,prev,nums);

    return max(take,skip);
}*/
// Memoization:
// int n;
// int dp[2501][2502];
// int helper(int i,int prev,vector<int> &nums){

//     // Base Case:
//     if(i>=n) return 0;

//     if(dp[i][prev+1] != -1) {
//         return dp[i][prev+1];
//     }

//     //Take: only take when prev<ith element
//     int take=0;
//     if(prev==-1 || nums[prev]<nums[i]){
//          take=1+helper(i+1,i,nums);
    // }

    //Skip:
    // int skip=helper(i+1,prev,nums);
    
//     return dp[i][prev + 1]=max(take,skip);

// }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // memset(dp, -1, sizeof(dp));
        // return helper(0, -1, nums);
        vector<int> dp(n,1);

        // TABULATION:
        int maxLIS=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                    maxLIS=max(maxLIS,dp[i]);
                }
            }
        }
        return maxLIS;
    }
};
