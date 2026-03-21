class Solution {
public:
    int ans=INT_MAX;
    void dfs(int st,vector<vector<pair<int,int>>> &adj,vector<bool> &visited){
        visited[st]=1;
        for(auto &p:adj[st]){
            int neigh=p.first;
            int cost=p.second;
            ans=min(ans,cost);
            if(!visited[neigh])
            dfs(neigh,adj,visited);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<bool> visited(n+1,0);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int w=roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        dfs(1,adj,visited);
        return ans;

    }
};
