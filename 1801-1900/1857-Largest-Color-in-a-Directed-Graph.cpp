class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(); // constraints make aj and bj btw 0 and n where n is size of colors

        if (edges.size() == 0) { return 1; }

        vector<vector<int>> adjacencyList(n);
        vector<int> inDegree(n);

        // for each edge calculate the indegree and make adjacency list
        for (vector<int>& edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }

        vector<vector<int>> dp(n, vector<int>(26, 0));
        queue<int> q;

        // for each node if indegree is 0 add to queue
        // each node also has a max of 1 of its color
        // there's 26 possible colors
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) { q.push(i); }
            dp[i][colors[i] - 'a'] = 1;
        }

        vector<int> result;
        int value = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (int it : adjacencyList[node]) {
                for (int color = 0; color < 26; color++) {
                    // if same color
                    int add = (colors[it] - 'a' == color) ? 1 : 0;
                    dp[it][color] = max(dp[it][color], dp[node][color] + add);
                    value = max(value, dp[it][color]);
                }
                inDegree[it]--;
                if (inDegree[it] == 0) { q.push(it); }
            }
        }

        if (result.size() != n) {
            return -1; // detects cycle
        }
        return value;
    }


};
