class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> values(boxes.size());
        int ballsLeft = 0, movesLeft = 0;
        int ballsRight = 0, movesRight = 0;
        for (int i = 0; i < boxes.size(); i++) {
            values[i] += movesLeft;
            ballsLeft += boxes[i] - '0';
            movesLeft += ballsLeft;

            int j = boxes.size() - 1 - i;
            values[j] += movesRight;
            ballsRight += boxes[j] - '0';
            movesRight += ballsRight;
        }
        return values;   
    }
};
