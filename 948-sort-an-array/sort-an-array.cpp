class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right){
        vector<int> temp; // temporary array for merging
        int i = left, j = mid+1; // i left half ke liye, j right half ke liye

        while(i<=mid && j<=right){
            if(nums[i]<=nums[j]){ // agar left wala chota ya equal hai
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i<=mid){ // left half mein bacha hua daal do
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=right){ // right half mein bacha hua daal do
            temp.push_back(nums[j]);
            j++;
        }

        for(int k=left; k<=right; k++){ // temp ko wapas original array mein copy karo
            nums[k] = temp[k-left];
        }
    }

    void mergeSort(vector<int>& nums, int left, int right){
        if(left>=right) return; // base case: 1 ya 0 element already sorted

        int mid = left + (right-left)/2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};