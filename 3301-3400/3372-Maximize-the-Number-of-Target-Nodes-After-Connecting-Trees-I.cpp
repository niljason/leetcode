class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        if (k == 0) { return vector<int>(n,1); }
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
        vector<int> nodes1 = BFS(adjList1, k);
        vector<int> nodes2 = BFS(adjList2, k-1);

        int maxNode = *max_element(nodes2.begin(), nodes2.end());
        vector<int> result(n, 0);
        for (int i = 0; i < n; i++) {
            result[i] = maxNode + nodes1[i];
        }
        return result;
    }

    vector<int> BFS(vector<vector<int>>& adjList, int k) {
        int n = adjList.size();
        vector<int> result(n, 0);
        vector<bool> visited(n);
        // for each node
        for (int node = 0; node < n; node++) {
            queue<int> q;
            fill(visited.begin(), visited.end(), false);
            visited[node] = true;
            int count = 1;
            q.push(node);
            // for k steps away
            for (int level = 0; level < k; level++) {
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
                            count++;
                        }
                    }
                }
            }
            result[node] = count;
        }
        return result;
    }
};
