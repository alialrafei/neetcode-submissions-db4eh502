class Solution {
public:
    bool validPalindrome(string& s) {
        int front = 0;
        int back = s.size()-1;
        int n = s.size();
        while(front<back){
            if(s[front]!=s[back]){
                //option 1 : check remove the front 
                //option 2 : check remove the back
                return CheckValidation(s,front+1,back) || CheckValidation(s,front,back-1);   
            }
            front++;
            back--;
            
           
        }
       
        return true;
    }
private:
    bool CheckValidation(string& s, int front,int back){
        while(front < back){
            if(s[front] != s[back]){
                return false;
            }
            front++;
            back--;
        }
        return true;
    }
};

