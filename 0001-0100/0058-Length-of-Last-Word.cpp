class Solution {
public:
    int lengthOfLastWord(string s) {
        int ind = s.size()-1;
        int counter = 0;
        while(ind >= 0) {
            if (s[ind] == ' ' && counter != 0) {
                break;
            }
            if (s[ind] != ' ') {
                counter++;
            }
            ind--;
        }
        return counter;
    }
};
