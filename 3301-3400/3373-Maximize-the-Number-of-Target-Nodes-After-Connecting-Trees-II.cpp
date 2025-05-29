class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        vector<vector<int>> adjList1(n, vector<int>());
        vector<vector<int>> adjList2(m, vector<int>());

        for (const auto& edge : edges1) {
            int u = edge[0], v = edge[1];
            adjList1[u].push_back(v);
            adjList1[v].push_back(u);
        }

        for (const auto& edge : edges2) {
            int u = edge[0], v = edge[1];
            adjList2[u].push_back(v);
            adjList2[v].push_back(u);
        }
        
        vector<int> color1(n, -1);
        vector<int> color2(m, -1);

        vector<int> nodes1 = BFS(adjList1, 0, color1);
        vector<int> nodes2 = BFS(adjList2, 1, color2);

        vector<int> result(n, 0);
        for (int i = 0; i < n; i++) {
            result[i] = nodes1[color1[i]] + max(nodes2[0], nodes2[1]);
        }
        return result;
    }

    vector<int> BFS(const vector<vector<int>>& adjList, int k, vector<int>& color) {
        int n = adjList.size();
        vector<bool> visited(n);

        int node = 0;
        queue<int> q;
        fill(visited.begin(), visited.end(), false);
        visited[node] = true;

        color[node] = 0; // color odd or even
        
        int count = 0; // set count = 0
        if (k == 0) { count++; }
        q.push(node);

        // run BFS once
        // for level steps away
        for (int level = 1; level <= n; level++) {
            if (q.empty()) { break; }
            int c = q.size(); // current size of q
            // for this many elements of queue at the jth level
            for (int u = 0; u < c; u++) {
                int edge1 = q.front();
                q.pop();
                // v of (u,v)
                for (int v : adjList[edge1]) {
                    if (!visited[v]) { // element not yet visited
                        q.push(v); 
                        visited[v] = true;
                        if (level % 2 == k) { count++; }
                        color[v] = level % 2;
                    }
                }
            }
        }
        // even odd
        return {count, n-count};
    }
};
