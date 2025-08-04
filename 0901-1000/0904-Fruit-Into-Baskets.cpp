class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int fruitA = -1;
        int fruitB = -1;
        int maxFruit = 0;
        int count = 0;
        vector<int> mp(fruits.size(), -1);
        for (int i = 0; i < fruits.size(); i++) {
            mp[fruits[i]] = i; // map fruit to last index it appeared
            if (fruitA < 0) { fruitA = fruits[i];} // set fruitA
            if (fruitB < 0 && fruitA != fruits[i]) { fruitB = fruits[i]; } // set fruitB
            if (fruits[i] == fruitA || fruits[i] == fruitB) { count++; }
            else {
                if (mp[fruitA] < mp[fruitB]) {
                    count = i - mp[fruitA];
                    fruitA = fruits[i];
                }
                else {
                    count = i - mp[fruitB];
                    fruitB = fruits[i];
                }
            }
            maxFruit = max(maxFruit, count);
        }
        return maxFruit;

    }
};
