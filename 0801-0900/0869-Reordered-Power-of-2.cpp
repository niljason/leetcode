class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> mp = mapDigits(n);
        int m = 1;
        for (int i = 1; i < 32; i++) {
            vector<int> mp2 = mapDigits(m);
            if (equalVec(mp, mp2)) { return true; }
            m = (m << 1);
        }
        return false;
    }

    vector<int> mapDigits(int n) {
        vector<int> mp(10, 0);
        while (n > 0) {
            mp[n%10]++;
            n = n/10;
        }
        return mp;
    }

    bool equalVec(vector<int>& mp1, vector<int>& mp2) {
        for (int i = 0; i < 10; i++) {
            if (mp1[i] != mp2[i]) { return false;}
        }
        return true;
    }
};
