class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int x1 = 0;
        int x2 = 0;
        int total_size = nums1.size() + nums2.size();
        int k = (total_size + 1)/2;
        bool start = true;

        /*
            log (m+n) time complexity solution
            similar to kth order statistic problem which has complexity nlogn due to swapping around pivots
            since the arrays are sorted this removes the n factor
        */
        while(k != 1) {
            start = false;
            int mid = k/2; // chop at most half of k
            int y1 = min(x1 + mid, int(nums1.size())); // bound check to make sure we do not exceed the size
            int y2 = min(x2 + mid, int(nums2.size()));

            // cout << "x1:" << x1 << "\ty1:" << y1 << "\tx2:" << x2 << "\ty2:" << y2 << "\tk:" << k << endl; 

            // if one array is finished e.g. [1..n] [n+1...4n] chop the other array
            if (x1 == y1 && nums2.size() != 0) {
                k = k - (y2-x2);
                x2 = y2;
            }
            else if (x2 == y2 && nums1.size() != 0) {
                k = k - (y1-x1);
                x1 = y1;
            }
            // chop whichever side is smaller
            else if (nums1[y1-1] < nums2[y2-1]) {
                // cout << nums1[y1-1] << " " << nums2[y2-1] << endl;
                k = k - (y1-x1);
                x1 = y1;
            }
            else {
                // cout << nums1[y1-1] << " " << nums2[y2-1] << endl;
                k = k - (y2-x2);
                x2 = y2;
            }
        }
        // cout << "x1:" << x1 << "\tx2:" << x2 << "\tk:" << k << endl; 

        // even so take average
        if (total_size % 2 == 0) {
            // first array depleted so in second
            if (x1 == nums1.size()) {
                return double(nums2[x2] + nums2[x2+1]) / 2;
            }
            if (x2 == nums2.size()) {
                return double(nums1[x1] + nums1[x1+1]) / 2;
            }
            // edge case for [a], [b]
            if (x1 + 1 == nums1.size() && x2 + 1 == nums2.size()) {
                return double(nums1[x1] + nums2[x2])/2;
            }
            // edge cases for [a, b] [c, d] where b < c
            if (x1 + 1 == nums1.size()) {
                return min(double(nums1[x1] + nums2[x2])/2, double(nums2[x2] + nums2[x2+1])/2 );
            }
            if (x2 + 1 == nums2.size()) {
                return min(double(nums1[x1] + nums2[x2])/2, double(nums1[x1] + nums1[x1+1])/2 );
            }
            // last case where the median can be any combination of values
            else {
                double a = nums1[x1] + nums2[x2];
                double b = nums1[x1] + nums1[x1+1];
                double c = nums2[x2] + nums2[x2+1];
                double res = min(a/2, b/2);
                return min(res, c/2);
            }
        }
        else {
            // depleted first array
            if (x1 == nums1.size()) {
                return nums2[x2];
            }
            // depleted second array
            if (x2 == nums2.size()) {
                return nums1[x1];
            }
            // both arrays exist return min
            return min(nums1[x1], nums2[x2]);
        }

    }
};
