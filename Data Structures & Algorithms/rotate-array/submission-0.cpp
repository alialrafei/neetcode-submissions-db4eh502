class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        reverse_part(nums, 0, n - k - 1);
        reverse_part(nums, n - k, n - 1);
        reverse(nums.begin(), nums.end());
    }

private:
    void reverse_part(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};
