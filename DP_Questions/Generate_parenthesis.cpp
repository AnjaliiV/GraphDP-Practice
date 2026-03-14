class Solution {
public:
    void helper(int n,vector<string> &ans,string &temp,int left,int right){
        // Base Case:
        if(left==n && right==n) {
            ans.push_back(temp);
            return;
        }
        // Take left
        if(left<n){
            temp.push_back('(');
            helper(n,ans,temp,left+1,right);
            temp.pop_back();
        }

        // Take right:
        if(left>right){
            temp.push_back(')');
            helper(n,ans,temp,left,right+1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        helper(n,ans,temp,0,0);
        return ans;
    }
};
