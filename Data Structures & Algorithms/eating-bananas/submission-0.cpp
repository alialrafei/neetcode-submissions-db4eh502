class Solution {
public:
    bool CanEatAllBananas(vector<int>& piles, int k, int h) {
        int n = piles.size();
        int idx = 0;
        while(idx < n && h ) {
            int number_of_hours = (piles[idx]+k-1)/k;
            h -= number_of_hours;
            idx++;
        }
        return idx == n && h >= 0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = INT_MAX;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (CanEatAllBananas(piles, mid, h)){
                end = mid;
            }
            else {
                start = mid + 1;
            }
        }
        return start;
    }
};