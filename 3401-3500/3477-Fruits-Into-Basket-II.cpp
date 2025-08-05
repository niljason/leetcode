class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count = 0;
        vector<bool> placed(baskets.size(), false);
        for (int i = 0; i < fruits.size(); i++) {
            for (int j = 0; j < placed.size(); j++) {
                if (!placed[j] && fruits[i] <= baskets[j]) {
                    placed[j] = true;
                    count++;
                    break;
                }
            }
        }
        return baskets.size() - count;
    }
};
