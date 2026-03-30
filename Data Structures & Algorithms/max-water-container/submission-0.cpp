class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int pstart = 0;
        int pend = n-1;

        int area = 0;
        while(pstart<pend){
            int left = heights[pstart];
            int right = heights[pend];
            area = max(area,min(left,right)*(pend-pstart));
            if(right<left){
                pend--;
            }else{
                pstart++;
            }
        }
        return area;
    }
};
