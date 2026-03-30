using namespace std;
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0;
        int r = n-1;
        long long answer = 0;
        while(l<r){
            int h= min(heights[l],heights[r]);
            int w = (r-l);
            long long areaSoFar = 1ll*h*w;
            if(areaSoFar>answer){
                answer = areaSoFar;
            }
            if(heights[l]>=heights[r]){
                r--;
            }else{
                l++;
            }

        }
        return (int) answer;
    }
};
