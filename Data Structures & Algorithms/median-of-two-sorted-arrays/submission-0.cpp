class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int msize = (size1 + size2) / 2;

        int l1 = 0, l2 = 0;
        bool toggle = false; // true if nums1 supplied the last value

        if ((size1 + size2) % 2 == 0) {
            int x = 0;

            // Consume the first middle value.
            while (l1 + l2 < msize) {
                if (l1 == size1) {
                    toggle = false;
                    l2++;
                } else if (l2 == size2) {
                    toggle = true;
                    l1++;
                } else if (nums1[l1] < nums2[l2]) {
                    toggle = true;
                    l1++;
                } else {
                    toggle = false;
                    l2++;
                }

                x = toggle ? nums1[l1 - 1] : nums2[l2 - 1];
            }

            // Consume the second middle value.
            if (l1 == size1) {
                toggle = false;
                l2++;
            } else if (l2 == size2) {
                toggle = true;
                l1++;
            } else if (nums1[l1] < nums2[l2]) {
                toggle = true;
                l1++;
            } else {
                toggle = false;
                l2++;
            }

            int y = toggle ? nums1[l1 - 1] : nums2[l2 - 1];
            return (static_cast<double>(x) + y) / 2.0;
        }

        // Consume through the middle value.
        while (l1 + l2 <= msize) {
            if (l1 == size1) {
                toggle = false;
                l2++;
            } else if (l2 == size2) {
                toggle = true;
                l1++;
            } else if (nums1[l1] < nums2[l2]) {
                toggle = true;
                l1++;
            } else {
                toggle = false;
                l2++;
            }
        }

        return toggle ? nums1[l1 - 1] : nums2[l2 - 1];
    }
};