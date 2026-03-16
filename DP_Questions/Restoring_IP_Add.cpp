class Solution {
public:
    bool isValid(string str){
        if(str[0]=='0') return false;
        int val=stoi(str);
        if(val>255) return false;
        return true;
    }
    void helper(int i,string s,int parts,vector<string> &ans,string temp){
        int n=s.size();
        if(parts>4 || i>n) return;
        if(parts==4 && i==n) {
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        //Taking 1 digits
        helper(i+1,s,parts+1,ans,temp+s.substr(i,1)+'.');

        //Taking 2 digits
        if(i+2<=n && isValid(s.substr(i,2))){
            helper(i+2,s,parts+1,ans,temp+s.substr(i,2)+'.');
        }

        //Taking 3 digits
        if(i+3<=n && isValid(s.substr(i,3))){
            helper(i+3,s,parts+1,ans,temp+s.substr(i,3)+'.');
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string temp="";
        vector<string> ans;
        int n=s.size();
        if(n<4||n>12) return {};
        int parts=0;
        helper(0,s,parts,ans,temp);
        return ans;
        
    }
};
