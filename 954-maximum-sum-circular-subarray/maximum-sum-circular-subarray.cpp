class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0;
        //int circuler;
        int minsum=0;
        int maxi=nums[0];
        int mini=nums[0];
        //int total=maxi+min;
        int total=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            total=total+nums[i];
           
                
            sum=sum+nums[i];
            maxi=max(maxi,sum);
            if(sum<0){
                sum=0;
            }
                
            
            minsum=minsum+nums[i];
            mini=min(mini,minsum);
            if(minsum>0){
                minsum=0;
            }
        }
        if(maxi<0){
            return maxi;
        }
        int circuler=total-mini;

        return max(maxi,circuler); 
    }     
            
};
