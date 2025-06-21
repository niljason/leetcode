class Solution {
public:
    int maxDistance(string s, int k) {
        int maxDist = 0;
        vector<int> freq(4,0);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'N') freq[0]++;
            if (s[i] == 'S') freq[1]++;
            if (s[i] == 'W') freq[2]++;
            if (s[i] == 'E') freq[3]++;
            maxDist = max(maxDist, getMaxDist(freq, k));
        }
        return maxDist;
    }

    int getMaxDist(vector<int>& freq, int k) {
        int bestDist = 0;
        int minY = min(freq[0], freq[1]);
        int minX = min(freq[2], freq[3]);
        int maxX = max(freq[2], freq[3]);
        int maxY = max(freq[0], freq[1]);
        if (k >= minX+minY) {
            bestDist = maxX + maxY + minX + minY;
            return bestDist;
        } 
        else {
            int unflipped = minX+minY - k;
            bestDist = maxX + maxY + k - unflipped;
            return bestDist;
        }
        return -1;
    }
};
