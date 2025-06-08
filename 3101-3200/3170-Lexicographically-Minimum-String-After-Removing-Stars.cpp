class Solution {
public:
    struct compare {
        bool operator()(const pair<char, int>& a, const pair<char, int>&b) {
            if (a.first == b.first) { return a.second < b.second; }
            return a.first > b.first;
        }
    };
    
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, compare> pq;
        string copys = s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                pair<char, int> curr = pq.top();
                pq.pop();
                copys[curr.second] = '*';
            } 
            else {
                pq.push({s[i], i});
            }
        }
        string result = "";
        for (int i = 0; i < copys.size(); i++) {
            if (copys[i] != '*') {
                result += copys[i];
            }
        }
        return result;
    }
};
