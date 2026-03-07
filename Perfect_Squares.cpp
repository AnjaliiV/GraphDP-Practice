class Solution {
public:
    int numSquares(int n) {
        vector<bool> visited(n+1,0);
        queue<int> q;
        int st=n;
        int count=0;
        visited[st]=1;
        q.push(n);

        while(!q.empty()){
            int sz=q.size();
            count++;
            while(sz--){
               int node=q.front();
               q.pop();

               for(int i=1;i*i<=node;i++){
                int neigh=node-i*i;

                if(neigh==0) return count;

                if(!visited[neigh]){
                    visited[neigh]=1;
                    q.push(neigh);
                }
               }
            }
        }
        return count;
    }
};