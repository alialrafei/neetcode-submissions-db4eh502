class Solution {
private:
    void merge(vector<int>& arr, int left,int mid,int right){
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);

        for(int i = 0 ; i < n1 ; i++)
            L[i] = arr[left+i];
        
        for(int i = 0 ; i < n2 ; i++)
            R[i] = arr[mid+1+i];
        int i  = 0 , j = 0;
        int k = left ;
        while(i < n1 && j < n2){
            if(L[i] > R[j]){
                arr[k] = R[j];
                j++;
            }else{
                arr[k] = L[i];
                i++;
            }
            k++;
        }
        while(i < n1){
            arr[k] = L[i];
            k++;
            i++;
        }
        while(j < n2){
            arr[k] = R[j];
            k++;
            j++;
        }

    }
    void mergeSort(vector<int>& nums, int left,int right){
        if(left>=right)
            return;
        int mid = left + (right-left)/2;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        merge(nums,left,mid,right);
    }
public:
    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};