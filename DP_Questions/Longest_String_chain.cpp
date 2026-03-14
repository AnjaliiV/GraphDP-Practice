class Solution {
public:
int dp[1001][1001];

bool isPredecessor(string &a, string &b) {
    if (b.size() != a.size() + 1) return false;

    int i = 0, j = 0;
    while (j < b.size()) {
        if (i < a.size() && a[i] == b[j]) i++;
        j++;
    }
    return i == a.size();
}

static bool comparator(string &a, string &b) {
    return a.size() < b.size();
}

// int helper(int curr, int prev, vector<string>& words) {
//     if (curr == words.size()) return 0;

//     if (prev != -1 && dp[curr][prev] != -1)
//         return dp[curr][prev];

//     int take = 0;

//     if (prev == -1 || isPredecessor(words[prev], words[curr])) {
//         take = 1 + helper(curr + 1, curr, words);
//     }

//     int skip = helper(curr + 1, prev, words);

//     if (prev != -1)
//         dp[curr][prev] = max(take, skip);

//     return max(take, skip);
// }

int longestStrChain(vector<string>& words) {
    int n=words.size();
    sort(words.begin(), words.end(), comparator);
    // memset(dp, -1, sizeof(dp));
    // return helper(0, -1, words);
    // Tabulation:
    vector<int> dp(n,1);
    int maxL=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(isPredecessor(words[j],words[i])){
                dp[i]=max(dp[i],dp[j]+1);
                maxL=max(maxL,dp[i]);
            }
        }
    }
    return maxL;
}
};
