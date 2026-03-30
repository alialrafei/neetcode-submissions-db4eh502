class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
         int n = numbers.size();
        int end = n-1;
        while(end>0){
            for(int i =0;i<end &&(numbers[i]+numbers[end])<=target;i++){
                if(target==(numbers[i]+numbers[end])){
                    return {i+1,end+1};
                }else if((numbers[i]+numbers[end])>target){
                    break;
                }
            }
            end--;
        }
        return {};
    }
};
