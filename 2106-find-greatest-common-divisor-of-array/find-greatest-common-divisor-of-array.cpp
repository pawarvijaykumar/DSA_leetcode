class Solution {
public:
    int findGCD(vector<int>& nums) {
       // int Count=0;
        int smallest=nums[0];
        int largest=nums[0];
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<smallest){
                smallest = nums[i];
            }
            
            if(nums[i]>largest ){
                largest = nums[i];
            }

            
        }
        while(smallest != 0) {
            int rem = largest % smallest;

            largest = smallest;
            smallest = rem;
        }
        return largest;

        
        
    }
};