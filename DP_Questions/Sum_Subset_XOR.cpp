class Solution {
public:
    int helper(int i,vector<int>& nums,int XOR){
        if(i==nums.size()) return XOR;
        int take=helper(i+1,nums,nums[i]^XOR);
        int notTake=helper(i+1,nums,XOR);
        return take+notTake;
    }
    int subsetXORSum(vector<int>& nums) {
        return helper(0,nums,0);
        
    }
};
