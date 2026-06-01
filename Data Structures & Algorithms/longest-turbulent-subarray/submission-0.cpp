class Solution {
public:
    int CheckMax(vector<int>& arr, int index, int& n) {
        // up = true down = false
        bool up = index & 1 ? false : true;
        int start = 0;
        int end = 0;
        int window = 1;

        while (end + 1 < n) {
            if (up && arr[end + 1] > arr[end]) {
                end++;
                up = !up;
            } else if (!up && arr[end + 1] < arr[end]) {
                end++;
                up = !up;

            } else {
                if (arr[end + 1] == arr[end]) {
                    start = end + 1;
                } else {
                    start = end;
                }
                end++;
                up = arr[end] < arr[end - 1];
            }
           
            window = max(window, end - start + 1);
        }
   
        return window;
    }
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        return max(CheckMax(arr, 0, n),CheckMax(arr, 1, n));
    }
};