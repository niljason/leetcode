class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) { return a[1] < b[1]; }
            return a[0] < b[0];
        });

        priority_queue<int, vector<int>, greater<int>> pq;

        int currDay = 0;
        int maxDay = 0;
        for (auto& event: events) maxDay = max(maxDay, event[1]);
        int count = 0;
        int i = 0;

        for (int day = 1; day <= maxDay; ++day) {
            // event today
            while (i < events.size() && events[i][0] == day) {
                pq.push(events[i][1]);
                ++i;
            }

            // past event
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            if (!pq.empty()) {
                pq.pop();
                ++count;
            }
        }
        return count;
    }
};
