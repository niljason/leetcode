class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> time1 = BFS(node1, edges);
        vector<int> time2 = BFS(node2, edges);
        int resultNode = -1;
        int minDist = edges.size();
        for (int i = 0; i < time1.size(); i++) {
            if (time1[i] != -1 && time2[i] != -1) {
                int currMax = max(time1[i], time2[i]);
                if (currMax < minDist) {
                    minDist = currMax;
                    resultNode = i;
                }
            }
        }
        return resultNode;        
    }

    vector<int> BFS(int node, vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false);
        vector<int> visitTime(n, -1);
        queue<int> q;
        q.push(node);
        int level = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visited[curr] = true;
            visitTime[curr] = level;
            if (edges[curr] != -1 && !visited[edges[curr]]) {
                q.push(edges[curr]);
            }
            level++;
        }
        return visitTime;
    }
};
