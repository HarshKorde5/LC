class Solution {
public:

    int res = 0;


    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto& connection : connections){
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }

        dfs(0, -1, adj);
        return res;
    }

    void dfs(int node, int parent, vector<vector<pair<int,int>>>& adj){
        for(auto& [neighbor, sign] : adj[node]){
            if(neighbor != parent){
                res += sign;
                dfs(neighbor, node, adj);
            }
        }

    }
};