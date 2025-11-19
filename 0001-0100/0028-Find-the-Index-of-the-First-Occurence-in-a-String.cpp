class Solution {
public:
    int strStr(string haystack, string needle) {
        int start = 0;
        int pt = 0;
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[pt]) {
                pt++;
                if (pt == needle.size()) { return i - pt + 1; }
            }
            else {
                i = start;
                start++;
                pt = 0;
            }
        }
        return -1;
    }
};
