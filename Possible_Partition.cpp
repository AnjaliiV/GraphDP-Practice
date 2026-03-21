class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto &e:dislikes){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> color(n+1,-1);
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
            color[i]=0;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(int neigh:adj[node]){
                    if(color[neigh]==-1){
                        color[neigh]=1-color[node];
                        q.push(neigh);
                    }
                    else if(color[neigh]==color[node]) return false;
        
                }
            }
        }
    }
        return true;
        
    }
};
