/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int start = 1;
        int end = n;
       
        while(start <= end){
            int current_guess = start + (end-start)/2;
            int current = guess(current_guess);
            if(current == 1){
                start =  current_guess+1;
            }else if(current == -1){
                end = current_guess-1;
            }else{
                return current_guess;
            }
           
            
        }
        return start;
    }
};
