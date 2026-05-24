class Solution {
public:
    void merge(vector<int>& nums1, int& n, vector<int>& nums2, int& m) {
        int ptr1 = n-1;
        int ptr2 = m-1;
        for (int back = n + m - 1; back >= 0; back--) {
            if (ptr2 < 0)
                break;
            if (ptr1 >= 0 && nums2[ptr2] < nums1[ptr1]) {
                nums1[back] = nums1[ptr1];
                ptr1--;
            } else {
                nums1[back] = nums2[ptr2];
                ptr2--;
            }
            
        }
    }
};