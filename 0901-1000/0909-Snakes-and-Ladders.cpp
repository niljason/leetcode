class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int goal = n * n;
        vector<bool> visited(goal, false);
        queue<pair<int,int>> q;
        q.push({1,0});
        while (!q.empty()) {
            int square = q.front().first;
            int move = q.front().second;
            if (square >= goal) { return move; }
            q.pop();
            for (int i = 1; i <= 6; i++) {
                int newSquare = square+i;
                if (newSquare >= goal) { newSquare = goal; }
                int section = ((newSquare-1) % (2*n)) >= n ? 1 : 0; 
                int boardPosX = (n-1) - ((newSquare-1) / n);
                int boardPosY = (newSquare-1) % n;
                if (section) { boardPosY = (n-1)-boardPosY; }
                // if snake or ladder
                if (board[boardPosX][boardPosY] != -1) {
                    newSquare = board[boardPosX][boardPosY];
                }
                if (!visited[newSquare-1]) {
                    q.push({newSquare, move+1});
                    visited[newSquare-1] = true;
                }
            }
        }
        return -1;
    }
};
