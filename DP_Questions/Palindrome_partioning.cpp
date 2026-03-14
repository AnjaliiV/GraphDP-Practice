class Solution {
public:
   // checking palindrome:
    bool ispalindrome(string &s,int left,int right){
        while(left<=right){
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    void helper(int index,string &s,vector<string>&curr,vector<vector<string>> &ans){
    // base case
    if(index==s.size()) {
       ans.push_back(curr);
       return;
    }
    for(int i=index;i<s.size();i++){
        if(ispalindrome(s,index,i)){
            curr.push_back(s.substr(index,i-index+1));
            helper(i+1,s,curr,ans);
        // Backtrack to last chosen substring to explore new paths
             curr.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        helper(0,s,curr,ans);
        return ans;
        
    }
};
