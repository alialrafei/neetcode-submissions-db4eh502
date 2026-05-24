class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int start_1 = 0;
        int end_1 = n - 1;
        int start_2 = 0;
        int end_2 = m - 1;
        string merged_string;
        while (start_1 <= end_1 && start_2 <= end_2) {
            merged_string += word1[start_1];
            merged_string += word2[start_2];
            start_1++;
            start_2++;
        }
        while (start_1 <= end_1) {
            merged_string += word1[start_1];
            start_1++;
        }
        while (start_2 <= end_2) {
            merged_string += word2[start_2];
            start_2++;
        }
        return merged_string;
    }
};