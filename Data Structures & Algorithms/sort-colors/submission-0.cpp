class Solution {
public:
    void merge(int l, int r , int mid , vector<int> &arr){
        int n1 = mid-l+1;
        int n2 = r - mid;
        vector<int> left(n1),right(n2);
        for(int i =0; i < n1;i++){
            left[i] = arr[l+i];
        }
        for(int i =0; i < n2;i++){
            right[i] = arr[mid+i+1];
        }
        int k = l;
        int i = 0 , j = 0;
        while(i < n1 && j < n2){
            if(left[i] > right[j]){
                arr[k] = right[j];
                j++;
            }else{ 
                 arr[k] = left[i];
                 i++;
            }
            k++;
        }
        while(i<n1){
            arr[k] = left[i];
            k++;
            i++;
        }
        while(j<n2){
            arr[k] = right[j];
            k++;
            j++;
        }

    }
    void mergeSort(int left,int right,vector<int> &nums){
        if(left>=right)
            return ;
        int mid = left + (right-left)/2;
        mergeSort(left,mid,nums);
        mergeSort(mid+1,right,nums);
        merge(left,right,mid,nums);
    }
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        mergeSort(0,n-1,nums);
        
    }
};