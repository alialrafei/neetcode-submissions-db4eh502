class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int back = n-1;
        int front = 0;
        while(front < back){
            swap(s[front],s[back]);
            front++;
            back--;
        }
        
    }
};